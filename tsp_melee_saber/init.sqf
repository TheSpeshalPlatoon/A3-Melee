tsp_fnc_melee_saber = {
    params ["_unit", "_new", "_old"];
    if (!isNil "tsp_saber") exitWith {deleteVehicle tsp_saber; tsp_saber = nil; _unit playAction "tsp_common_stop"};
    if ("saber" in _old && isNil "tsp_saber") exitWith {
        tsp_saber = createSimpleObject ["tsp_melee_saber\scabbard.p3d", getPos _unit]; 
        tsp_saber attachTo [_unit, [-0.12,0.2,-0.3], "Spine3", true];  
        [tsp_saber, [-50,-10,210]] call BIS_fnc_setObjectRotation;
        _unit playAction "tsp_common_stop";
    };
};

waitUntil {!isNull findDisplay 46};
["weapon", {_this call tsp_fnc_melee_saber}] call CBA_fnc_addPlayerEventHandler;