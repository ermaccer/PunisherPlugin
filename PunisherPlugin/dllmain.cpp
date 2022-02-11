// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "MemoryMgr.h"
#include "code/eSettingsManager.h"


using namespace Memory::VP;

void Init()
{
	eSettingsManager::Init();

	if (eSettingsManager::bDisableNegativePoints)
		Patch<float>(0x4BA9B2 + 4, -2.0f);

	if (eSettingsManager::bEnableDualWieldingAnyWeapon)
	{
		// enable picking up anything
		Nop(0x4DB7C0, 6);
		// force pick up text
		Nop(0x4C02B6, 3);
	}

	if (eSettingsManager::bDisableBlackWhiteFilterOnKills)
		Patch<char>(0x4D84EB + 6, 0);
}

bool CheckExecutable()
{
	char* name = (char*)(0x605AC0);

	if (strcmp(name, "VolitionPunisher") == 0)
		return true;
	else
	{
		MessageBoxA(0, "Invalid executable!", "PunisherPlugin", MB_ICONINFORMATION);
		return false;
	}

}


extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		if (CheckExecutable())
		{
			Init();
		}
	}
}