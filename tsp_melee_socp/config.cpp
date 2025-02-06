class CfgPatches {
	class tsp_melee_socp {
		requiredAddons[] = {"tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_knifeDown;
	class tsp_meleeWeapon_socp: tsp_meleeWeapon_knifeDown {
		scope = 2;
		model = "tsp_melee_socp\socp.p3d";
		picture = "\tsp_melee_socp\gui\ui.paa";
		displayname = "SOCP Dagger";
		descriptionShort = "Special Operations Combatives Program knife.";
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};
};