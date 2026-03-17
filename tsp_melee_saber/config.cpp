class CfgPatches {
	class tsp_melee_saber {
		requiredAddons[] = {"cba_common","tsp_melee"};
		units[] = {};
	};
};

class Extended_PostInit_EventHandlers {class tsp_melee_saber_init {init = "['CBA_settingsInitialized', {[] spawn compileScript ['\tsp_melee_saber\init.sqf']}] call CBA_fnc_addEventHandler;";};};  

class CfgWeapons {
	class tsp_meleeWeapon_knifeUp;
	class tsp_meleeWeapon_saber: tsp_meleeWeapon_knifeUp {
		scope = 2;
		model = "tsp_melee_saber\saber.p3d";  //https://sketchfab.com/3d-models/cavalry-saber-ww1-sabre-sword-94ba67d2f393457e8ee9d2d1fb2d7178
		picture = "\tsp_melee_saber\gui\ui.paa";
		displayname = "Cavalry Saber";
		descriptionShort = "WW1 Cavalry Saber Saber";
		meleeType = "saber";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\tsp_melee_saber\tex\saber_co.paa"};
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};
};