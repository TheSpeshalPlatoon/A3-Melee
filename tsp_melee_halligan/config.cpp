class CfgPatches {
	class tsp_melee_halligan {
		requiredAddons[] = {"tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_axe;
	class tsp_meleeWeapon_halligan: tsp_meleeWeapon_axe {
		scope = 2;
		scopeArsenal = 2; 
		scopeCurator = 2;
		meleeType = "sledge";
		model = "tsp_melee_halligan\halligan.p3d";
		picture = "\tsp_melee_halligan\gui\ui.paa";
		displayname = "Halligan Bar";
		descriptionShort = "A Halligan bar is a forcible entry tool commonly used by firefighters.";
	};
};