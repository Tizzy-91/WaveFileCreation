#ifndef SINEOSCILLATOR_H
#define SINEOSCILLATOR_H

#include "Oscillator.h"

class SineWaveOscillator : public Oscillator
{
public:
    SineWaveOscillator(float freq, float amp);
    ~SineWaveOscillator();

    float process() override;
};

#endif
