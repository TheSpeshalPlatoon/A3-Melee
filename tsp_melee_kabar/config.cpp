class CfgPatches {
	class tsp_melee_kabar {
		requiredAddons[] = {"tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_knifeUp;
	class tsp_meleeWeapon_kabar: tsp_meleeWeapon_knifeUp {
		scope = 2;
		model = "tsp_melee_kabar\kabar.p3d";
		picture = "\tsp_melee_kabar\gui\ui.paa";
		displayname = "KA-BAR";
		descriptionShort = "USMC standard issue comabt knife";
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};
};