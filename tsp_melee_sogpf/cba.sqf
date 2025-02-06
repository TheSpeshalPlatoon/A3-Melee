["tsp_cba_melee_sogpf", "CHECKBOX", ["Disable SOGPF Melee", "Disable SOGPF melee."], "TSP Melee", true, true] call CBA_fnc_addSetting;

/*
wpnclasses = [];
{wpnclasses pushBack [_x, [configFile >> "CfgWeapons" >> _x, true] call BIS_fnc_returnParents]} forEach [
    "vn_m_bayo_carbine",
    "vn_m_bayo_m1897",
    "vn_m_bayo_m4956",
    "vn_m_bayo_m14",
    "vn_m_bayo_m16",
    "vn_m_axe_01",
    "vn_m_axe_fire",
    "vn_m_bolo_01",
    "vn_m_fishing_rod_01",
    "vn_m_hammer",
    "vn_m_fighting_knife_01",
    "vn_m_vc_knife_01",
    "vn_m_m51_etool_01",
    "vn_m_machete_02",
    "vn_m_machete_01",
    "vn_m_mk2_knife_01",
    "vn_m_shovel_01",
    "vn_m_wrench_01",
    "vn_m_typeivaxe_01",

    "vn_b_k98k","vn_b_m1903","vn_b_l1a1","vn_b_m1897","vn_b_carbine","vn_b_m1_garand","vn_b_m14","vn_b_m16","vn_b_m4956","vn_b_m36","vn_b_m38","vn_b_sks","vn_b_type56"  //-- Bayonets
];

[
	["vn_m_bayo_carbine",["vn_m_bayo_carbine","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_bayo_m1897",["vn_m_bayo_m1897","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_bayo_m4956",["vn_m_bayo_m4956","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_bayo_m14",["vn_m_bayo_m14","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_bayo_m16",["vn_m_bayo_m16","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_axe_01",["vn_m_axe_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_axe_fire",["vn_m_axe_fire","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_bolo_01",["vn_m_bolo_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_fishing_rod_01",["vn_m_fishing_rod_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_hammer",["vn_m_hammer","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_fighting_knife_01",["vn_m_fighting_knife_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_vc_knife_01",["vn_m_vc_knife_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_m51_etool_01",["vn_m_m51_etool_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_machete_02",["vn_m_machete_02","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_machete_01",["vn_m_machete_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_mk2_knife_01",["vn_m_mk2_knife_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_shovel_01",["vn_m_shovel_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_wrench_01",["vn_m_wrench_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],
	["vn_m_typeivaxe_01",["vn_m_typeivaxe_01","vn_hand_melee_base_dynamic_scope","vn_hand_melee_base","vn_melee_base","Pistol_Base_F","Pistol","PistolCore","Default"]],

	["vn_b_k98k",["vn_b_k98k","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_m1903",["vn_b_m1903","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_l1a1",["vn_b_l1a1","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_m1897",["vn_b_m1897","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_carbine",["vn_b_carbine","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_m1_garand",["vn_b_m1_garand","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_m14",["vn_b_m14","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_m16",["vn_b_m16","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_m4956",["vn_b_m4956","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_m36",["vn_b_m36","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_m38",["vn_b_m38","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_sks",["vn_b_sks","vn_acc_bayo_base","ItemCore","Default"]],
	["vn_b_type56",["vn_b_type56","vn_acc_bayo_base","ItemCore","Default"]]
]
*/