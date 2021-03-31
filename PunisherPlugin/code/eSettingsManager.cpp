#include "eSettingsManager.h"
#include "..\IniReader.h"


bool eSettingsManager::bDisableNegativePoints;
bool eSettingsManager::bEnableDualWieldingAnyWeapon;

void eSettingsManager::Init()
{
	CIniReader reader("");
	bDisableNegativePoints  = reader.ReadBoolean("Settings", "bDisableNegativePoints", false);
	bEnableDualWieldingAnyWeapon = reader.ReadBoolean("Settings", "bEnableDualWieldingAnyWeapon", false);
}
