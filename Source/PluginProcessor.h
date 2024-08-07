#pragma once

#include <JuceHeader.h>

/**
 * @brief AudioProcessor for InterDelay.
 * Defines the processing for InterDelay.
 * @see
 *  <a href="https://docs.juce.com/master/classAudioProcessor.html">
 *      juce::AudioProcessor
 *  </a>
 */
class InterDelayAudioProcessor  : public juce::AudioProcessor
{
public:
    /**
     * @brief Constructor.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a8602919358f1bf8799abd0c179c5e03b">
     *      juce::AudioProcessor::AudioProcessor()
     *  </a>
     */
    InterDelayAudioProcessor();

    /**
     * @brief Destructor
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a8602919358f1bf8799abd0c179c5e03b">
     *      juce::AudioProcessor::~AudioProcessor()
     *  </a>
     */
    ~InterDelayAudioProcessor() override;

    /**
     * @brief Called before playback starts, to let the processor prepare.
     * @param sampleRate The target sample rate.
     * @param samplesPerBlock A strong hint about the maximum number of
     *      sample that will be provided in each block.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a44b74778247a35a669a3a994d814389e">
     *      juce::AudioProcessor::prepareToPlay()
     *  </a>
     */
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;

    /**
     * @brief Called after playback has stopped, to let the object free up any
     * resources it no longer needs.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a44b74778247a35a669a3a994d814389e">
     *      juce::AudioProcessor::releaseResources()
     *  </a>
     */
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    /**
     * @brief Callback to query if the AudioProcessor supports a specific
     *      layout.
     * @param layouts The layouts to check.
     * @return 0
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a44b74778247a35a669a3a994d814389e">
     *      juce::AudioProcessor::isBusesLayoutSupported()
     *  </a>
     */
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    /**
     * @brief Renders the next block.
     * @param  buffer       The audio buffer.
     * @param  midiMessages The MIDI buffer.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a44b74778247a35a669a3a994d814389e">
     *      juce::AudioProcessor::processBlock()
     *  </a>
     */
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    /**
     * @brief Creates the processor's GUI.
     * @return A pointer to the AudioProcessorEditor for this processor.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#adf76a112d670baa25b40d13cf87e1306">
     *      juce::AudioProcessor::createEditor()
     *  </a>
     */
    juce::AudioProcessorEditor* createEditor() override;

    /**
     * @brief Check if this processor has an editor.
     * @return true
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a00be8f595da09ba01d74cb7c52b8fb81">
     *      juce::AudioProcessor::hasEditor()
     *  </a>
     */
    bool hasEditor() const override { return true; }

    /**
     * @brief Returns the name of the processor.
     * @return A const string with value 'InterDelay'.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a71affad7782adb55b183d6d4d0853253">
     *      juce::AudioProcessor::getName()
     *  </a>
     */
    const juce::String getName() const override;

    /**
     * @brief Check if the processor accepts MIDI.
     * @return false
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#ae482a0c2928bfe77de821e6824ffaee6">
     *      juce::AudioProcessor::acceptsMidi()
     *  </a>
     */
    bool acceptsMidi() const override;

    /**
     * @brief Check if the processor produces MIDI.
     * @return false
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a719715472b12c40e8144109561c04e65">
     *      juce::AudioProcessor::producesMidi()
     *  </a>
     */
    bool producesMidi() const override;

    /**
     * @brief Check if the processor is a midi effect.
     * @return false
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#ac23ad992a24d00574b9e062f0e4dddf5">
     *      juce::AudioProcessor::isMidiEffect()
     *  </a>
     */
    bool isMidiEffect() const override;

    /**
     * @brief Returns the length of the processor's tail in seconds.
     * @return The length of the processor's tail, in seconds.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a358db82650c6423968091f8b4d22b09a">
     *      juce::AudioProcessor::getTailLengthSeconds()
     *  </a>
     */
    double getTailLengthSeconds() const override;

    /**
     * @brief Returns the number of currently active programs.
     * @return The number of currently active programs.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a510123768a99f32ff4a23d0458e15e13">
     *      juce::AudioProcessor::getNumPrograms()
     *  </a>
     */
    int getNumPrograms() override;

    /**
     * @brief Returns the number of the currently active program.
     * @return The number of the currently active program.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#ac111282810f1e9ddb057e1267fa0bd79">
     *      juce::AudioProcessor::getCurrentProgram()
     *  </a>
     */
    int getCurrentProgram() override;

    /**
     * @brief Called by the host to change the current program.
     * @param index The index of the program to use.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#aafe9fab0a94b6bb23cecdbb67851f206">
     *      juce::AudioProcessor::setCurrentProgram()
     *  </a>
     */
    void setCurrentProgram (int index) override;

    /**
     * @brief Must return the name of a given program.
     * @param index The index of the program to search for.
     * @return A const string containing the name of the given program.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#af0facfc9ed31fb3d2948ceac7ae89d87">
     *      juce::AudioProcessor::getProgramName()
     *  </a>
     */
    const juce::String getProgramName (int index) override;

    /**
     * @brief Called by the host to rename the program.
     * @param index The index of the program to rename.
     * @param newName The new name to give to the program at index.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#accd5bd7b594fbc1a385f7a8b31c7b3f3">
     *      juce::AudioProcessor::changeProgramName()
     *  </a>
     */
    void changeProgramName (int index, const juce::String& newName) override;

    /**
     * @brief The host will call this method when it want to save the
     *      processor's internal state.
     * @param destData A pointer to the destination of the processor's state
     *      information.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a5d79591b367a7c0516e4ef4d1d6c32b2">
     *      juce::AudioProcessor::getStateInformation()
     *  </a>
     */
    void getStateInformation (juce::MemoryBlock& destData) override;

    /**
     * @brief This must restore the processor's state from a block of data
     *      previously created using getStateInformation().
     * @param data The data from which to restore the processor's state.
     * @param sizeInBytes The size of the data.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessor.html#a6154837fea67c594a9b35c487894df27">
     *      juce::AudioProcessor::setStateInformation()
     *  </a>
     */
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InterDelayAudioProcessor)
};
