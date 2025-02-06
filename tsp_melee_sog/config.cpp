class CfgPatches {
	class tsp_melee_sog {
		requiredAddons[] = {"tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_knifeUp;
	class tsp_meleeWeapon_sog: tsp_meleeWeapon_knifeUp {
		scope = 2;
		model = "tsp_melee_sog\sog.p3d";
		picture = "\tsp_melee_sog\gui\ui.paa";
		displayname = "SOG Throwing Knife";
		descriptionShort = "Simple throwing knife with paracord, can also be used as a backup field knife.";
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};
};