class CfgPatches {
	class tsp_melee {
		requiredAddons[] = {"cba_common", "tsp_core"};
		units[] = {"tsp_module_melee"};
	};
};

//-- FUNCTIONS
class Extended_PreInit_EventHandlers {class tsp_melee_cba {init = "[] call compileScript ['\tsp_melee\cba.sqf']";}; class tsp_melee_functions {init = "[] call compileScript ['\tsp_melee\functions.sqf']";};};

//-- MELEE
class CfgMelee {
	class variant_base {
		animation = "";
		gesture = "";
		angle = 65;
		reach = 2.4;
		stamina = 5;
		swingSound[] = {{"tsp_melee\snd\swing1.ogg", 0.5}};
		swingTime = 0.1;
		impactTime = 0.1;
		restTime = 0.1;
		afterTime = 0.1;
		manDamage = 0;
		manDamageType = "punch";
		manProjectile = "";
		manEffect = "";
		manSound[] = {{"tsp_melee\snd\impact1.ogg", 1}};
		manKnockoutChance = 0;
		manKnockoutSound[] = {{"tsp_melee\snd\knockout1.ogg", 3}};
		manStunChance = 0;
		manDisarmChance = 0;
		blockableDamage[] = {};
		objectProjectile = "";
		objectSound[] = {{"tsp_melee\snd\impact1.ogg", 1}};
		environmentDamage[] = {1,0.1,0,0,0};  //_glass,_civil,_military,_reinforced,_wall
		code = "";
		condition = "false";
	};
	class variant_base_block: variant_base {gesture = "tsp_melee_fistBlock"; blockableDamage[] = {{"punch", 0.1, {{"tsp_melee\snd\impact1.ogg", 0}}}, {"stab", 0.2, {{"tsp_melee\snd\slice1.ogg", 1}}}};};
	class variant_base_kick: variant_base {reach = 2.5; manKnockoutChance = 0; manStunChance = 1; manDisarmChance = 0.5; swingTime = 0.3; impactTime = 0.1; restTime = 0.3; afterTime = 0.1; environmentDamage[] = {1,0.6,0.3,0,0};};
	class fist {
		class ready {
			class variant: variant_base {gesture = "tsp_melee_fistReady";};
			class variant1: variant {gesture = "tsp_melee_fistReady1";}
			class variant2: variant {gesture = "tsp_melee_fistReady2";}
			class variant3: variant {gesture = "tsp_melee_fistReady3";}
		};
		class block {class variant: variant_base_block {gesture = "tsp_melee_fistBlock";};};
		class main {
			class variant: variant_base {gesture = "tsp_melee_fistPunchRight"; manDamage = 0.12; manKnockoutChance = 0.1;};
			class variant1: variant {gesture = "tsp_melee_fistPunchLeft";};
		};
		class alt {
			class variant: variant_base {
				gesture = "tsp_melee_fistPush";
				stamina = 15; 
				manStunChance = 1;
				manDisarmChance = 0.75;
				swingTime = 0.3;
				impactTime = 0.2;
				afterTime = 0.2;
			};
			class variant1: variant_base {
				gesture = "tsp_melee_fistPunchBig"; 
				stamina = 15; 
				manDamage = 0.25; 
				manKnockoutChance = 0.9; 
				swingTime = 0.3; 
				impactTime = 0.2; 
				afterTime = 0.2; 
			};
		};
		class kick {class variant: variant_base_kick {animation = "tsp_melee_fistKick"; gesture = "tsp_common_stop";};};
		class dodge_left {class variant: variant_base {animation = "tsp_melee_fist_dodge_left"; gesture = "tsp_common_stop";};};
		class dodge_right {class variant: variant_base {animation = "tsp_melee_fist_dodge_right"; gesture = "tsp_common_stop";};};
		class special {
			class variant: variant_base {
				condition = "alive (_this#1) && stance (_this#0) in ['STAND','CROUCH'] && speed (_this#1) < 12 && [position (_this#1), (getDir (_this#1))-180, 180, position (_this#0)] call BIS_fnc_inAngleSector";
				code = "[_this#0, _this#1, 'tsp_melee_fistAttacker', 'tsp_melee_fistVictim', 2.75, 'tsp_melee\snd\choke.ogg'] spawn tsp_fnc_melee_takedown";
			};
		};
	};
	class rifle {
		class ready {class variant: variant_base {gesture = "tsp_melee_rifleReady";};};
		class block {class variant: variant_base_block {gesture = "tsp_melee_rifleBlock";}; class variant1: variant_base_block {gesture = "tsp_melee_rifleBlock1";};};
		class main {
			class variant: variant_base {
				gesture = "tsp_melee_rifleSlashRight"; 
				manDamage = 0.15; 
				manKnockoutChance = 0.5;
				manStunChance = 0.5; 
				manDisarmChance = 0.5; 
				objectProjectile = "tsp_melee_medium";
			};
			class variant1: variant {gesture = "tsp_melee_rifleSlashLeft";};
		};
		class alt {
			class variant: variant_base {
				gesture = "tsp_melee_rifleButt"; 
				stamina = 20;
				manDamage = 0.15; 
				manKnockoutChance = 1; 
				manStunChance = 0.75;
				manDisarmChance = 0.75; 
				swingTime = 0.3; 
				impactTime = 0.2; 
				afterTime = 0.2; 
				objectProjectile = "tsp_melee_medium";
			};
		};
		class kick {class variant: variant_base_kick {animation = "tsp_melee_rifleKick"; gesture = "";};};
		class dodge_left {class variant: variant_base {animation = "tsp_melee_rifle_dodge_left"; gesture = "tsp_melee_rifleblock";};};
		class dodge_right {class variant: variant_base {animation = "tsp_melee_rifle_dodge_right"; gesture = "tsp_melee_rifleblock";};};
		class special {class variant: variant_base {condition = "false";}}
	};
	class pistol {
		class ready {class variant: variant_base {gesture = "tsp_melee_pistolReady";};};
		class block {class variant: variant_base_block {gesture = "tsp_melee_pistolBlock";};};
		class main {
			class variant: variant_base {
				gesture = "tsp_melee_pistolSlashRight"; 
				manDamage = 0.1;
				manKnockoutChance = 0.5;
				manStunChance = 0.5;
				manDisarmChance = 0.5;
				impactTime = 0.15;
				restTime = 0.05;
				afterTime = 0.1;
				objectProjectile = "tsp_melee_medium";
			};
			class variant1: variant {gesture = "tsp_melee_pistolSlashLeft";};
		};
		class alt {
			class variant: variant_base {
				gesture = "tsp_melee_pistolButt"; 
				stamina = 20;
				manDamage = 0.2; 
				manKnockoutChance = 1;
				manStunChance = 0.75; 
				manDisarmChance = 0.75;
				swingTime = 0.4; 
				restTime = 0.25; 
				afterTime = 0.2; 
				objectProjectile = "tsp_melee_medium";
			};
		};
		class kick {class variant: variant_base_kick {animation = "tsp_melee_pistolKick"; gesture = "tsp_common_stop";};};
		class dodge_left {class variant: variant_base {animation = "tsp_melee_pistol_dodge_left";};};
		class dodge_right {class variant: variant_base {animation = "tsp_melee_pistol_dodge_right"; gesture = "tsp_melee_pistolblock";};};
		class special {class variant: variant_base {condition = "false";}}
	};
	class knifeDown {
		moveset = "knife";
		class ready {
			class variant: variant_base {gesture = "tsp_melee_knifeDownReady";};
			class variant1: variant {gesture = "tsp_melee_knifeDownReady1";};
			class variant2: variant {gesture = "tsp_melee_knifeDownReady2";};
		};
		class block {class variant: variant_base_block {gesture = "tsp_melee_knifeBlock";};};
		class main {
			class variant: variant_base {
				gesture = "tsp_melee_knifeSlashLeft"; 
				manDamage = 0.25; 
				manDamageType = "stab";
				manProjectile = "tsp_melee_man";
				manSound[] = {{"tsp_melee\snd\stab1.ogg", 2}, {"tsp_melee\snd\stab3.ogg", 2}};	
				manKnockoutChance = 0.1; 
				manKnockoutSound[] = {{"tsp_melee\snd\slice1.ogg", 2}};			
				manStunChance = 0.5; 
				manDisarmChance = 0.5; 
				impactTime = 0.15;
				restTime = 0.1;
				afterTime = 0.05;
				objectProjectile = "tsp_melee_medium";
			};
			class variant1: variant {gesture = "tsp_melee_knifeDownSlashRight";};
		};
		class alt {
			class variant: variant_base {
				gesture = "tsp_melee_knifeDownStab"; 
				stamina = 20;
				manDamage = 0.6;
				manDamageType = "stab";
				manProjectile = "tsp_melee_man";
				manSound[] = {{"tsp_melee\snd\stab2.ogg", 1}}; 
				manKnockoutChance = 1; 
				manKnockoutSound[] = {{"tsp_melee\snd\slice1.ogg", 1}};
				manStunChance = 0.75;
				manDisarmChance = 0.75;
				swingTime = 0.4; 
				restTime = 0.25; 
				afterTime = 0.3; 
				objectProjectile = "tsp_melee_medium";
			};
		};
		class kick {class variant: variant_base_kick {animation = "tsp_melee_pistolKick"; gesture = "tsp_common_stop";};};
		class dodge_left {class variant: variant_base {animation = "tsp_melee_pistol_dodge_left"; gesture = "tsp_melee_knifeBlock";};};
		class dodge_right {class variant: variant_base {animation = "tsp_melee_pistol_dodge_right"; gesture = "tsp_melee_knifeBlock";};};
		class special {
			class variant: variant_base {
				condition = "alive (_this#1) && stance (_this#0) in ['STAND','CROUCH'] && speed (_this#1) < 12 && [position (_this#1), (getDir (_this#1))-180, 180, position (_this#0)] call BIS_fnc_inAngleSector";
				code = "[_this#0, _this#1, 'tsp_melee_knifeDownAttacker', 'tsp_melee_knifeVictim', 1.67, 'tsp_melee\snd\takedown.ogg'] spawn tsp_fnc_melee_takedown";
			};
		};
	};
	class knifeUp: knifeDown {
		class ready {
			class variant: variant_base {gesture = "tsp_melee_knifeUpReady";};
			class variant1: variant {gesture = "tsp_melee_knifeUpReady1";};
		};
		class main: main {class variant1: variant {gesture = "tsp_melee_knifeUpSlashRight";};};
		class alt: alt {
			class variant: variant {
				gesture = "tsp_melee_knifeUpStab";
			};
		};
		class special {
			class variant: variant_base {
				condition = "alive (_this#1) && stance (_this#0) in ['STAND','CROUCH'] && speed (_this#1) < 12 && [position (_this#1), (getDir (_this#1))-180, 180, position (_this#0)] call BIS_fnc_inAngleSector";
				code = "[_this#0, _this#1, 'tsp_melee_knifeUpAttacker', 'tsp_melee_knifeVictim', 1.67, 'tsp_melee\snd\takedown.ogg'] spawn tsp_fnc_melee_takedown";
			};
		};
	};
	class bayonet: knifeDown {
		moveset = "";
		class ready {class variant: variant_base {gesture = "tsp_melee_rifleReady";};};
		class block {class variant: variant_base_block {gesture = "tsp_melee_rifleBlock";}; class variant1: variant_base_block {gesture = "tsp_melee_rifleBlock1";};};
		class main: main {
			class variant: variant {gesture = "tsp_melee_rifleSlashRight"; reach = 2.5; manDamage = 0.3; objectProjectile = "tsp_melee_big";};
			class variant1: variant {gesture = "tsp_melee_rifleSlashLeft";};
		};
		class alt: alt {
			class variant: variant {gesture = "tsp_melee_rifleBayonet"; reach = 2.5; manDamage = 0.8; restTime = 0.4; objectProjectile = "tsp_melee_big";};
			class variant1: variant {gesture = "tsp_melee_rifleBayonet1";};
		};
		class kick {class variant: variant_base_kick {animation = "tsp_melee_rifleKick"; gesture = "";};};
		class special {class variant: variant_base {condition = "false";}}
	};
	class spade: knifeDown {
		class ready {class variant: variant_base {gesture = "tsp_melee_spadeReady";};};
		class main: main {
			class variant: variant {
				manDamage = 0.2; 
				manDamageType = "punch";
				manProjectile = "";
				manSound[] = {{"tsp_melee\snd\impact1.ogg", 1}}; 
				manKnockoutChance = 0.5; 
				manKnockoutSound[] = {{"tsp_melee\snd\bonk1.ogg", 2}};
				objectProjectile = "tsp_melee_big";
			};
			class variant1: variant {gesture = "tsp_melee_knifeUpSlashRight";};
		};
		class block {class variant: variant_base_block {gesture = "tsp_melee_spadeBlock";};};
		class alt: alt {
			class variant: variant {
				gesture = "tsp_melee_spadeSmash"; 
				manSound[] = {{"tsp_melee\snd\bonk1.ogg", 1}}; 
				manKnockoutChance = 0.75;
				manKnockoutSound[] = {{"tsp_melee\snd\knockout1.ogg", 2}};
				restTime = 0.01; 
				afterTime = 0.1;
				objectProjectile = "tsp_melee_big";
				environmentDamage[] = {1,0.2,0,0,0};  //_glass,_civil,_military,_reinforced,_wall
			};
		};
		class special {class variant: variant_base {condition = "false";}}
	};
	class gavel: spade {
		class ready {class variant: variant_base {gesture = "tsp_melee_knifeupready";};};
		class main: main {
			class variant: variant {
				manSound[] = {{"tsp_melee\snd\impact1.ogg", 1}};
				manDamageType = "punch";
				manProjectile = ""; 
				manKnockoutSound[] = {{"tsp_melee\snd\bonk1.ogg", 2}}; 
				objectProjectile = "tsp_melee_big";
			};
			class variant1: variant {gesture = "tsp_melee_knifeUpSlashRight";};
		};
		class block {class variant: variant_base_block {gesture = "tsp_melee_knifeBlock";};};
		class alt: alt {
			class variant: variant {
				gesture = "tsp_melee_spadeSmash"; 
				manDamageType = "punch";
				manProjectile = "";
				manSound[] = {{"tsp_melee\snd\bonk1.ogg", 1}};
				manKnockoutSound[] = {{"tsp_melee\snd\knockout1.ogg", 2}};
				objectProjectile = "tsp_melee_big";
			};
		};
	};
	class axe {
		class ready {class variant: variant_base {gesture = "tsp_melee_axeReady";};};
		class block {class variant: variant_base_block {gesture = "tsp_melee_axeBlock";};};
		class main {
			class variant: variant_base {
				gesture = "tsp_melee_axeSlashRight";
				angle = 60;
				reach = 3;
				stamina = 10;
				swingTime = 0.2;
				impactTime = 0.15;
				restTime = 0.15;
				afterTime = 0.1;
				manDamage = 0.6; 
				manDamageType = "stab";
				manProjectile = "tsp_melee_man";
				manSound[] = {{"tsp_melee\snd\stab1.ogg", 2},{"tsp_melee\snd\stab2.ogg", 2},{"tsp_melee\snd\stab3.ogg", 2}}; 
				manKnockoutChance = 0.5; 
				manKnockoutSound[] = {{"tsp_melee\snd\slice1.ogg", 1}};
				manStunChance = 0.75; 
				manDisarmChance = 0.75;
				objectProjectile = "tsp_melee_big";
				environmentDamage[] = {1,0.8,0.1,0,0};  //_glass,_civil,_military,_reinforced,_wall
			};
			class variant1: variant {gesture = "tsp_melee_axeSlashLeft";};
		};
		class alt {
			class variant: variant_base {
				gesture = "tsp_melee_axeSmash"; 
				angle = 60;
				reach = 3;
				stamina = 10;
				swingTime = 0.4; 
				restTime = 0.25; 
				afterTime = 0.3; 
				manDamage = 0.85; 
				manDamageType = "stab";
				manProjectile = "tsp_melee_man";
				manSound[] = {{"tsp_melee\snd\stab1.ogg", 2},{"tsp_melee\snd\stab2.ogg", 2},{"tsp_melee\snd\stab3.ogg", 2}}; 
				manKnockoutChance = 1; 
				manKnockoutSound[] = {{"tsp_melee\snd\knockout1.ogg", 2}};
				manStunChance = 1; 
				manDisarmChance = 1;
				objectProjectile = "tsp_melee_big";
				environmentDamage[] = {1,0.9,0.2,0,0};  //_glass,_civil,_military,_reinforced,_wall
			};
		};
		class kick {class variant: variant_base_kick {animation = "tsp_melee_axeKick"; gesture = "";};};
		class dodge_left {class variant: variant_base {animation = "tsp_melee_axe_dodge_left"; gesture = "tsp_melee_axeBlock";};};
		class dodge_right {class variant: variant_base {animation = "tsp_melee_axe_dodge_right"; gesture = "tsp_melee_axeBlock";};};
		class special {class variant: variant_base {condition = "false";}}
	};
	class sledge: axe {
		class main: alt {
			class variant: variant {
				gesture = "tsp_melee_axeSlashRight";
				manDamageType = "punch";
				manSound[] = {{"tsp_melee\snd\blunt1.ogg", 1},{"tsp_melee\snd\blunt2.ogg", 1},{"tsp_melee\snd\impact1.ogg", 1}}; 
				manKnockoutSound[] = {{"tsp_melee\snd\knockout1.ogg", 1}};
			};
			class variant1: variant {gesture = "tsp_melee_sledgeSlam";};
		};
		class alt: alt {
			class variant: variant {
				manDamageType = "punch";
				manSound[] = {{"tsp_melee\snd\blunt1.ogg", 2},{"tsp_melee\snd\blunt1.ogg", 2}}; 
				manKnockoutSound[] = {{"tsp_melee\snd\knockout1.ogg", 2}};
				environmentDamage[] = {1,0.8,0.4,0,0};  //_glass,_civil,_military,_reinforced,_wall
			};
		};
	};
};

