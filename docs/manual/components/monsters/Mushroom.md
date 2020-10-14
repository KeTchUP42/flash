 ## Mushroom

 Mushroom is a harmless mob, which simply pushes all monsters. Players can also jump on them.

 **Configuration block example:**

    [Mushroom]
    X = 100
    Y = 100
    WIDTH = 100
    HEIGHT = 100
    ANGLE = 0
    X_SPEED = 0
    Y_SPEED = 0
    PUNCH_POWER = 5
    ELASTICITY_LEVEL = 0.25
    SPRITE_X = 100
    SPRITE_Y = 100
    SPRITE_WIDTH = 100
    SPRITE_HEIGHT = 100
    TEXTURE = mushroom.png
    COLLISION_ANALYSIS_STEP = 5

 ### Explanation:

 * `X`, `Y`, `WIDTH`, `HEIGHT` and `ANGLE` - options allow you to specify the position and orientation of mushroom's physical area on the screen.
 * `X_SPEED` and `Y_SPEED` - physical object's speed.
 * `PUNCH_POWER` - mushroom's push power.
 * `SPRITE_X`, `SPRITE_Y`, `SPRITE_WIDTH` and `SPRITE_HEIGHT` - options allow you to specify the position and orientation of mushroom's sprite area on the screen.
 * `ELASTICITY_LEVEL` - the percentage of vertical speed that the player will return to when he jumps a mushroom.
 * `TEXTURE` - path to image file.
 * `COLLISION_ANALYSIS_STEP` - the collision frequency factor depends on the accuracy of the collision, but the performance suffers.