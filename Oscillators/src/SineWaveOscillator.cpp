#define _USE_MATH_DEFINES
#include "include/Oscillator.h"

#include <cmath>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#ifndef M_PIl
#define M_PIl (3.14159265358979323846264338327950288)
#endif
const float SAMPLE_RATE = 44100.0f;

class SineWaveOscillator : public Oscillator
{
protected:
    float frequency, amplitude, angle = 0.0f, offset = 0.0f;

public:
    SineWaveOscillator(float freq, float amp) : Oscillator(freq, amp)
    {
        offset = 2 * M_PI * frequency / SAMPLE_RATE;
    }

    // generate the next sample value called at every sampling interval, so it needs to be fast
    float process()
    {
        float sample = amplitude * sin(angle);
        angle += offset;
        return sample;
        // Asin(2pif/sr)
    }
};