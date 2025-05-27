class CfgPatches {
	class tsp_melee_spe44 {
		requiredAddons[] = {"tsp_core", "tsp_melee", "cba_common", "WW2_SPE_Core_f_System_Infantry_f"};		
        skipWhenMissingDependencies = 1;
		units[] = {};
	};
};


class Extended_PreInit_EventHandlers {class tsp_melee_spe44_cba {init = "['tsp_cba_melee_spe44', 'CHECKBOX', ['Disable SPE44 Melee', 'Disable SPE44 melee.'], 'TSP Melee', true, true, {SPE_ACE_AllowBayonet = !tsp_cba_melee_spe44}] call CBA_fnc_addSetting";};};
class Extended_PostInit_EventHandlers {class tsp_melee_spe44_init {init = "[] spawn {waitUntil {sleep 1; !isNil 'SPE_ACE_AllowBayonet'}; SPE_ACE_AllowBayonet = !tsp_cba_melee_spe44}";};};
class CfgFunctions {class SPE {class melee {class bayonet_actionCondition {file = "tsp_melee_spe44\action.sqf";};};};};

class CfgWeapons {
    class SPE_ACC_base;
    class SPE_ACC_Bayonet_Base: SPE_ACC_base {meleeType = "bayonet";};
};