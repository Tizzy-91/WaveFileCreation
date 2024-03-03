#ifndef SAWTOOTHOSCILLATOR_H
#define SAWTOOTHOSCILLATOR_H

#include "Oscillator.h"

class SawtoothOscillator : public Oscillator
{
public:
    SawtoothOscillator(float freq, float amp);
    ~SawtoothOscillator();

    float process() override;
};

#endif
