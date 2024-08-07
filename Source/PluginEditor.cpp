#include "PluginProcessor.h"
#include "PluginEditor.h"

InterDelayAudioProcessorEditor::InterDelayAudioProcessorEditor (InterDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
}

InterDelayAudioProcessorEditor::~InterDelayAudioProcessorEditor()
{
}

void InterDelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void InterDelayAudioProcessorEditor::resized()
{

}
