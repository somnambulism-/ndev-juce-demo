/*
  ==============================================================================

    FirstSynthAudioManager.cpp
    Created: 4 Nov 2016 12:06:05am
    Author:  Elliott Barrett

  ==============================================================================
*/

#ifndef FIRSTSYNTHAUDIOMANAGER_H_INCLUDED
#define FIRSTSYNTHAUDIOMANAGER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "FirstSynthAudioSource.cpp"

class FirstSynthAudioManager
{
public:
    FirstSynthAudioManager()
    {
        deviceManager = new AudioDeviceManager();
        deviceManager->initialise(2, 2, 0, true, String::empty, 0);
        deviceManager->addAudioCallback(&audioSourcePlayer);
        
        synthAudioSource = new FirstSynthAudioSource();
        audioSourcePlayer.setSource(synthAudioSource);
        deviceManager->addMidiInputCallback(String::empty, &(synthAudioSource->midiCollector));
    }
    
    ~FirstSynthAudioManager()
    {
        
    }
private:
	// Members
    ScopedPointer<AudioDeviceManager> deviceManager;
    AudioSourcePlayer audioSourcePlayer;
    ScopedPointer<FirstSynthAudioSource> synthAudioSource;

    // Methods
};

#endif