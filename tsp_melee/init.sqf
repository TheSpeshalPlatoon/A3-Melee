if (isNil "KJW_Imposters_core_fnc_updateUnit") exitWith {};
player addEventHandler ["GestureChanged", {
	params ["_unit", "_gesture"]; 
	_melee = "melee" in animationState _unit || "melee" in gestureState _unit;
	_unit setVariable ["KJW_Imposters_core_ignore", _melee];
	if (_melee) then {[_unit, 5] call KJW_Imposters_core_fnc_updateUnit};
}];
player addEventHandler ["AnimStateChanged", {
	params ["_unit", "_animation"]; 
	_melee = "melee" in animationState _unit || "melee" in gestureState _unit;
	_unit setVariable ["KJW_Imposters_core_ignore", _melee];
	if (_melee) then {[_unit, 5] call KJW_Imposters_core_fnc_updateUnit};
}];