//-- WEAPONS
class CfgMagazines {class RPG32_F; class tsp_melee_mag: RPG32_F {scope = 1; count = 0;};};
class CfgMagazineWells {class tsp_melee_magwell {mags[] = {"tsp_melee_mag"};};};
class CfgWeapons {
	class RifleCore; class Rifle: RifleCore {meleeType = "rifle";};
	class PistolCore; class Pistol: PistolCore {meleeType = "pistol";};
	class LauncherCore; class Launcher: LauncherCore {meleeType = "";};

	class Pistol_Base_F;
	class tsp_meleeWeapon_knifeDown: Pistol_Base_F {
		meleeType = "knifeDown";
		handAnim[]={"OFP2_ManSkeleton","\tsp_melee\anim\knifeDownWeapon.rtm"};	
		useModelOptics = true;
		modelOptics = "";
		weaponInfoType = "RscWeaponEmpty";	
		fireLightIntensity = 0;
		magazines[] = {};	
		magazineWells[] = {};	
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};
	class tsp_meleeWeapon_knifeUp: tsp_meleeWeapon_knifeDown {meleeType = "knifeUp"; handAnim[]={"OFP2_ManSkeleton","\tsp_melee\anim\knifeUpWeapon.rtm"};};

	class bipod_01_F_snd; class tsp_meleeWeapon_bipod: bipod_01_F_snd {meleeType = "bayonet"; scope = 0; class itemInfo {hasBipod = false; type = 302; mass = 2;};};
	class inventoryFlashLightItem_Base_F; class tsp_meleeWeapon_pointer: tsp_meleeWeapon_bipod {class itemInfo: inventoryFlashLightItem_Base_F {class Pointer {}; class FlashLight {}; mass = 2;};};
	
