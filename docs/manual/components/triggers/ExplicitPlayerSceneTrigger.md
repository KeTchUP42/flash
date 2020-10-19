 ## ExplicitPlayerSceneTrigger

 This trigger moves players to a specified point when one of the players enters the trigger area and changes current screen scene.

 **Configuration block example:**

    [ExplicitPlayerSceneTrigger]
    POSITION = 100:100
    SIZE = 100:100
    ANGLE = 0
    TARGET = 500:500
    NEXT_SCENE = levels/level_1.ini

 ### Explanation:

 * `POSITION` - Parameter sets the position of the trigger's area on the screen. It has the following format - `X:Y`.
 * `SIZE` - Parameter sets the size of the trigger's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - Parameter sets the angle of the trigger's area on the screen. 
 * `TARGETY` - Target point. It has the following format - `X:Y`.
 * `NEXT_SCENE` - Next scene file in the appropriate directory.
