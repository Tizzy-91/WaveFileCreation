#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#ifndef M_PIl
#define M_PIl (3.14159265358979323846264338327950288)
#endif

#define SAMPLE_RATE (44100)
#define BIT_DEPTH (16)

class SineOscillator
{
    float frequency, amplitude, angle = 0.0f, offset = 0.0f;

public:
    // we added the expression in the sine function to the constructor for optimization, we can calculate the offset, during memory allocation?
    SineOscillator(float freq, float amp) : frequency(freq), amplitude(amp)
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

void writeToFile(std::ofstream &fileHandler, int value, int size)
{
    fileHandler.write(reinterpret_cast<const char *>(&value), size);
}

int main()
{

    int duration = 2;

    std::ofstream audioFile;

    audioFile.open("waveform.wav", std::ios::binary);

    // we have the oscillator but we need to generate the sample
    SineOscillator sineOscillator(440, 0.5);

    // Header chunk
    audioFile << "RIFF";
    // this string is size, it needs to be 4 bytes
    audioFile << "----";
    audioFile << "WAVE";

    // Fomat chunk needs to have a space(or a null character)
    audioFile << "fmt ";
    writeToFile(audioFile, 16, 4);                          // Size
                                                            // Meta data
    writeToFile(audioFile, 1, 2);                           // compression code;
    writeToFile(audioFile, 1, 2);                           // Number of channels
    writeToFile(audioFile, SAMPLE_RATE, 4);                 // sample rate
    writeToFile(audioFile, SAMPLE_RATE * BIT_DEPTH / 8, 4); // Byte rate per second
    writeToFile(audioFile, BIT_DEPTH / 8, 2);               // block align, is used to determine how many bytes are avaiable to playback device at any given point in time
    writeToFile(audioFile, BIT_DEPTH, 2);                   // significant bits per sample (bit_depth)

    // Data chunk
    audioFile << "data";
    audioFile << "----";

    // record position of the pointer in the current stream before the audio data chunk
    int beforeAudioDataPosition = audioFile.tellp();

    auto maxAmplitude = pow(2, BIT_DEPTH - 1) - 1;
    // we need to generate 44100 samples to get a one second wave
    for (int i = 0; i < SAMPLE_RATE * duration; i++)
    {
        float sample = sineOscillator.process();
        int intSample = static_cast<int>(sample * maxAmplitude);

        // extract the first 2 bytes of the sample
        writeToFile(audioFile, intSample, 2);
    }

    // record position of the pointer in the current stream after the audio data chunk
    int afterAudioDataPosition = audioFile.tellp();

    // seek to a position in the audio file and then write values for size (-4 to get to the starting of the size field)
    audioFile.seekp(beforeAudioDataPosition - 4);
    writeToFile(audioFile, afterAudioDataPosition - beforeAudioDataPosition, 4);

    audioFile.seekp(4, std::ios::beg);
    writeToFile(audioFile, afterAudioDataPosition - 8, 4);

    // check how big our "word" length is in our operating system
    //  printf("size of int word size is %d\n", sizeof(int));
    //  printf("size of float word size is %d\n", sizeof(float));

    audioFile.close();
    return 0;
}