 ## ExplicitPlayerSceneTrigger

 This trigger moves players to a specified point when one of the players enters the trigger area.

 **Configuration block example:**

    [ExplicitPlayerSceneTrigger]
    X = 100
    Y = 100
    WIDTH = 100
    HEIGHT = 100
    ANGLE = 0
    TARGET_X = 500
    TARGET_Y = 500
    NEXT_SCENE = levels/level_1.ini

 ### Explanation:

 * `X`, `Y`, `WIDTH`, `HEIGHT` and `ANGLE` - options allow you to specify the position and orientation of triggers's physical area on the screen.
 * `TARGET_X` and `TARGET_Y` - target point.
 * `NEXT_SCENE` - next scene file.
