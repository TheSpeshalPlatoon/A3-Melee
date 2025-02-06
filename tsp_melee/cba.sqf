//-- CONTROLS	
	[  //-- Toggle
		["TSP Core", "Melee"], "tsp_melee_meleeKeyHold", "Melee (Hold)",
		{if (tsp_cba_melee && playa call tsp_fnc_melee_can && [playa] call tsp_fnc_melee_weapon != "") then {[playa, "ready"] spawn tsp_fnc_melee_action}}, 
		{if (playa call tsp_fnc_melee_doing) then {[playa] call tsp_fnc_gesture_stop}},
		[0, [false, false, false]]
	] call CBA_fnc_addKeybind;	

	[  //-- Toggle
		["TSP Core", "Melee"], "tsp_melee_meleeKeyToggle", "Melee (Toggle)",
		{
			if (playa call tsp_fnc_melee_doing) exitWith {[playa] call tsp_fnc_gesture_stop};		  
			if (tsp_cba_melee && playa call tsp_fnc_melee_can && [playa] call tsp_fnc_melee_weapon != "") then {[playa, "ready"] spawn tsp_fnc_melee_action};
		}, {},
		[0, [false, false, false]]
	] call CBA_fnc_addKeybind;
	
	[  //-- Double tap, toggle
		["TSP Core", "Melee"], "tsp_melee_meleeKeyDoubleTapToggle", "Melee (Double Tap, Toggle)",
		{
			if (playa call tsp_fnc_melee_doing) exitWith {[playa] call tsp_fnc_gesture_stop};		  
			if (isNil "tsp_melee_firstTap") exitWith {[] spawn {tsp_melee_firstTap = true; sleep 0.3; tsp_melee_firstTap = nil}};  //-- Double tap
			if (tsp_cba_melee && playa call tsp_fnc_melee_can && [playa] call tsp_fnc_melee_weapon != "") then {[playa, "ready"] spawn tsp_fnc_melee_action};
		}, {},
		[33, [false, false, false]]
	] call CBA_fnc_addKeybind;
	
	[["TSP Core", "Melee"], "tsp_melee_main", "Main", {if (playa call tsp_fnc_melee_doing) then {[playa, "main"] spawn tsp_fnc_melee_action}}, {}, [0xF0, [false, false, false]]] call CBA_fnc_addKeybind;
	[["TSP Core", "Melee"], "tsp_melee_alt", "Alternate", {if (playa call tsp_fnc_melee_doing) then {[playa, "alt"] spawn tsp_fnc_melee_action}}, {}, [0xF1, [false, false, false]]] call CBA_fnc_addKeybind;
	[["TSP Core", "Melee"], "tsp_melee_kick", "Kick", {
		if (playa call tsp_fnc_melee_doing) then {["", false] spawn tsp_fnc_scroll; [] spawn {sleep 1; ["", true] spawn tsp_fnc_scroll}};  //-- Hide scroll when kicking
		if (playa call tsp_fnc_melee_doing) then {[playa, "kick"] spawn tsp_fnc_melee_action};
	}, {}, [0xF9, [false, false, false]]] call CBA_fnc_addKeybind;
	[["TSP Core", "Melee"], "tsp_melee_block", "Block", {if (playa call tsp_fnc_melee_doing) then {[playa, "block"] spawn tsp_fnc_melee_action}}, {if (playa call tsp_fnc_melee_doing) then {[playa, "ready"] spawn tsp_fnc_melee_action}}, [0x1F, [false, false, false]]] call CBA_fnc_addKeybind;
	[["TSP Core", "Melee"], "tsp_melee_special", "Special", {if (playa call tsp_fnc_melee_doing) then {[playa, "special"] spawn tsp_fnc_melee_action}}, {}, [0xF0, [true, false, false]]] call CBA_fnc_addKeybind;
	[["TSP Core", "Melee"], "tsp_melee_dodge_left", "Dodge (Left)", {if (playa call tsp_fnc_melee_doing) then {[playa, "dodge_left"] spawn tsp_fnc_melee_action}}, {}, [16, [false, false, false]]] call CBA_fnc_addKeybind;
	[["TSP Core", "Melee"], "tsp_melee_dodge_right", "Dodge (Right)", {if (playa call tsp_fnc_melee_doing) then {[playa, "dodge_right"] spawn tsp_fnc_melee_action}}, {}, [18, [false, false, false]]] call CBA_fnc_addKeybind;

//-- SETTINGS
    ["tsp_cba_melee", "CHECKBOX", ["Enable Melee", "Enables melee mode activation."], "TSP Melee", true, true] call CBA_fnc_addSetting;
	["tsp_cba_melee_damage", "SLIDER", ["Damage Modifier", "Damage applied is multiplied by this value."], "TSP Melee", [0, 10, 1], true] call CBA_fnc_addSetting;     //-- Damage Modifier
	["tsp_cba_melee_disarm", "SLIDER", ["Disarm Modifier", "Change of disarm is multiplied by this value."], "TSP Melee", [0, 10, 1], true] call CBA_fnc_addSetting;  //-- Stamina Modifier
	["tsp_cba_melee_stamina", "SLIDER", ["Stamina Modifier", "Stamina used is multiplied by this value."], "TSP Melee", [0, 10, 1], true] call CBA_fnc_addSetting;   //-- Stamina Modifier
	["tsp_cba_melee_speed", "SLIDER", ["Sprint Speed", "Speeds higher than this will not allow melee."], "TSP Melee", [0, 25, 15], true] call CBA_fnc_addSetting;   //-- sPRINT