#ifndef SQUAREWAVEOSCILLATOR_H
#define SQUAREWAVEOSCILLATOR_H

#include "Oscillator.h"

class SquareWaveOscillator : public Oscillator
{
public:
    SquareWaveOscillator(float freq, float amp);
    ~SquareWaveOscillator();

    float process() override;
};

#endif
