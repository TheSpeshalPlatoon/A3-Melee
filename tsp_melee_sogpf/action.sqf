if (tsp_cba_melee_sogpf) exitWith {true}

params [["_player", call vn_fnc_player, [objnull]]];

if (vn_melee_debug) then { ["Melee action check passed"] call VN_fnc_debug_message };

private _primaryweapon = (primaryweapon _player);
private _handgunweapon = (handgunweapon _player);
private _currentweapon = (currentweapon _player);
private _type = "stun";

if (_currentweapon isEqualTo _handgunweapon) exitWith {_this call vn_fnc_melee_action_handgun};

(primaryWeaponItems _player) params ["_silencer","_pointer"];

private _butt = false;
private _attached = getNumber (configFile >> "cfgweapons" >> _primaryweapon >> "vn_melee_bayonet_attached");
private _offset = getArray (configFile >> "cfgweapons" >> _primaryweapon >> "vn_melee_bayonet_startpos");
private _length = if (_attached >= 1) then
{
	_type = "stab";
	getNumber (configFile >> "cfgweapons" >> _primaryweapon >> "vn_melee_bayonet_length")
}
else
{
	if (_silencer == "" && {getNumber (configFile >> "cfgweapons" >> _pointer >> "vn_melee_bayonet") > 0}) then
	{
		_type = "stab";
		getNumber (configFile >> "cfgweapons" >> _pointer >> "vn_melee_bayonet_length")
	}
	else
	{
		_offset = [0.2,0.05,-0.2];
		_butt = true;
		2
	}
};

if (_length == 0 || (count _offset) <= 0) exitWith {};

private _fake_pos = getPosASL _player;
_fake_pos set [2, 6000];

_player setVariable ["vn_melee_busy",true];

private _ammo_type = switch (tolower _type) do
{
	case ("stab"): {"vn_melee_stab"};
	case ("stun");
	default {"vn_melee_stun"};
};
missionNamespace setVariable ["vn_melee_projectile", _ammo_type];

private _projectile = createvehicle [_ammo_type, _fake_pos, [], 0, "CAN_COLLIDE"];
[_projectile,[_player, _player]] remoteExecCall ["setShotParents", 2];

_player playActionNow ([vn_melee_stab_gesture,vn_melee_stun_gesture] select (_type isEqualTo "stun"));

private _stab_audio = selectRandom vn_melee_stab_audio;
if ( _player isEqualTo cameraOn && {cameraView in ["INTERNAL","GUNNER"]}) then
{
	enableCamShake true;
	addCamShake [1, 1, 5];
};
[_player, _stab_audio] remoteExecCall ["say3D",0,false];

vn_melee_fired_params = [_projectile, _offset, _length, _player, _butt];
["itemAdd",
	[
		"vn_melee_fired_wait",
		{
			vn_melee_fired_params params ["_projectile", "_offset", "_length", "_player", "_butt"];
			if (_player isEqualTo cameraOn && {cameraView in ["INTERNAL","GUNNER"]}) then { addCamShake [9, 1.9, 2]; };

			[_projectile, _offset, _length, _player, _butt] call vn_fnc_melee_fired;
			[_player] call vn_fnc_melee_drainstamina;
		},
		0.6,
		"seconds",
		{ true },
		{ true },
		true
	]
] call BIS_fnc_loop;
true
