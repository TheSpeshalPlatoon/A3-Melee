//-- This method SUCKS, if anyone knows how to make proper movesets, lmk
tsp_fnc_melee_moveset_change = {
    params ["_unit", ["_moveset", ""], ["_sleep", false], ["_anim", ""]]; sleep 0.001;
    if (vehicle _unit != _unit || !isNil "tsp_switch") exitWith {};
    if ((getText (configFile >> "CfgMovesMaleSdr" >> "States">> (animationState _unit) >> "moveset")) isEqualTo _moveset) exitWith {};  //-- If trying to replace current moveset with same one, do nothing
    if !(isNil "tsp_melee_movesetChange") exitWith {}; [] spawn {tsp_melee_movesetChange = true; sleep 0.5; tsp_melee_movesetChange = nil};  //-- Anti spam
    if (_moveset == "knife") then {
        _anim = "tsp_" + animationState _unit,;
        _anim = _anim regexReplace ["sraswpst", "snonwnon"];
        _anim = _anim regexReplace ["sraswrfl", "snonwnon"];
        _anim = _anim regexReplace ["mtac", "mwlk"];
    } else {
        _anim = animationState _unit regexReplace ["tsp_", ""];
        if (currentWeapon _unit == "") exitWith {};
        if (currentWeapon _unit == primaryWeapon _unit) exitWith {_anim = _anim regexReplace ["snonwnon", "sraswrfl"]};
        if (currentWeapon _unit == handgunWeapon _unit) exitWith {_anim = _anim regexReplace ["snonwnon", "sraswpst"]};
        if (currentWeapon _unit == secondaryWeapon _unit) exitWith {_anim = _anim regexReplace ["snonwnon", "sraswlnr"]};
    };
    _unit playMoveNow _anim;
    sleep 0.2; if ('wlnr' in animationState _unit) then {_unit switchMove _anim}; 
    sleep 0.1; if (_moveset == "knife" && "amov" in gestureState _unit) then {_unit playActionNow "tsp_common_stop"};
};

tsp_fnc_melee_moveset_poll = {
    params ["_unit"];
    if (getText (configFile >> "CfgMelee" >> ([_unit] call tsp_fnc_melee_weapon) >> "moveset") == "") exitWith {[_unit] spawn tsp_fnc_melee_moveset_change};
    [_unit, if (_unit call tsp_fnc_melee_doing) then {""} else {"knife"}] spawn tsp_fnc_melee_moveset_change;
};
	
waitUntil {!isNull findDisplay 46};
["weapon", {params ["_unit"]; if (getText (configFile >> "CfgMelee" >> [_unit] call tsp_fnc_melee_weapon >> "moveset") == "knife") then {_unit playActionNow "tsp_common_stop"}}] call CBA_fnc_addPlayerEventHandler;
player addEventHandler ["OpticsSwitch", {params ["_unit", "_ads"]; if (_ads && (getText (configFile >> "CfgMovesMaleSdr" >> "States">> (animationState _unit) >> "moveset")) != "") then {_unit switchCamera "INTERNAL"}}];
player addEventHandler ["AnimDone", {params ["_unit"]; [_unit] call tsp_fnc_melee_moveset_poll}];
player addEventHandler ["AnimChanged", {params ["_unit"]; [_unit] call tsp_fnc_melee_moveset_poll}];
(findDisplay 46) displayAddEventHandler ["KeyDown", {[] spawn {sleep 0.1; [playa] call tsp_fnc_melee_moveset_poll}}];
//[] spawn {tsp_cba_melee_moveset = true; while {sleep 0.1; tsp_cba_melee_moveset} do {[playa] call tsp_fnc_melee_moveset_poll};};