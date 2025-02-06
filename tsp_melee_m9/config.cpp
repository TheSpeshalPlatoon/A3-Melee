class CfgPatches {
	class tsp_melee_m9 {
		requiredAddons[] = {"cba_common", "tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class Extended_PostInit_EventHandlers {
	class melee_m9_m27 {init = "player addEventHandler ['InventoryClosed', {if !('m9' in (primaryWeaponItems player)#3) exitWith {}; player addPrimaryWeaponItem (if ('m27' in currentWeapon player) then {'tsp_meleeWeapon_m9_bipod_m27'} else {'tsp_meleeWeapon_m9_bipod'})}];";};
};

class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class ACE_Equipment {
				class tsp_melee_m9s_bayonet {
					displayName = "Convert M9 to Bayonet"; 
					icon = "\tsp_melee\gui\bayonet.paa";
					condition = "'tsp_meleeWeapon_m9' in items _player || handgunWeapon _player == 'tsp_meleeWeapon_m9'";
					statement = "[_player, 'tsp_meleeWeapon_m9', 'tsp_meleeWeapon_m9_bipod'] call tsp_fnc_melee_bayonet";
				};
				class tsp_melee_m9s_knife {
					displayName = "Convert M9 to Knife"; 
					icon = "\tsp_melee\gui\knife.paa";
					condition = "'tsp_meleeWeapon_m9_bipod' in items _player || 'tsp_meleeWeapon_m9_bipod' in primaryWeaponItems player";
					statement = "[_player, 'tsp_meleeWeapon_m9_bipod', 'tsp_meleeWeapon_m9'] call tsp_fnc_melee_bayonet";
				};
				class tsp_melee_m9s_knife_m27 {
					displayName = "Convert M9 to Knife"; 
					icon = "\tsp_melee\gui\knife.paa";
					condition = "'tsp_meleeWeapon_m9_bipod_m27' in items _player || 'tsp_meleeWeapon_m9_bipod_m27' in primaryWeaponItems player";
					statement = "[_player, 'tsp_meleeWeapon_m9_bipod_m27', 'tsp_meleeWeapon_m9'] call tsp_fnc_melee_bayonet";
				};
			};
		};
	};
};
class rhs_western_rifle_underbarrel_slot;
class rhs_western_rifle_underbarrel_slot_import: rhs_western_rifle_underbarrel_slot {class compatibleItems;};
class CfgWeapons {
	class tsp_meleeWeapon_knifeDown;
	class tsp_meleeWeapon_m9: tsp_meleeWeapon_knifeDown	{
		scope = 2;
		model = "tsp_melee_m9\m9.p3d";
		picture = "\tsp_melee_m9\gui\ui.paa";
		displayname = "M9 Bayonet";
		descriptionShort = "US Army standard issue bayonet";
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};
	class tsp_meleeWeapon_bipod;
	class tsp_meleeWeapon_m9_bipod: tsp_meleeWeapon_bipod {
		scope = 2;
		displayname = "M9 Bayonet";
		descriptionShort = "US Army standard issue bayonet";
		model = "tsp_melee_m9\m9bipod.p3d";
		picture = "\tsp_melee_m9\gui\ui.paa";
	};
	class tsp_meleeWeapon_m9_bipod_m27: tsp_meleeWeapon_m9_bipod {
		scope = 1;
		displayname = "M9 Bayonet (M27 IAR)";
		model = "tsp_melee_m9\m9bipodm27.p3d";
	};

	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F {class WeaponSlotsInfo;};
	class rhs_weap_m4_Base: arifle_MX_Base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: rhs_western_rifle_underbarrel_slot_import {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_m9_bipod = 1;};
			};
		};
	};
	class rhs_weap_m4a1: rhs_weap_m4_Base {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: underBarrelSlot {
				class compatibleItems;
			};
		};
	};
	class rhs_weap_m4a1_blockII: rhs_weap_m4a1 {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: underBarrelSlot {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_m9_bipod = 0;};
			};
		};
	};
	class rhs_weap_hk416d10: rhs_weap_m4a1 {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: underBarrelSlot {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_m9_bipod = 0;};
			};			
		};
	};

	class rhs_weap_m27iar: rhs_weap_m4a1 {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: rhs_western_rifle_underbarrel_slot_import {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_m9_bipod = 1; tsp_meleeWeapon_m9_bipod_m27 = 1;};
			};			
		};
	};
	class rhs_weap_m27iar_grip: rhs_weap_m27iar {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: rhs_western_rifle_underbarrel_slot_import {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_m9_bipod = 1; tsp_meleeWeapon_m9_bipod_m27 = 1;};
			};			
		};
	};
};
