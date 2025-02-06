## Creating your own Melee Weapons
You can create melee weapons in 2 ways. 

If you just want to make a new weapon that acts like one of the melee weapons already included in the base mod, you can use an [inherited config](#inherited-config).

If you want to completely customize your weapon with custom animations, damage, etc, you can use a [custom config](#custom-config).

---
### Inherited Config
You can easily create your own melee weapons/attachments by inheriting some of the base weapons from CfgWeapons that come with the mod:
- tsp_meleeWeapon_knifeUp  
- tsp_meleeWeapon_knifeDown  
- tsp_meleeWeapon_bipod (for bayonets)  
- tsp_meleeWeapon_pointer (for bayonets)
- tsp_meleeWeapon_axe

The example below shows how to create a knife and corresponding bayonet by simply inheriting one of the base weapons.
```cpp 
class CfgWeapons {
	class tsp_meleeWeapon_knifeDown;
	class tsp_meleeWeapon_m9: tsp_meleeWeapon_knifeDown {
		scope = 2;
		model = "tsp_melee_m9\m9.p3d";
		picture = "\tsp_melee_m9\gui\ui.paa";
		displayname = "M9 Bayonet";
		descriptionShort = "US Army standard issue bayonet";
	};
	class tsp_meleeWeapon_bipod;
	class tsp_meleeWeapon_m9_bipod: tsp_meleeWeapon_bipod {
		scope = 2;
		displayname = "M9 Bayonet";
		descriptionShort = "US Army standard issue bayonet";
		model = "tsp_melee_m9\m9bipod.p3d";
		picture = "\tsp_melee_m9\gui\ui.paa";
	};
};
```
---
### Custom Config
A melee weapon consists of 2 parts: a CfgMelee class and a CfgWeapons class. The CfgMelee class defines the actual melee animations, damage, sound etc. The CfgWeapons class only contains the idle animation and some other entries to make it act like a melee weapon instead of a gun.

If you want to completely customize your melee weapon, this can be done by adding a config values to the weapon's CfgWeapons class as well as in the CfgMelee class. An example can be seen below:

**CfgMelee:**
```cpp
class CfgMelee {
	class default;
	class myKnifeMelee: default {
		movesetRest = "knife";      //-- Moveset when not in melee mode, just holding weapon (can be default/knife)
		movesetReady = "default";  //-- Moveset when in melee mode (can be default/knife)
		class ready {
			class v1 {  //-- You can have v1, v2, v3, etc. Which is used is selected randomly
				animation[] = {"Gesture", "tsp_melee_knifeReadyUp"};  //-- Animation/Gesture, classname
			};
		};
		class block {
			class v1 {
				animation[] = {"Gesture", "tsp_melee_knifeBlock"};  //-- Animation/Gesture, classname
				timing[] = {0, 0, 1.2};  //-- Time to swing, time to impact, total duration
				blockableDamage[] = {
					{"punch", 0.8, "tsp_melee\snd\impact1.ogg"},  //-- Type, effectiveness, sound
					{"stab", 0.5, "tsp_melee\snd\slice1.ogg"}  //-- Type, effectiveness, sound
				};
			};                     
		};
		class main {
			class v1 {
				animation[] = {"Gesture", "tsp_melee_knifeSlashUp"};  //-- Animation/Gesture, classname
				damage[] = {"stab", {0.4, 0.5, 0.6}, 1};  //-- Type, quantity, knockout chance
				environmentDamage[] = {0.6, 0.05, 0, 0, 0};  //-- Window, door, reinforced door, military door, wall
				reach = 1.5;  //-- How far attack can reach
				angle = 70;  //-- Cone of fire
				timing[] = {0.1, 0.4, 0.5};  //-- Time to swing, time to impact, total duration
				soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
				soundImpact[] = {"tsp_melee\snd\stab1.ogg","tsp_melee\snd\stab2.ogg"};
				soundKnockout[] = {"tsp_melee\snd\stab3.ogg"};
				hitEffects[] = {"tsp_meleeBulletGlass","tsp_meleeBulletFlesh"};  //-- Glass, man
			};
		};
		class alt {
			class v1 {
				animation[] = {"Gesture", "tsp_melee_knifeStabUp"};
				damage[] = {"stab", {0.6, 0.7, 0.8}, 1};
				environmentDamage[] = {0.6, 0.05, 0, 0, 0};
				reach = 1.5;
				angle = 60;
				timing[] = {0.3, 0.5, 0.6};
				soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
				soundImpact[] = {"tsp_melee\snd\stab1.ogg","tsp_melee\snd\stab2.ogg"};
				soundKnockout[] = {"tsp_melee\snd\stab3.ogg"};
				hitEffects[] = {"tsp_meleeBulletGlass","tsp_meleeBulletFlesh"};
			};
		};
		class kick {
			class v1 {
				animation[] = {"Animation", "tsp_melee_knifeKick"};
				damage[] = {"punch", {0.3, 0.4, 0.5}, 0.5};
				environmentDamage[] = {1, 0.75, 0.1, 0.05, 0};
				reach = 2;
				angle = 50;
				timing[] = {0, 0.25, 0.6};
				soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
				soundImpact[] = {"tsp_melee\snd\impact1.ogg"};
				soundKnockout[] = {"tsp_melee\snd\knockout1.ogg"};
				hitEffects[] = {"tsp_meleeBulletGlass",""};
			};
		};
	};
};
```

**CfgWeapons:**
```cpp
class CfgWeapons {
	class Pistol_Base_F;
	class myKnifeWeapon: Pistol_Base_F {
		modelOptics = "";  //-- No optics
		meleeType = "myKnifeMelee";  //-- Reference to CfgMelee
		useModelOptics = true;  //-- No aiming
		fireLightIntensity = 0;  //-- No muzzle flash
		magazines[] = {};  //-- No mags
		weaponInfoType = "RscWeaponEmpty";  //-- No crosshair
		handAnim[]={"OFP2_ManSkeleton","\tsp_melee\anim\knifeWpnRestUp.rtm"};  //-- Handanim
		class WeaponSlotsInfo {mass = 10; holsterScale = 0;};  //-- Hide in holster
	};
};
```