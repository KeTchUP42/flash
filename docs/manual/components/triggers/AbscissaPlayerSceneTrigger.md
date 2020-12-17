 ## AbscissaPlayerSceneTrigger

 This trigger moves players to a specified point on the abscissa axis when one of the players enters the trigger area and changes current screen scene.

 **Configuration block example:**

    [AbscissaPlayerSceneTrigger]
    POSITION = 100:100
    SIZE = 100:100
    ANGLE = 0
    TARGET_X = 0
    NEXT_SCENE = [scene-path]

 ### Explanation:

 * `POSITION` - The parameter sets the position of the trigger's area on the screen. It has the following format - `X:Y`.
 * `SIZE` - The parameter sets the size of the trigger's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - The parameter sets the angle of the trigger's area on the screen.
 * `TARGET_X` - Position on the abscissa axis where the players will be moved.
 * `NEXT_SCENE` - Next scene file in the appropriate directory.