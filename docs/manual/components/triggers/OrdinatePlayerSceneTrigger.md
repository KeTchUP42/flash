 ## OrdinatePlayerSceneTrigger

 This trigger moves players to a specified point on the ordinate axis when one of the players enters the trigger area.

 Configuration block example:

    [OrdinatePlayerSceneTrigger]
    X = 100
    Y = 100
    WIDTH = 100
    HEIGHT = 100
    ANGLE = 0
    TARGET_Y = 0
    NEXT_SCENE = levels/level_1.ini

 ### Explanation:

 * `X`, `Y`, `WIDTH`, `HEIGHT` and `ANGLE` - options allow you to specify the position and orientation of triggers's physical area on the screen.
 * `TARGET_Y` - target `Y` position. You can write "MAX" if you need to specify a point at the edge of the coordinates.
 * `NEXT_SCENE` - next scene file.
