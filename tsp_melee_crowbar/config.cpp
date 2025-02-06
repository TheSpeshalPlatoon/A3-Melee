class CfgPatches {
	class tsp_melee_crowbar {
		requiredAddons[] = {"tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_axe;
	class tsp_meleeWeapon_crowbar: tsp_meleeWeapon_axe {
		scope = 2;
		scopeArsenal = 2; 
		scopeCurator = 2;
		meleeType = "sledge";
		model = "a3\Props_F_Orange\Items\Tools\Crowbar_01_F";
		picture = "\tsp_melee_crowbar\gui\ui.paa";
		displayname = "Crowbar";
		descriptionShort = "Gordon's crowbar.";
	};
};