tsp_fnc_melee_can = {_this getVariable ["ace_captives_isSurrendering", false] == false && _this getVariable ["ace_captives_handcuffAnimEHID", -1] == -1 && stance _this in ["STAND", "CROUCH"] && speed _this < tsp_cba_melee_speed &&	vehicle _this == _this && ("amov" in animationState _this || "melee" in animationState _this)};
tsp_fnc_melee_doing = {_this getVariable ["tsp_melee_doing", false] || "melee" in gestureState _this || "melee" in animationState _this};

tsp_fnc_melee_weapon = {  //-- Returns weapon's meleeType, "" if none
    params ["_unit", ["_weapon", currentWeapon (_this#0)]]; [primaryWeaponItems _unit select {getText (configFile >> "CfgWeapons" >> _x >> "meleeType") != ""}] params ["_attachments"];
    if (_weapon == primaryWeapon _unit && count _attachments > 0) exitWith {getText (configFile >> "CfgWeapons" >> _attachments#0 >> "meleeType")};  //-- Bayonets
    if (_weapon in ["", "Throw"]) then {"fist"} else {getText (configFile >> "CfgWeapons" >> _weapon >> "meleeType")};
};

tsp_fnc_melee_config = {  //-- Get list of variants of certain mode from CfgMelee of meleeType (cfgMelee >> rifle >> main >> variant)
    params ["_meleeType", "_mode", ["_variants", []]];
	{
		_variants pushBack [  //-- Push back attributes from one variant to _variants
			getText   (_x >> "animation"), 
			getText   (_x >> "gesture"),	
			getNumber (_x >> "angle"), 
			getNumber (_x >> "reach"), 
			getNumber (_x >> "stamina"),	
			getArray  (_x >> "swingSound"),
			getNumber (_x >> "swingTime"),	
			getNumber (_x >> "impactTime"),	
			getNumber (_x >> "afterTime"),	
			getNumber (_x >> "restTime"),	
			getNumber (_x >> "manDamage"),	
			getText   (_x >> "manDamageType"),	
			getText   (_x >> "manProjectile"),	
			getText   (_x >> "manEffect"),	
			getArray  (_x >> "manSound"),	
			getNumber (_x >> "manKnockoutChance"),	
			getArray  (_x >> "manKnockoutSound"),	
			getNumber (_x >> "manStunChance"),	
			getNumber (_x >> "manDisarmChance"),	
			getArray  (_x >> "blockableDamage"),
			getText   (_x >> "objectProjectile"),	
			getArray  (_x >> "objectSound"),	
			getArray  (_x >> "environmentDamage"),
			getText   (_x >> "condition"),	
			getText   (_x >> "code")
		];
	} forEach configProperties [configFile >> "CfgMelee" >> _meleeType >> _mode, "true", true];
	_variants
};

tsp_fnc_melee_action = {  //-- Ready, main, alt, block, kick, special, dodgeleft, dodgeright
	params ["_unit", "_mode"]; [[[_unit] call tsp_fnc_melee_weapon, _mode] call tsp_fnc_melee_config] params ["_variants"]; 
	if (count _variants > 1) then {_variants = _variants select {_x#1 != _unit getVariable ["previousAnim", "BRUH"]}};  //-- Don't repeat same animations if possible
	(selectRandom _variants) params [  //-- Pick random variant and get parameters
		"_animation", "_gesture",
		"_angle", "_reach", "_stamina",
		"_swingSound", "_swingTime", "_impactTime", "_afterTime", "_restTime",
		"_manDamage", "_manDamageType", "_manProjectile", "_manEffect", "_manSound", "_manKnockoutChance", "_manKnockoutSound", "_manStunChance", "_manDisarmChance", 
		"_blockableDamage",
		"_objectProjectile", "_objectSound", "_environmentDamage",
		"_condition", "_code"
	];
		
	if !(_unit getVariable ["meleeEH", false]) then {
		_unit addEventHandler ["AnimDone", {if (_this#0 call tsp_fnc_melee_doing && !(_this#0 call tsp_fnc_melee_can)) then {[_this#0] call tsp_fnc_gesture_stop}}];
		_unit addEventHandler ["GestureChanged", {if (_this#0 call tsp_fnc_melee_doing && !(_this#0 call tsp_fnc_melee_can)) then {[_this#0] call tsp_fnc_gesture_stop}}];
		_unit setVariable ["meleeEH", true, true];
	};

	if (!(_mode in ["ready", "block"]) && _unit getVariable ["tsp_melee_doing", false]) exitWith {};  //-- No overwriting current melee action unless switching back to ready
	_victims = [_unit, eyePos _unit, [0,_angle/6,_angle/3,_angle/2,_angle/1.5,_angle/1.2,-(_angle/6),-(_angle/3),-(_angle/2),-(_angle/1.5),-(_angle/1.2)], _reach, getCameraViewDirection _unit] call tsp_fnc_obstruction select {_x#0 isKindOf "Man" && [_unit, _x#0] call compile _condition};
	if (_mode == "special") exitWith {if (count _victims > 0) then {[_unit, _victims#0#0] call compile _code}};
	if (_animation != "") then {[_unit, _animation] remoteExec ["playMoveNow", 0]};
	if (_gesture != "") then {[_unit, "", _gesture, "tsp_common_stop", true, true] spawn tsp_fnc_gesture_play}; 
	if (_mode == "ready") exitWith {};  //unit,in,loop,out,interupt,instant,return,returnable,toggle,lower,code
	if (_mode == "block") exitWith {_unit setVariable ["blocking", _blockableDamage, true]; waitUntil {sleep 0.1; gestureState _unit != _gesture}; _unit setVariable ["blocking", [], true]};
 	_unit setVariable ["tsp_melee_doing", true]; _unit setVariable ["previousAnim", _gesture];
	sleep _swingTime; (selectRandom _swingSound) params ["_sound", "_volume"]; playSound3D [_sound, _unit, false, getPosASL _unit, 3*_volume, 1, 20*_volume];
	if ("dodge" in _mode) exitWith {sleep 0.3; _unit setVariable ["tsp_melee_doing", false]; [_unit, "ready"] spawn tsp_fnc_melee_action};
	
	sleep _impactTime;

	//-- Impact
	if (!isNil "tsp_fnc_breach_melee") then {[_unit, _environmentDamage] spawn tsp_fnc_breach_melee};
	_victims = [_unit, eyePos _unit, [0,_angle/6,_angle/3,_angle/2,_angle/1.5,_angle/1.2,-(_angle/6),-(_angle/3),-(_angle/2),-(_angle/1.5),-(_angle/1.2)], _reach, getCameraViewDirection _unit] call tsp_fnc_obstruction select {_x#0 isKindOf "Man"};
	_objects = [_unit, eyePos _unit, [0,5,10,-5,-10], _reach, getCameraViewDirection _unit] call tsp_fnc_obstruction select {!(_x#0 isKindOf "Man")};
	if (count _victims > 0) then {
		(_victims#0) params ["_victim", "_intersect", "_selections", ["_knockout", false]];
		if (count (_victim getVariable ["blocking", []]) > 0) then {
			{  //-- Search victim's blocking data to see if he is able to block damage, if something found, then reduce damage
				_x params ["_blockDamageType", "_blockDamageAmount", "_blockSound"];
				if (_manDamageType == _blockDamageType) exitWith {_manDamage = _manDamage * _blockDamageAmount; _manSound = _blockSound};
			} forEach (_victim getVariable "blocking");
		} else {_manProjectile createVehicle ASLtoATL _intersect setVelocity (getCameraViewDirection _unit vectorMultiply 20)};
		if (_manKnockoutChance != 1 && ([headgear _victim] call tsp_fnc_hitpoint_armor) > 5) then {_manKnockoutChance = _manKnockoutChance - 0.25};                                       //-- Knockout helmet
		if (random 1 <= _manKnockoutChance && {_x in ["neck", "head"]} count _selections > 0) then {_knockout = true};                                                                   //-- Knockout chance
		if (random 1 <= _manStunChance) then {[_victim, _manDisarmChance] remoteExec ["tsp_fnc_melee_stun", _victim]};                                                                  //-- Stun
		if (_knockout) then {selectRandom _manKnockoutSound params ["_sound", "_volume"]; playSound3D [_sound, vehicle _victim, false, getPosASL _victim, 3*_volume, 1, 20*_volume]};  //-- Sound		
		selectRandom _manSound params ["_sound", "_volume"]; playSound3D [_sound, vehicle _victim, false, getPosASL _victim, 3*_volume, 1, 20*_volume];                               //-- Sound
		[_victim, _selections#0, _manDamage*tsp_cba_melee_damage, _manDamageType, _knockout] remoteExec ["tsp_fnc_hitpoint_damage", _victim];                                        //-- Damage
		["tsp_melee_damageMan", [_unit, _victim]] call CBA_fnc_localEvent;                                                                                                          //-- CBA Event
		if (!alive _victim) then {[_unit, [1, 0, 0, 0, 0]] remoteExec ["addPlayerScores", 2]};                                                                                     //-- Score
		if !(([_victim] call tsp_fnc_melee_weapon) in ["rifle", "pistol"]) then {[_victim] remoteExec ["tsp_fnc_melee_ai", _victim]};                                             //-- AI behaviour
	} else {if (count _objects > 0) then {
		_adjust = (_objects#0#1) vectorAdd (([_unit, getCameraViewDirection _unit, 180] call tsp_fnc_vector) vectorMultiply 0.1);
		_objectProjectile createVehicle ASLtoATL _adjust setVelocity (getCameraViewDirection _unit vectorMultiply 20);
	}};

	//-- Rest
	sleep _restTime; 
	_unit setStamina (getStamina _unit - (_stamina*tsp_cba_melee_stamina));
	[_unit, if (inputAction "MoveBack" > 0) then {"block"} else {"ready"}] spawn tsp_fnc_melee_action;
	sleep (_afterTime + ((60-getStamina _unit)/300));
	_unit setVariable ["tsp_melee_doing", false];	
};

tsp_fnc_melee_stun = {  //-- Stun lock
	params ["_unit", ["_manDisarmChance", 0]]; if ("stun" in animationState _unit || stance _unit != "STAND") exitWith {};
	_anim = switch (currentWeapon _unit) do {case "": {"tsp_melee_fistStun"}; case primaryWeapon _unit: {"tsp_melee_rifleStun"}; case handgunWeapon _unit: {"tsp_melee_pistolStun"}};
	[_unit] call tsp_fnc_gesture_stop; [_unit, _anim] remoteExec ["playMoveNow", 0]; 
	if (random 1 < (_manDisarmChance*tsp_cba_melee_disarm) && ([_unit] call tsp_fnc_melee_weapon) in ["rifle", "pistol"]) then {sleep 0.2; [_unit, currentWeapon _unit] call tsp_fnc_throw};
};

tsp_fnc_melee_takedown = {  //-- Used for takedown animations
	params ["_unit", "_victim", "_unitAnim", "_victimAnim", ["_dieTime", 1], ["_sound", ""]];
	_unit setVariable ["tsp_melee_doing", true];
	{_victim disableAI _x} forEach ["ANIM", "MOVE"];
	{_x playAction "tsp_common_stop"} forEach [_unit, _victim];
	[_unit, _unitAnim] remoteExec ["playMoveNow", 0]; waitUntil {animationState _unit == _unitAnim};
	_victim attachTo [_unit, [0,0,0]]; [_victim, _victimAnim] remoteExec ["switchMove", 0];
	{[_victim, _x] call tsp_fnc_throw} forEach [primaryWeapon _victim, handgunWeapon _victim];
	playSound3D [_sound, _victim, false, getPosASL _victim, 4, 1, 10]; sleep _dieTime; _victim setDamage 1; 
	[_unit, "ready"] spawn tsp_fnc_melee_action; _unit setVariable ["tsp_melee_doing", false];
	sleep 0.1; detach _victim;
};

tsp_fnc_melee_bayonet = {  //-- Swap bayonet attachment/item
	params ["_unit", "_old", "_new"];
	if (_unit canAdd _new) then {_unit addItem _new} else {createVehicle ["GroundWeaponHolder", getPosATL _unit, [], 0, "CAN_COLLIDE"] addItemCargoGlobal [_new, 1]};  //-- Add new
	if (_old in (primaryWeaponItems _unit)) exitWith {_unit action ["GEAR", null]; _unit removePrimaryWeaponItem _old};  //-- Remove bayonet
	if (handgunWeapon _unit == _old) exitWith {_unit removeWeapon _old; _unit action ["GEAR", null]}; //-- Remove handgun
	if (_old in (items _unit)) exitWith {_unit removeItem _old; _unit action ["GEAR", null]};  //-- Remove item
};

tsp_fnc_melee_ai = {
	params ["_unit", ["_radius", 100], ["_actionChance", 0.75], ["_blockChance", 0.75], ["_reach", 2]];
	if (isPlayer _unit || _unit getVariable ["AIMELEE", false]) exitWith {}; _unit setVariable ["AIMELEE", true, true];
	_unit setUnitPos "UP";
	while {sleep 0.5; alive _unit} do {
		_enemies = (_unit nearEntities [["CAManBase"], _radius]) select {_x != _unit && _unit knowsAbout _x > 0 && !([side _x, side _unit] call BIS_fnc_sideIsFriendly)};
		if (_unit getVariable ["ACE_isUnconscious", false] || stance _unit != "STAND" || count _enemies == 0) then {[_unit] call tsp_fnc_gesture_stop; continue};
		_enemies = _enemies apply {_distance = _x distance _unit; if (lifeState _x == "INCAPACITATED") then {_distance = _distance + 5}; [_distance, _x]};
		_enemies sort true; _enemy = _enemies#0#1;
		_unit doMove ([[[getPos _enemy, 5]],[]] call BIS_fnc_randomPos);
		if (_unit distance _enemy > _reach || random 1 > _actionChance) then {[_unit] call tsp_fnc_gesture_stop; continue};
		[_unit, (_unit getReldir _enemy) + getDir _unit, 0.1] spawn tsp_fnc_lookAt;
		[_unit, if (_enemy getVariable ["ACE_isUnconscious", false]) then {"kick"} else {selectRandom ["main","main","alt","kick"]}] spawn tsp_fnc_melee_action;		
	};
};

tsp_fnc_melee_ai_module = {params ["_module"]; [attachedTo _module] remoteExec ['tsp_fnc_melee_ai', attachedTo _module]; deleteVehicle _module};