	class launch_RPG32_F;
	class tsp_meleeWeapon_axe: launch_RPG32_F {
		scope = 0;
		meleeType = "axe";
		handAnim[] = {"OFP2_ManSkeleton","\tsp_melee\anim\axeweapon.rtm"};
		useModelOptics = true;
		modelOptics = "";
		weaponInfoType = "RscWeaponEmpty";
		fireLightIntensity = 0;
		magazines[] = {"tsp_melee_mag"};
		magazineWells[] = {"tsp_melee_magwell"};
		magazineWell[] = {"tsp_melee_magwell"};
	};
};
class CfgAmmo {
	class B_127x33_Ball;
	class tsp_melee_big: B_127x33_Ball {
		craterEffects = "";
		effectsSmoke = "";
		hit = 40;
		timeToLive = 0.03;
		soundSetBulletFly[] = {};
		bulletFly[] = {};
		bulletFly1[] = {};		
		bulletFly2[] = {};
		bulletFly3[] = {};
		bulletFly4[] = {};
		bulletFly5[] = {};
		bulletFly6[] = {};
		bulletFly7[] = {};
		bulletFly8[] = {};
		bulletFly9[] = {};
		bulletFly10[] = {};
		bulletFly11[] = {};
		bulletFly12[] = {};
	};
	class tsp_melee_medium: tsp_melee_big {hit = 20;};
	class tsp_melee_small: tsp_melee_big {hit = 10;};
	class tsp_melee_man: tsp_melee_big {hit = 0.1;};  //-- Just blood, no damage
};

