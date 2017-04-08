/*
  ==============================================================================

    SpectroscopeComponent.h
    Created: 8 Apr 2017 12:46:51pm
    Author:  Nick Thompson

  ==============================================================================
*/

#ifndef SPECTROSCOPECOMPONENT_H_INCLUDED
#define SPECTROSCOPECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SpectroscopeComponent    : public Component,
                                 private Timer
{
public:
    SpectroscopeComponent();
    ~SpectroscopeComponent();

    void paint (Graphics&) override;
    void resized() override;
    void timerCallback() override;

    void pushBuffer (AudioSampleBuffer& buffer);
    inline void pushSample (float sample);

    enum {
        kFFTOrder = 10,
        kFFTSize = 1024, // 2^10
    };

private:
    float m_fifo [kFFTSize];
    float m_fftData [kFFTSize];
    float m_outputData [kFFTSize];

    unsigned int m_fifoIndex;
    bool m_fftBlockReady;

    FFT m_forwardFFT;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectroscopeComponent)
};


#endif  // SPECTROSCOPECOMPONENT_H_INCLUDED