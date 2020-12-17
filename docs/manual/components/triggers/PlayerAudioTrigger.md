 ## PlayerAudioTrigger

 This trigger plays audio when one of the players enters the trigger area.

 **Configuration block example:**

    [PlayerAudioTrigger]
    POSITION = 400:500
    SIZE = 100:100
    ANGLE = 0
    AUDIO = [audio-path]
    AUDIO_VOLUME = 10
    AUDIO_LOOP = 0

 ### Explanation:

 * `POSITION` - The parameter sets the position of the trigger's area on the screen. It has the following format - `X:Y`.
 * `SIZE` - The parameter sets the size of the trigger's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - The parameter sets the angle of the trigger's area on the screen.
 * `AUDIO` - Path to audio file in the appropriate directory.
 * `AUDIO_VOLUME` - This parameter sets the audio playback volume.
 * `AUDIO_LOOP` - The parameter sets whether the audio will be repeated.