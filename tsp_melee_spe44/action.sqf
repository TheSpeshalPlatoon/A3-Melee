if (tsp_cba_melee_spe44) exitWith {false};

params ["_unit"];
private _lifeState = lifeState _unit;
private _muzzle = currentWeaponMode _unit; 

inputaction "defaultaction" > 0 
&& (_lifeState in ["HEALTHY", "INJURED"]) 
&& {
	_muzzle == "SPE_Bayonet_Muzzle" 
	&& !(_unit getVariable ["SPE_Bayonet_IsStabbing", false]) 
	&& !(weaponLowered _unit) 
	&& stance _unit != "PRONE" 
	&& !visibleMap 
	&& cameraOn == vehicle _unit 
	&& !dialog
	&& (isNull (uiNamespace getVariable ["BIS_fnc_arsenal_cam", objNull])) 
	&& (isNull (uiNamespace getVariable ["ace_arsenal_camera", objNull])) 
	&& {(missionNamespace getVariable ["SPE_ACE_AllowBayonet", true])}
}