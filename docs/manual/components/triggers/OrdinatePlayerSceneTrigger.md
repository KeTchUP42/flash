 ## OrdinatePlayerSceneTrigger

 This trigger moves players to a specified point on the ordinate axis when one of the players enters the trigger area and changes current screen scene.

 **Configuration block example:**

    [OrdinatePlayerSceneTrigger]
    POSITION = 100:100
    SIZE = 100:100
    ANGLE = 0
    TARGET_Y = 0
    NEXT_SCENE = [scene-path]

 ### Explanation:

 * `POSITION` - The parameter sets the position of the trigger's area on the screen. It has the following format - `X:Y`.
 * `SIZE` - The parameter sets the size of the trigger's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - The parameter sets the angle of the trigger's area on the screen.
 * `TARGET_Y` - Position on the ordinate axis where the players will be moved.
 * `NEXT_SCENE` - Next scene file in the appropriate directory.