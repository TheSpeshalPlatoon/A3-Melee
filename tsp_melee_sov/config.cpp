class CfgPatches {
    class tsp_melee_sov {
        requiredAddons[] = {"tsp_core", "tsp_melee", "cba_common", "MMM_SOV_AK74", "MMM_SOV_AKM"};
        skipWhenMissingDependencies = 1;
        units[] = {};
    };
};

class Extended_PreInit_EventHandlers {
	class melee_6Kh4_fix {init = "tsp_fnc_melee_sov_6Kh4_fix = {if ('6Kh4' in (primaryWeaponItems _this)#0) then {_this addPrimaryWeaponItem (if ('AK74' in currentWeapon _this) then {'MMM_Acc_6Kh4_AK74'} else {'MMM_Acc_6Kh4_AKM'})}}";};
};

class Extended_PostInit_EventHandlers {
	class melee_6Kh4_inv {init = "player addEventHandler ['InventoryClosed', {player call tsp_fnc_melee_sov_6Kh4_fix}];";};
	class melee_6Kh4_init {init = "addMissionEventHandler ['EntityCreated', {_this spawn {sleep 1; _this call tsp_fnc_melee_sov_6Kh4_fix}}];";};
	class melee_6Kh4_arsenal {init = "[missionNamespace, 'arsenalOpened', {_this spawn {_this params ['_display', '_center']; while {sleep 0.2; !isNull _display} do {player call tsp_fnc_melee_sov_6Kh4_fix}}}] call BIS_fnc_addScriptedEventHandler;";};
	class melee_6Kh4_ace {init = "['ace_arsenal_displayOpened', {_this spawn {_this params ['_display']; while {sleep 0.2; !isNull _display} do {player call tsp_fnc_melee_sov_6Kh4_fix}}}] call CBA_fnc_addEventHandler;";};
};

class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {                
				class tsp_melee_6Kh4_bayonet {
                    displayName = "Convert 6Kh4 to Bayonet"; icon = "\tsp_melee\gui\bayonet.paa";
					condition = "'tsp_meleeWeapon_6kh4' in items _player || handgunWeapon _player == 'tsp_meleeWeapon_6kh4'";
					statement = "[_player, 'tsp_meleeWeapon_6kh4', 'MMM_Acc_6Kh4_AKM'] call tsp_fnc_melee_bayonet";
				};
				class tsp_melee_6Kh4_knife {
                    displayName = "Convert 6Kh4 to Knife"; icon = "\tsp_melee\gui\knife.paa";
					condition = "'MMM_Acc_6Kh4_AKM' in items _player || 'MMM_Acc_6Kh4_AKM' in primaryWeaponItems player";
					statement = "[_player, 'MMM_Acc_6Kh4_AKM', 'tsp_meleeWeapon_6kh4'] call tsp_fnc_melee_bayonet";
				};
				class tsp_melee_6Kh4_knife_ak74 {
                    displayName = "Convert 6Kh4 to Knife"; icon = "\tsp_melee\gui\knife.paa";
					condition = "'MMM_Acc_6Kh4_AK74' in items _player || 'MMM_Acc_6Kh4_AK74' in primaryWeaponItems player";
					statement = "[_player, 'MMM_Acc_6Kh4_AK74', 'tsp_meleeWeapon_6kh4'] call tsp_fnc_melee_bayonet";
				};
            };
        };
    };
};

class rhs_russian_akm_muzzle_slot;
class MMM_muzzle_AKM_slot: rhs_russian_akm_muzzle_slot {class compatibleItems;};
class CfgWeapons {
    class ItemCore;
    class MMM_Acc_6Kh4_AKM: ItemCore {displayName = "6Kh4"; meleeType = "bayonet";};  //-- Add melee, rename to remove ("AK74")
    class MMM_Acc_6Kh4_AK74: ItemCore {displayName = "6Kh4"; scope = 1; scopeArsenal = 1; meleeType = "bayonet";};  //-- Add melee, rename to remove ("AKM") and hide from arsenal

    class tsp_meleeWeapon_knifeUp;
    class tsp_meleeWeapon_6kh4: tsp_meleeWeapon_knifeUp {
        scope = 2;
        model = "tsp_melee_sov\6kh4_knife.p3d";
        picture = "\MMM_SOV_Knife\ico\MMM_ico_6Kh4_ca.paa";
        displayname = "6Kh4 Bayonet";
        descriptionShort = "Rifle bayonet<br />Year of Service: 1974<br />Used by: AKM, AK-74";
        class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
    };

    class rhs_weap_ak74m_Base_F;
    
    //-- Allow AKM to use AK74 bayonet
    class rhs_weap_akm: rhs_weap_ak74m_Base_F {class WeaponSlotsInfo;};
    class MMM_weap_AKM_H1S1: rhs_weap_akm {class WeaponSlotsInfo: WeaponSlotsInfo {class MuzzleSlot: MMM_muzzle_AKM_slot {class compatibleItems: compatibleItems {MMM_Acc_6Kh4_AKM = 1; MMM_Acc_6Kh4_AK74 = 1;};};};};

    //-- Allow AK74 to use AKM bayonet
    class rhs_weap_ak74m: rhs_weap_ak74m_Base_F {class WeaponSlotsInfo;};
    class MMM_weap_AK74_H1S1: rhs_weap_ak74m {class WeaponSlotsInfo: WeaponSlotsInfo {class MuzzleSlot: MMM_muzzle_AKM_slot {class compatibleItems: compatibleItems {MMM_Acc_6Kh4_AKM = 1; MMM_Acc_6Kh4_AK74 = 1;};};};};
};