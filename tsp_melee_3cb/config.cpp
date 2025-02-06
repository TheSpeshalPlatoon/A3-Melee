class CfgPatches {
	class tsp_melee_compat {
		requiredAddons[] = {"tsp_core", "tsp_melee", "cba_common", "UK3CB_BAF_Weapons_L3A1"};		
        skipWhenMissingDependencies = 1;
		units[] = {};
	};
};

class CfgWeapons {
    class muzzle_snds_H;
    class UK3CB_BAF_Bayonet_L3A1: muzzle_snds_H {meleeType = "bayonet";};
};