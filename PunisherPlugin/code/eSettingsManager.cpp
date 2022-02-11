#include "eSettingsManager.h"
#include "..\IniReader.h"


bool eSettingsManager::bDisableNegativePoints;
bool eSettingsManager::bEnableDualWieldingAnyWeapon;
bool eSettingsManager::bDisableBlackWhiteFilterOnKills;

void eSettingsManager::Init()
{
	CIniReader reader("");
	bDisableNegativePoints  = reader.ReadBoolean("Settings", "bDisableNegativePoints", true);
	bEnableDualWieldingAnyWeapon = reader.ReadBoolean("Settings", "bEnableDualWieldingAnyWeapon", false);
	bDisableBlackWhiteFilterOnKills = reader.ReadBoolean("Settings", "bDisableBlackWhiteFilterOnKills", true);
}
