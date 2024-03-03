#ifndef PULSEWIDTHMODULATIONOSCILLATOR_H
#define PULSEWIDTHMODULATIONOSCILLATOR_H

#include "Oscillator.h"

class PulseWidthModulationOscillator : public Oscillator
{
public:
    PulseWidthModulationOscillator(float freq, float amp);
    ~PulseWidthModulationOscillator();

    float process() override;
};

#endif
