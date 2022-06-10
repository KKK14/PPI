#include "Video.h"

Video::Video()
{

}

Video::~Video()
{

}

void Video::Init()
{
	Reset(false);
}

void Video::Reset(bool is_pal)
{

}

bool Video::Tick(unsigned int clock_cycles, GD_Color* frame_buffer)
{
	return true;
}

void Video::LatchHCounter()
{

}

u8 Video::GetVCounter()
{
	return 0;
}

u8 Video::GetHCounter()
{
	return 0;
}

u8 Video::GetDataPort()
{
	return 0;
}

u8 Video::GetStatusFlags()
{
	return 0;
}

void Video::WriteData(u8 data)
{

}

void Video::WriteControl(u8 control)
{

}

void Video::ScanLine(int line)
{

}