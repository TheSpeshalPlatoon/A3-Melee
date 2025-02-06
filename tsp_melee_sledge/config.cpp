class CfgPatches {
	class tsp_melee_sledge {
		requiredAddons[] = {"tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_axe;
	class tsp_meleeWeapon_sledge_red: tsp_meleeWeapon_axe {
		scope = 2;
		scopeArsenal = 2; 
		scopeCurator = 2;
		meleeType = "sledge";
		model = "tsp_melee_sledge\sledge_red.p3d";
		picture = "\tsp_melee_sledge\gui\ui_red.paa";
		displayname = "Sledge Hammer (Red)";
		descriptionShort = "Big hitter.";
	};
	class tsp_meleeWeapon_sledge_black: tsp_meleeWeapon_sledge_red {
		model = "tsp_melee_sledge\sledge_black.p3d";
		picture = "\tsp_melee_sledge\gui\ui_black.paa";
		displayname = "Sledge Hammer (Black)";
	};
};