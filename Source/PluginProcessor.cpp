#include "PluginProcessor.h"
#include "PluginEditor.h"

InterDelayAudioProcessor::InterDelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

InterDelayAudioProcessor::~InterDelayAudioProcessor()
{
}

const juce::String InterDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool InterDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool InterDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool InterDelayAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double InterDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int InterDelayAudioProcessor::getNumPrograms()
{
    return 1;
}

int InterDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void InterDelayAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String InterDelayAudioProcessor::getProgramName (int index)
{
    return {};
}

void InterDelayAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

void InterDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void InterDelayAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool InterDelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void InterDelayAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
    }
}

juce::AudioProcessorEditor* InterDelayAudioProcessor::createEditor()
{
    return new InterDelayAudioProcessorEditor (*this);
}

void InterDelayAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
}

void InterDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new InterDelayAudioProcessor();
}
