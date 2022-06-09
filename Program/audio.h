#ifndef GD_AUDIO_H_
#define	GD_AUDIO_H_

#include "definitions.h"
 //#include "audio/Multi_Buffer.h"

 //class Sms_Apu;
 //class Sound_Queue;

class Audio
{
public:
	Audio();
	~Audio();
	void Init();
	void Reset();
	void Enable(bool enabled);
	bool IsEnabled() const;
	void SetSampleRate(int rate);
	void WriteAudioRegister(u8 value);
	void WriteGGStereoRegister(u8 value);
	void EndFrame();
	void Tick(unsigned int clock_cycles);

private:
	bool enabled_;
	//    Sms_Apu* m_pApu;
	//    Stereo_Buffer* m_pBuffer;
	//    long m_Time;
	//    Sound_Queue* m_pSound;
	//    int m_iSampleRate;
	//    blip_sample_t* m_pSampleBuffer;
};

const long kSampleBufferSize = 8192;

#endif // GD_AUDIO_H_
