class CfgPatches {
	class tsp_melee_splittingaxe {
		requiredAddons[] = {"tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_axe;
	class tsp_meleeWeapon_splittingaxe: tsp_meleeWeapon_axe {
		scope = 2;
		scopeArsenal = 2; 
		scopeCurator = 2;
		model = "tsp_melee_splittingaxe\splittingaxe.p3d";
		picture = "\tsp_melee_splittingaxe\gui\ui.paa";
		displayname = "Splitting Axe";
		descriptionShort = "Basic splitting axe with a wooden handle.";
	};
};