class CfgPatches {
	class tsp_melee_gavel {
		requiredAddons[] = {"cba_common", "tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_knifeUp;
	class tsp_meleeWeapon_gavel: tsp_meleeWeapon_knifeUp {
		scope = 2;
		model = "tsp_melee_gavel\gavel.p3d";
		picture = "\tsp_melee_gavel\gui\ui.paa";
		displayname = "Judge Gavel";
		descriptionShort = "TSP court standard issue judge gavel";
		meleeType = "gavel";
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};
};