class CfgPatches {
	class tsp_melee_kitchen {
		requiredAddons[] = {"tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_knifeUp;
	class tsp_meleeWeapon_kitchen: tsp_meleeWeapon_knifeUp {
		scope = 2;
		model = "tsp_melee_kitchen\kitchen.p3d";
		picture = "\tsp_melee_kitchen\gui\ui.paa";
		displayname = "Kitchen Knife";
		descriptionShort = "Japanese Kitchen Knife";
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};
};