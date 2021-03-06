#ifndef GD_CARTRIDGE_H_
#define	GD_CARTRIDGE_H_

#include "definitions.h"

class Cartridge
{
public:
	enum CartridgeTypes
	{
		CartridgeRomOnlyMapper,
		CartridgeSegaMapper,
		CartridgeCodemastersMapper,
		CartridgeNotSupported
	};
	enum CartridgeZones
	{
		CartridgeJapanSMS,
		CartridgeExportSMS,
		CartridgeJapanGG,
		CartridgeExportGG,
		CartridgeInternationalGG,
		CartridgeUnknownZone
	};

public:
	Cartridge();
	~Cartridge();
	void Init();
	void Reset();
	bool IsGameGear() const;
	bool IsPAL() const;
	bool IsValidROM() const;
	bool IsReady() const;
	bool HasRAMWithoutBattery() const;
	CartridgeTypes GetType() const;
	CartridgeZones GetZone() const;
	void ForzeZone(CartridgeZones zone);
	int GetROMSize() const;
	int GetROMBankCount() const;
	const char* GetFilePath() const;
	const char* GetFileName() const;
	u8* GetROM() const;
	bool LoadFromFile(const char* path);
	bool LoadFromBuffer(const u8* buffer, int size);

private:
	unsigned int Pow2Ceil(u16 n);
	bool GatherMetadata(u32 crc);
	bool LoadFromZipFile(const u8* buffer, int size);
	bool TestValidROM(u16 location);

private:
	u8* m_pROM;
	int m_iROMSize;
	CartridgeTypes m_Type;
	CartridgeZones m_Zone;
	bool m_bValidROM;
	bool m_bReady;
	char m_szFilePath[512];
	char m_szFileName[512];
	int m_iROMBankCount;
	bool m_bGameGear;
	bool m_bPAL;
	bool m_bRAMWithoutBattery;
};

#endif // GD_CARTRIDGE_H_
