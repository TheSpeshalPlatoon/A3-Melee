class CfgPatches {
	class tsp_melee_sogpf {
		requiredAddons[] = {"tsp_core", "tsp_melee", "cba_common", "vn_weapons", "functions_f_vietnam"};		
        skipWhenMissingDependencies = 1;
		units[] = {};
	};
};

class Extended_PreInit_EventHandlers {class tsp_melee_sogpf_cba {init = "[] call compileScript ['\tsp_melee_sogpf\cba.sqf']";};};
class CfgFunctions {class functions_f_vietnam {class vn_melee_functions {class melee_action {file = "tsp_melee_sogpf\action.sqf";};};};};

class CfgWeapons {
    class Pistol_Base_F;
	//class vn_melee_base: Pistol_Base_F {showToPlayer=0;};

    class ItemCore;
    class vn_acc_bayo_base: ItemCore {meleeType = "bayonet";};

    class vn_hand_melee_base;
    class vn_hand_melee_base_dynamic_scope: vn_hand_melee_base {meleeType = "knifeUp";};
    class vn_m_fishing_rod_01: vn_hand_melee_base_dynamic_scope {meleeType = "knifeTraining";};
    class vn_m_hammer: vn_hand_melee_base_dynamic_scope {meleeType = "gavel";};
    class vn_m_m51_etool_01: vn_hand_melee_base_dynamic_scope {meleeType = "spade";};
    class vn_m_shovel_01: vn_hand_melee_base_dynamic_scope {meleeType = "spade";};
    class vn_m_wrench_01: vn_hand_melee_base_dynamic_scope {meleeType = "gavel";};
};