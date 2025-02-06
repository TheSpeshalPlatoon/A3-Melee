class CfgPatches {
	class tsp_melee_mpl50 {
		requiredAddons[] = {"cba_common","tsp_melee"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_knifeUp;
	class tsp_meleeWeapon_mpl50: tsp_meleeWeapon_knifeUp {
		scope = 2;
		model = "tsp_melee_mpl50\mpl50.p3d";
		picture = "\tsp_melee_mpl50\gui\ui.paa";
		displayname = "MPL50 Spade (Green)";
		descriptionShort = "Russian standard issue entrenching tool";
		meleeType = "spade";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\tsp_melee_mpl50\tex\mpl50_co.paa"};
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};

	class tsp_meleeWeapon_mpl50_black: tsp_meleeWeapon_mpl50 {
		picture = "\tsp_melee_mpl50\gui\ui_black.paa";
		displayname = "MPL50 Spade (Black)";
		hiddenSelectionsTextures[] = {"\tsp_melee_mpl50\tex\mpl50_black_co.paa"};
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};

	class tsp_meleeWeapon_mpl50_dave: tsp_meleeWeapon_mpl50 {
		picture = "\tsp_melee_mpl50\gui\ui_black.paa";
		displayname = "MPL50 Spade (Dave)";
		hiddenSelectionsTextures[] = {"\tsp_melee_mpl50\tex\mpl50_dave_co.paa"};
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};
};