//-- MODULES
class CfgVehicles {
	class Module_F;	
	class tsp_module_melee: Module_F {
		scope = 1;
		scopeCurator = 2;
		category = "Ordnance";
		displayName = "Melee AI";
		icon = "\a3\Modules_F_Curator\Data\portraitIRGrenade_ca.paa";
		function = "tsp_fnc_melee_ai_module";
		functionPriority = 1;
		isGlobal = 0;
		isTriggerActivated = 0;
		isDisposable = 0;
		curatorCanAttach = 1;
	};
};

//-- ANIMATIONS
class CfgMovesBasic {
    class default;
    class DefaultDie;
    class ManActions {
		tsp_melee_fistReady[] = {"tsp_melee_fistReady", "Gesture"};
		tsp_melee_fistReady1[] = {"tsp_melee_fistReady1", "Gesture"};
		tsp_melee_fistReady2[] = {"tsp_melee_fistReady2", "Gesture"};
		tsp_melee_fistReady3[] = {"tsp_melee_fistReady3", "Gesture"};
		tsp_melee_fistBlock[] = {"tsp_melee_fistBlock", "Gesture"};
		tsp_melee_fistPunchRight[] = {"tsp_melee_fistPunchRight", "Gesture"};
		tsp_melee_fistPunchLeft[] = {"tsp_melee_fistPunchLeft", "Gesture"};
		tsp_melee_fistPunchBig[] = {"tsp_melee_fistPunchBig", "Gesture"};
		tsp_melee_fistPush[] = {"tsp_melee_fistPush", "Gesture"};
		tsp_melee_rifleReady[] = {"tsp_melee_rifleReady", "Gesture"};
		tsp_melee_rifleBlock[] = {"tsp_melee_rifleBlock", "Gesture"};
		tsp_melee_rifleBlock1[] = {"tsp_melee_rifleBlock1", "Gesture"};
		tsp_melee_rifleSlashRight[] = {"tsp_melee_rifleSlashRight", "Gesture"};
		tsp_melee_rifleSlashLeft[] = {"tsp_melee_rifleSlashLeft", "Gesture"};
		tsp_melee_rifleButt[] = {"tsp_melee_rifleButt", "Gesture"};
		tsp_melee_rifleBayonet[] = {"tsp_melee_rifleBayonet", "Gesture"};
		tsp_melee_rifleBayonet1[] = {"tsp_melee_rifleBayonet1", "Gesture"};
		tsp_melee_pistolReady[] = {"tsp_melee_pistolReady", "Gesture"};
		tsp_melee_pistolBlock[] = {"tsp_melee_pistolBlock", "Gesture"};
		tsp_melee_pistolSlashRight[] = {"tsp_melee_pistolSlashRight", "Gesture"};
		tsp_melee_pistolSlashLeft[] = {"tsp_melee_pistolSlashLeft", "Gesture"};
		tsp_melee_pistolButt[] = {"tsp_melee_pistolButt", "Gesture"};
		tsp_melee_knifeDownReady[] = {"tsp_melee_knifeDownReady", "Gesture"};
		tsp_melee_knifeDownReady1[] = {"tsp_melee_knifeDownReady1", "Gesture"};
		tsp_melee_knifeDownReady2[] = {"tsp_melee_knifeDownReady2", "Gesture"};
		tsp_melee_knifeDownSlashRight[] = {"tsp_melee_knifeDownSlashRight", "Gesture"};
		tsp_melee_knifeDownStab[] = {"tsp_melee_knifeDownStab", "Gesture"};
		tsp_melee_knifeUpReady[] = {"tsp_melee_knifeUpReady", "Gesture"};
		tsp_melee_knifeUpReady1[] = {"tsp_melee_knifeUpReady1", "Gesture"};
		tsp_melee_knifeUpSlashRight[] = {"tsp_melee_knifeUpSlashRight", "Gesture"};
		tsp_melee_knifeUpStab[] = {"tsp_melee_knifeUpStab", "Gesture"};
		tsp_melee_knifeBlock[] = {"tsp_melee_knifeBlock", "Gesture"};
		tsp_melee_knifeSlashLeft[] = {"tsp_melee_knifeSlashLeft", "Gesture"};
		tsp_melee_spadeReady[] = {"tsp_melee_spadeReady", "Gesture"};
		tsp_melee_spadeBlock[] = {"tsp_melee_spadeBlock", "Gesture"};
		tsp_melee_spadeSmash[] = {"tsp_melee_spadeSmash", "Gesture"};
		tsp_melee_axeReady[] = {"tsp_melee_axeReady", "Gesture"};
		tsp_melee_axeBlock[] = {"tsp_melee_axeBlock", "Gesture"};
		tsp_melee_axeSlashRight[] = {"tsp_melee_axeSlashRight", "Gesture"};
		tsp_melee_axeSlashLeft[] = {"tsp_melee_axeSlashLeft", "Gesture"};
		tsp_melee_axeSmash[] = {"tsp_melee_axeSmash", "Gesture"};
		tsp_melee_sledgeSlam[] = {"tsp_melee_sledgeSlam", "Gesture"};
	};
};
class CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	class States {  //-- Gestures
		class GestureNo;
		class tsp_melee_fistReady: GestureNo {file = "tsp_melee\anim\fistReady.rtm"; mask = "meleeFist"; looped = true; interpolationSpeed = 5; leftHandIKCurve[] = {0}; rightHandIKCurve[] = {0};};
		class tsp_melee_fistReady1: tsp_melee_fistReady {file = "tsp_melee\anim\fistReady1.rtm";};
		class tsp_melee_fistReady2: tsp_melee_fistReady {file = "tsp_melee\anim\fistReady2.rtm";};
		class tsp_melee_fistReady3: tsp_melee_fistReady {file = "tsp_melee\anim\fistReady3.rtm";};
		class tsp_melee_fistBlock: tsp_melee_fistReady {file = "tsp_melee\anim\fistBlock.rtm";};
		class tsp_melee_fistPunchRight: tsp_melee_fistReady {file = "tsp_melee\anim\fistPunchRight.rtm"; mask = "meleeFistSpine"; speed = 2; looped = false;};
		class tsp_melee_fistPunchLeft: tsp_melee_fistPunchRight {file = "tsp_melee\anim\fistPunchLeft.rtm";};
		class tsp_melee_fistPunchBig: tsp_melee_fistPunchRight {file = "tsp_melee\anim\fistPunchBig.rtm"; speed = 1;};
		class tsp_melee_fistPush: tsp_melee_fistPunchBig {file = "tsp_melee\anim\fistPush.rtm";};
		class tsp_melee_rifleReady: tsp_melee_fistReady {file = "tsp_melee\anim\rifleReady.rtm"; mask = "meleeRifle"; leftHandIKCurve[] = {1}; rightHandIKCurve[] = {1};};
		class tsp_melee_rifleBlock: tsp_melee_rifleReady {file = "tsp_melee\anim\rifleBlock.rtm";};
		class tsp_melee_rifleBlock1: tsp_melee_rifleBlock {file = "tsp_melee\anim\rifleBlock1.rtm";};
		class tsp_melee_rifleSlashRight: tsp_melee_rifleReady {file = "tsp_melee\anim\rifleSlashRight.rtm"; mask = "meleeRifleSpine"; speed = 2; looped = false;};
		class tsp_melee_rifleSlashLeft: tsp_melee_rifleSlashRight {file = "tsp_melee\anim\rifleSlashLeft.rtm";};
		class tsp_melee_rifleButt: tsp_melee_rifleSlashRight {file = "tsp_melee\anim\rifleButt.rtm"; mask = "meleeRifleSpineHeavy"; speed = 1;};
		class tsp_melee_rifleBayonet: tsp_melee_rifleButt {file = "tsp_melee\anim\rifleBayonet.rtm";};
		class tsp_melee_rifleBayonet1: tsp_melee_rifleButt {file = "tsp_melee\anim\rifleBayonet1.rtm";};
		class tsp_melee_pistolReady: tsp_melee_rifleReady {file = "tsp_melee\anim\pistolReady.rtm"; mask = "meleePistol"; showHandgun = true;};
		class tsp_melee_pistolBlock: tsp_melee_pistolReady {file = "tsp_melee\anim\pistolBlock.rtm"; speed = 0.5; mask = "meleePistolBlock"; canPullTrigger = true; disableWeapons = false;};
		class tsp_melee_pistolSlashRight: tsp_melee_pistolReady {file = "tsp_melee\anim\pistolSlashRight.rtm"; mask = "meleePistolSpine"; speed = 2; looped = false;};
		class tsp_melee_pistolSlashLeft: tsp_melee_pistolSlashRight {file = "tsp_melee\anim\pistolSlashLeft.rtm";};
		class tsp_melee_pistolButt: tsp_melee_pistolSlashRight {file = "tsp_melee\anim\pistolButt.rtm"; mask = "meleePistolSpineHeavy"; speed = 1;};
		class tsp_melee_knifeDownReady: tsp_melee_fistReady {file = "tsp_melee\anim\knifeDownReady.rtm"; mask = "meleeKnife"; showHandgun = true; canPullTrigger = false;};
		class tsp_melee_knifeDownReady1: tsp_melee_knifeDownReady {file = "tsp_melee\anim\knifeDownReady1.rtm";};
		class tsp_melee_knifeDownReady2: tsp_melee_knifeDownReady {file = "tsp_melee\anim\knifeDownReady2.rtm";};
		class tsp_melee_knifeDownSlashRight: tsp_melee_knifeDownReady {file = "tsp_melee\anim\pistolSlashRight.rtm"; mask = "meleeKnifeSpine"; speed = 2; looped = false;};
		class tsp_melee_knifeDownStab: tsp_melee_knifeDownSlashRight {file = "tsp_melee\anim\knifeDownStab.rtm"; speed = 1;};
		class tsp_melee_knifeUpReady: tsp_melee_knifeDownReady {file = "tsp_melee\anim\knifeUpReady.rtm";};
		class tsp_melee_knifeUpReady1: tsp_melee_knifeDownReady {file = "tsp_melee\anim\knifeUpReady1.rtm";};
		class tsp_melee_knifeUpSlashRight: tsp_melee_knifeDownSlashRight {file = "tsp_melee\anim\knifeUpSlashRight.rtm";};
		class tsp_melee_knifeUpStab: tsp_melee_knifeDownStab {file = "tsp_melee\anim\knifeUpStab.rtm";};
		class tsp_melee_knifeBlock: tsp_melee_knifeDownReady {file = "tsp_melee\anim\pistolBlock.rtm"; rightHandIKCurve[] = {1};};
		class tsp_melee_knifeSlashLeft: tsp_melee_knifeDownSlashRight {file = "tsp_melee\anim\pistolSlashLeft.rtm";};
		class tsp_melee_spadeReady: tsp_melee_knifeDownReady {file = "tsp_melee\anim\spadeReady.rtm";};
		class tsp_melee_spadeBlock: tsp_melee_knifeBlock {file = "tsp_melee\anim\spadeBlock.rtm";};
		class tsp_melee_spadeSmash: tsp_melee_knifeDownSlashRight {file = "tsp_melee\anim\spadeSmash.rtm"; speed = 1.5;};
		class tsp_melee_axeReady: tsp_melee_rifleReady {file = "tsp_melee\anim\axeReady.rtm"; mask = "meleeLauncher";};
		class tsp_melee_axeBlock: tsp_melee_axeReady {file = "tsp_melee\anim\axeBlock.rtm";};
		class tsp_melee_axeSlashRight: tsp_melee_axeReady {file = "tsp_melee\anim\axeSlashRight.rtm"; mask = "meleeLauncherSpine"; speed = 1.5; looped = false;};
		class tsp_melee_axeSlashLeft: tsp_melee_axeSlashRight {file = "tsp_melee\anim\axeSlashLeft.rtm";};
		class tsp_melee_axeSmash: tsp_melee_axeSlashLeft {file = "tsp_melee\anim\axeSmash.rtm"; speed = 1.2;};
		class tsp_melee_sledgeSlam: tsp_melee_axeSmash {file = "tsp_melee\anim\sledgeSlam.rtm";};
	};
	class BlendAnims {  //-- Masks
		meleeFist[] = {
			"Neck", 0,
			"Spine", 0,
			"Spine1", 0,
			"Spine2", 0,
			"Spine3", 0,
			"LeftShoulder", 1,
			"LeftArm", 1,
			"LeftArmRoll", 1,
			"LeftForeArm", 1,
			"LeftForeArmRoll", 1,
			"LeftHand", 1,
			"LeftHandRing", 1,
			"LeftHandPinky1", 1,
			"LeftHandPinky2", 1,
			"LeftHandPinky3", 1,
			"LeftHandRing1", 1,
			"LeftHandRing2", 1,
			"LeftHandRing3", 1,
			"LeftHandMiddle1", 1,
			"LeftHandMiddle2", 1,
			"LeftHandMiddle3", 1,
			"LeftHandIndex1", 1,
			"LeftHandIndex2", 1,
			"LeftHandIndex3", 1,
			"LeftHandThumb1", 1,
			"LeftHandThumb2", 1,
			"LeftHandThumb3", 1,
			"RightShoulder", 1,
			"RightArm", 1,
			"RightArmRoll", 1,
			"RightForeArm", 1,
			"RightForeArmRoll", 1,
			"RightHand", 1,
			"RightHandRing", 1,
			"RightHandPinky1", 1,
			"RightHandPinky2", 1,
			"RightHandPinky3", 1,
			"RightHandRing1", 1,
			"RightHandRing2", 1,
			"RightHandRing3", 1,
			"RightHandMiddle1", 1,
			"RightHandMiddle2", 1,
			"RightHandMiddle3", 1,
			"RightHandIndex1", 1,
			"RightHandIndex2", 1,
			"RightHandIndex3", 1,
			"RightHandThumb1", 1,
			"RightHandThumb2", 1,
			"RightHandThumb3", 1
		};
		meleeFistSpine[] = {
			"Neck", 0.5,
			"Spine", 0.7,
			"Spine1", 0.7,
			"Spine2", 0.8,
			"Spine3", 0.9,
			"LeftShoulder", 1,
			"LeftArm", 1,
			"LeftArmRoll", 1,
			"LeftForeArm", 1,
			"LeftForeArmRoll", 1,
			"LeftHand", 1,
			"LeftHandRing", 1,
			"LeftHandPinky1", 1,
			"LeftHandPinky2", 1,
			"LeftHandPinky3", 1,
			"LeftHandRing1", 1,
			"LeftHandRing2", 1,
			"LeftHandRing3", 1,
			"LeftHandMiddle1", 1,
			"LeftHandMiddle2", 1,
			"LeftHandMiddle3", 1,
			"LeftHandIndex1", 1,
			"LeftHandIndex2", 1,
			"LeftHandIndex3", 1,
			"LeftHandThumb1", 1,
			"LeftHandThumb2", 1,
			"LeftHandThumb3", 1,
			"RightShoulder", 1,
			"RightArm", 1,
			"RightArmRoll", 1,
			"RightForeArm", 1,
			"RightForeArmRoll", 1,
			"RightHand", 1,
			"RightHandRing", 1,
			"RightHandPinky1", 1,
			"RightHandPinky2", 1,
			"RightHandPinky3", 1,
			"RightHandRing1", 1,
			"RightHandRing2", 1,
			"RightHandRing3", 1,
			"RightHandMiddle1", 1,
			"RightHandMiddle2", 1,
			"RightHandMiddle3", 1,
			"RightHandIndex1", 1,
			"RightHandIndex2", 1,
			"RightHandIndex3", 1,
			"RightHandThumb1", 1,
			"RightHandThumb2", 1,
			"RightHandThumb3", 1
		};
		meleeRifle[] = {
			"Weapon", 1,
			"Neck", 0,
			"Spine", 0,
			"Spine1", 0,
			"Spine2", 0,
			"Spine3", 0
		};
		meleeRifleSpine[] = {
			"Weapon", 1,
			"Neck", 0.5,
			"Spine", 0.7,
			"Spine1", 0.7,
			"Spine2", 0.8,
			"Spine3", 0.9
		};		
		meleeRifleSpineHeavy[] = {
			"Weapon", 1,
			"Neck", 0.5,
			"Spine", 0.85,
			"Spine1", 0.85,
			"Spine2", 0.85,
			"Spine3", 0.85
		};
		meleePistol[] = {
			"Neck", 0,
			"Spine", 0,
			"Spine1", 0,
			"Spine2", 0,
			"Spine3", 0,
			"LeftShoulder", 1,
			"LeftArm", 1,
			"LeftArmRoll", 1,
			"LeftForeArm", 1,
			"LeftForeArmRoll", 1,
			"LeftHand", 1,			
			"RightShoulder", 1,
			"RightArm", 1,
			"RightArmRoll", 1,
			"RightForeArm", 1,
			"RightForeArmRoll", 1,
			"RightHand", 1,
		};
		meleePistolBlock[] = {
			"Neck", 0,
			"Spine", 0,
			"Spine1", 0,
			"Spine2", 0,
			"Spine3", 0,
			"LeftShoulder", 1,
			"LeftArm", 1,
			"LeftArmRoll", 1,
			"LeftForeArm", 1,
			"LeftForeArmRoll", 1,
			"LeftHand", 1,
			"LeftHandRing", 1,
			"LeftHandPinky1", 1,
			"LeftHandPinky2", 1,
			"LeftHandPinky3", 1,
			"LeftHandRing1", 1,
			"LeftHandRing2", 1,
			"LeftHandRing3", 1,
			"LeftHandMiddle1", 1,
			"LeftHandMiddle2", 1,
			"LeftHandMiddle3", 1,
			"LeftHandIndex1", 1,
			"LeftHandIndex2", 1,
			"LeftHandIndex3", 1,
			"LeftHandThumb1", 1,
			"LeftHandThumb2", 1,
			"LeftHandThumb3", 1,
			"RightShoulder", 1,
			"RightArm", 1,
			"RightArmRoll", 1,
			"RightForeArm", 1,
			"RightForeArmRoll", 1,
			"RightHand", 1
		};
		meleePistolSpine[] = {
			"Neck", 0.5,
			"Spine", 0.7,
			"Spine1", 0.7,
			"Spine2", 0.8,
			"Spine3", 0.9,
			"LeftShoulder", 1,
			"LeftArm", 1,
			"LeftArmRoll", 1,
			"LeftForeArm", 1,
			"LeftForeArmRoll", 1,
			"LeftHand", 1,			
			"RightShoulder", 1,
			"RightArm", 1,
			"RightArmRoll", 1,
			"RightForeArm", 1,
			"RightForeArmRoll", 1,
			"RightHand", 1,
		};
		meleePistolSpineHeavy[] = {
			"Neck", 0.5,
			"Spine", 1,
			"Spine1", 1,
			"Spine2", 1,
			"Spine3", 1,
			"LeftShoulder", 1,
			"LeftArm", 1,
			"LeftArmRoll", 1,
			"LeftForeArm", 1,
			"LeftForeArmRoll", 1,
			"LeftHand", 1,			
			"RightShoulder", 1,
			"RightArm", 1,
			"RightArmRoll", 1,
			"RightForeArm", 1,
			"RightForeArmRoll", 1,
			"RightHand", 1,
		};
		meleeKnife[] = {
			"Neck", 0.1,
			"Spine", 0.2,
			"Spine1", 0.3,
			"Spine2", 0.4,
			"Spine3", 0.5,
			"LeftShoulder", 1,
			"LeftArm", 1,
			"LeftArmRoll", 1,
			"LeftForeArm", 1,
			"LeftForeArmRoll", 1,
			"LeftHand", 1,
			"LeftHandRing", 1,
			"LeftHandPinky1", 1,
			"LeftHandPinky2", 1,
			"LeftHandPinky3", 1,
			"LeftHandRing1", 1,
			"LeftHandRing2", 1,
			"LeftHandRing3", 1,
			"LeftHandMiddle1", 1,
			"LeftHandMiddle2", 1,
			"LeftHandMiddle3", 1,
			"LeftHandIndex1", 1,
			"LeftHandIndex2", 1,
			"LeftHandIndex3", 1,
			"LeftHandThumb1", 1,
			"LeftHandThumb2", 1,
			"LeftHandThumb3", 1,
			"RightShoulder", 1,
			"RightArm", 1,
			"RightArmRoll", 1,
			"RightForeArm", 1,
			"RightForeArmRoll", 1,
			"RightHand", 1,
			"RightHandRing", 1,
			"RightHandPinky1", 1,
			"RightHandPinky2", 1,
			"RightHandPinky3", 1,
			"RightHandRing1", 1,
			"RightHandRing2", 1,
			"RightHandRing3", 1,
			"RightHandMiddle1", 1,
			"RightHandMiddle2", 1,
			"RightHandMiddle3", 1,
			"RightHandIndex1", 1,
			"RightHandIndex2", 1,
			"RightHandIndex3", 1,
			"RightHandThumb1", 1,
			"RightHandThumb2", 1,
			"RightHandThumb3", 1
		};
		meleeKnifeSpine[] = {
			"Neck", 0.5,
			"Spine", 0.7,
			"Spine1", 0.7,
			"Spine2", 0.8,
			"Spine3", 0.9,
			"LeftShoulder", 1,
			"LeftArm", 1,
			"LeftArmRoll", 1,
			"LeftForeArm", 1,
			"LeftForeArmRoll", 1,
			"LeftHand", 1,
			"LeftHandRing", 1,
			"LeftHandPinky1", 1,
			"LeftHandPinky2", 1,
			"LeftHandPinky3", 1,
			"LeftHandRing1", 1,
			"LeftHandRing2", 1,
			"LeftHandRing3", 1,
			"LeftHandMiddle1", 1,
			"LeftHandMiddle2", 1,
			"LeftHandMiddle3", 1,
			"LeftHandIndex1", 1,
			"LeftHandIndex2", 1,
			"LeftHandIndex3", 1,
			"LeftHandThumb1", 1,
			"LeftHandThumb2", 1,
			"LeftHandThumb3", 1,
			"RightShoulder", 1,
			"RightArm", 1,
			"RightArmRoll", 1,
			"RightForeArm", 1,
			"RightForeArmRoll", 1,
			"RightHand", 1,
			"RightHandRing", 1,
			"RightHandPinky1", 1,
			"RightHandPinky2", 1,
			"RightHandPinky3", 1,
			"RightHandRing1", 1,
			"RightHandRing2", 1,
			"RightHandRing3", 1,
			"RightHandMiddle1", 1,
			"RightHandMiddle2", 1,
			"RightHandMiddle3", 1,
			"RightHandIndex1", 1,
			"RightHandIndex2", 1,
			"RightHandIndex3", 1,
			"RightHandThumb1", 1,
			"RightHandThumb2", 1,
			"RightHandThumb3", 1
		};
		meleeLauncher[] = {
			"Launcher", 1,
			"Neck", 0,
			"Spine", 0,
			"Spine1", 0,
			"Spine2", 0,
			"Spine3", 0
		};
		meleeLauncherSpine[] = {
			"Launcher", 1,
			"Neck", 0.5,
			"Spine", 1,
			"Spine1", 1,
			"Spine2", 1,
			"Spine3", 1
		};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic {
    class States {  //-- Animations
        class CutSceneAnimationBase;

		//-- Kick
        class tsp_melee_fistKick: CutSceneAnimationBase {
			forceAim = 0;
			weaponIK = 0;
			canReload = false;
			head = "headDefault";
			speed = 1.5;	
			interpolationSpeed = 5;			
			file = "tsp_melee\anim\fistKick.rtm";
			InterpolateTo[] = {"AmovPercMstpSnonWnonDnon", 1, "AmovPercMstpSnonWnonDnon", 1};
			InterpolateFrom[] = {"AmovPercMstpSnonWnonDnon", 1, "AmovPercMstpSnonWnonDnon", 1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
			looped = false;
		};
        class tsp_melee_rifleKick: tsp_melee_fistKick {
			weaponIK = 1; file = "tsp_melee\anim\rifleKick.rtm"; 
			InterpolateTo[] = {"AmovPercMstpSrasWrflDnon", 1, "AmovPknlMstpSrasWrflDnon", 1};
			InterpolateFrom[] = {"AmovPercMstpSrasWrflDnon", 1, "AmovPknlMstpSrasWrflDnon", 1};
		};
        class tsp_melee_pistolKick: tsp_melee_fistKick {
			weaponIK = 0; showHandgun = true; 
			InterpolateTo[] = {"AmovPercMstpSrasWpstDnon", 1, "AmovPknlMstpSrasWpstDnon", 1};
			InterpolateFrom[] = {"AmovPercMstpSrasWpstDnon", 1, "AmovPknlMstpSrasWpstDnon", 1};
		};
		class tsp_melee_axeKick: tsp_melee_fistKick {
			weaponIK = 4; 
			InterpolateTo[] = {"AmovPercMstpSrasWlnrDnon", 1, "AmovPknlMstpSrasWlnrDnon", 1};
			InterpolateFrom[] = {"AmovPercMstpSrasWlnrDnon", 1, "AmovPknlMstpSrasWlnrDnon", 1};
		};

		//-- Dodge
        class tsp_melee_fist_dodge_left: tsp_melee_fistKick {speed = 2; file = "tsp_melee\anim\dodgeLeft.rtm";};
        class tsp_melee_rifle_dodge_left: tsp_melee_rifleKick {speed = 2; file = "tsp_melee\anim\dodgeLeft.rtm";};
        class tsp_melee_pistol_dodge_left: tsp_melee_pistolKick {speed = 2; file = "tsp_melee\anim\dodgeLeft.rtm";};
		class tsp_melee_axe_dodge_left: tsp_melee_axeKick {speed = 2; file = "tsp_melee\anim\dodgeLeft.rtm";};
		class tsp_melee_fist_dodge_right: tsp_melee_fist_dodge_left {file = "tsp_melee\anim\dodgeRight.rtm";};
		class tsp_melee_rifle_dodge_right: tsp_melee_rifle_dodge_left {file = "tsp_melee\anim\dodgeRight.rtm";};
		class tsp_melee_pistol_dodge_right: tsp_melee_pistol_dodge_left {file = "tsp_melee\anim\dodgeRight.rtm";};
		class tsp_melee_axe_dodge_right: tsp_melee_axe_dodge_left {file = "tsp_melee\anim\dodgeRight.rtm";};

		//-- Stun
		class tsp_melee_fistStun: tsp_melee_fistKick {interpolationSpeed = 5; speed = 3; file = "tsp_melee\anim\fistStun.rtm";};
		class tsp_melee_rifleStun: tsp_melee_rifleKick {interpolationSpeed = 5;	speed = 3; file = "tsp_melee\anim\rifleStun.rtm"; leftHandIKCurve[] = {0};};
        class tsp_melee_pistolStun: tsp_melee_pistolKick {interpolationSpeed = 5; speed = 3; file = "tsp_melee\anim\fistStun.rtm"; leftHandIKCurve[] = {0};};

		//-- Special
        class tsp_melee_fistAttacker: tsp_melee_fistKick {speed = 0.35; file = "tsp_melee\anim\fistAttacker.rtm";};
        class tsp_melee_fistVictim: tsp_melee_fistAttacker {file = "tsp_melee\anim\fistVictim.rtm"; InterpolateTo[] = {"Unconscious", 1}; ignoreMinPlayTime[] = {"Unconscious"};};
        class tsp_melee_knifeDownAttacker: tsp_melee_pistolKick {speed = 0.55; file = "tsp_melee\anim\knifeDownAttacker.rtm";};
        class tsp_melee_knifeUpAttacker: tsp_melee_knifeDownAttacker {file = "tsp_melee\anim\knifeUpAttacker.rtm";};
        class tsp_melee_knifeVictim: tsp_melee_knifeDownAttacker {file = "tsp_melee\anim\knifeVictim.rtm"; InterpolateTo[] = {"Unconscious", 1}; ignoreMinPlayTime[] = {"Unconscious"};};
	};
};