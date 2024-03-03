

class Oscillator
{
protected:
    float frequency, amplitude, angle = 0.0f, offset = 0.0f;

public:
    Oscillator(float freq, float amp) : frequency(freq), amplitude(amp) {}

    ~Oscillator() {}

    float process() { return 0; }
};