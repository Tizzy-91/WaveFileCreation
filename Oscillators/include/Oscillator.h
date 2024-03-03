#ifndef OSCILLATOR_H
#define OSCILLATOR_H

class Oscillator
{
protected:
    float frequency, amplitude, angle = 0.0f, offset = 0.0f;

public:
    Oscillator(float freq, float amp);
    virtual ~Oscillator();

    virtual float process() = 0;
};

#endif
