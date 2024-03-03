#ifndef TRIANGLEWAVEOSCILLATOR_H
#define TRIANGLEWAVEOSCILLATOR_H

#include "Oscillator.h"

class TriangleWaveOscillator : public Oscillator
{
public:
    TriangleWaveOscillator(float freq, float amp);
    ~TriangleWaveOscillator();

    float process() override;
};

#endif
