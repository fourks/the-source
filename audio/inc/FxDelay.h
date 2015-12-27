/*
  ==============================================================================

    FxDelay.h
    Created: 30 Nov 2015 6:21:10pm
    Author:  nj

  ==============================================================================
*/

#ifndef FXDELAY_H_INCLUDED
#define FXDELAY_H_INCLUDED

#include "SynthParams.h"

class FxDelay {
public:
    FxDelay(SynthParams &p)
        : params(p)
        , loopPosition(0)
        , bpm(120)
        , divisor(0)
        , dividend(0)
        , lastSample(0.f)
        , inputDelay1(0.f)
        , inputDelay2(0.f)
        , outputDelay1(0.f)
        , outputDelay2(0.f)
        , delayBuffer()
        , maxDelayLength(5000)
    {}
    ~FxDelay(){}
    
    void render(AudioSampleBuffer& outputBuffer, int startSample, int numSamplesIn);
    void init(int channelsIn, double sampleRateIn);

private:
    void calcTime();
    float filter(float inputSignal);
    SynthParams &params;
    AudioSampleBuffer delayBuffer;
    double sampleRate;
    int channels;
    int loopPosition;
    int currentDelayLength;
    int maxDelayLength;
    double bpm;
    float divisor;
    float dividend;
    float lastSample, inputDelay1, inputDelay2, outputDelay1, outputDelay2;
    eOnOffToggle triplet;
};
#endif  // FXDELAY_H_INCLUDED