class CfgPatches {
	class tsp_melee_training {
		requiredAddons[] = {"tsp_melee", "tsp_core"};
		units[] = {};
	};
};

class CfgMelee {
	class knifeUp;
	class variant_base;
	class variant_base_block;
	class knifeTraining: knifeUp {
		moveset = "knife";
		class main {
			class variant: variant_base {
				gesture = "tsp_melee_knifeSlashLeft"; 
				manDamage = 0; 
				manDamageType = "stab";
				manProjectile = "";
				manSound[] = {{"tsp_melee\snd\impact1.ogg", 2}, {"tsp_melee\snd\impact1.ogg", 2}};	
				manKnockoutChance = 0; 
				manKnockoutSound[] = {{"tsp_melee\snd\impact1.ogg", 2}};			
				manStunChance = 0.5; 
				manDisarmChance = 0.5; 
				impactTime = 0.15;
				restTime = 0.1;
				afterTime = 0.05;
				objectProjectile = "";
			};
			class variant1: variant {gesture = "tsp_melee_knifeUpSlashRight";};
		};
		class alt {
			class variant: variant_base {
				gesture = "tsp_melee_knifeUpStab"; 
				stamina = 20;
				manDamage = 0;
				manDamageType = "stab";
				manProjectile = "";
				manSound[] = {{"tsp_melee\snd\impact1.ogg", 1}}; 
				manKnockoutChance = 0; 
				manKnockoutSound[] = {{"tsp_melee\snd\impact1.ogg", 1}};
				manStunChance = 0.75;
				manDisarmChance = 0.75;
				swingTime = 0.4; 
				restTime = 0.25; 
				afterTime = 0.3; 
				objectProjectile = "";
				manSpecialCondition = "false";
				manSpecialCode = "";
			};
		};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_knifeUp;
	class tsp_meleeWeapon_training: tsp_meleeWeapon_knifeUp {
		scope = 2;
		meleeType = "knifeTraining";
		model = "tsp_melee_training\training.p3d";
		picture = "\tsp_melee_training\gui\ui.paa";
		displayname = "Rubber Training Knife";
		descriptionShort = "Rubber verson of the USMC KA-BAR";
		class WeaponSlotsInfo {mass = 2; holsterScale = 0;};
	};
};

