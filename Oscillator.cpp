#define _USE_MATH_DEFINES

#include <cmath>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#ifndef M_PIl
#define M_PIl (3.14159265358979323846264338327950288)
#endif

const float SAMPLE_RATE = 44100.0f; // Assuming a sample rate of 44.1 kHz

class Oscillator
{
protected:
    float frequency, amplitude, angle = 0.0f, offset = 0.0f;

public:
    Oscillator(float freq, float amp) : frequency(freq), amplitude(amp)
    {
        offset = 2 * M_PI * frequency / SAMPLE_RATE;
    }

    virtual ~Oscillator() {}

    virtual float process() = 0;
};