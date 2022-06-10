#ifndef GD_VIDEO_H_
#define	GD_VIDEO_H_

#include "definitions.h"

#define GD_GEN_WIDTH 320
#define GD_GEN_HEIGHT 224
#define VDP_READ_VRAM_OPERATION 0x00
#define VDP_WRITE_VRAM_OPERATION 0x01
#define VDP_WRITE_REG_OPERATION 0x02
#define VDP_WRITE_CRAM_OPERATION 0x03

struct GD_Color
{
	u8 red;
	u8 green;
	u8 blue;
	u8 alpha;
};

class Video
{
public:
	Video();
	~Video();
	void Init();
	void Reset(bool is_pal);
	bool Tick(unsigned int clock_cycles, GD_Color* frame_buffer);
	u8 GetVCounter();
	u8 GetHCounter();
	u8 GetDataPort();
	u8 GetStatusFlags();
	void WriteData(u8 data);
	void WriteControl(u8 control);
	void LatchHCounter();

private:
	void ScanLine(int line);
};

#endif // GD_VIDEO_H_
