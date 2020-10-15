 ## Mushroom

 Mushroom is a harmless mob, which simply pushes all monsters. Players can also jump on them.

 **Configuration block example:**

    [Mushroom]
    POSITION = 100:100
    SIZE = 30:30
    ANGLE = 0
    SPRITE_POSITION = 100:100
    SPRITE_SIZE = 30:30
    SPRITE_ANGLE = 0
    SPEED = 0:0
    PUNCH_POWER = 5
    ELASTICITY_LEVEL = 0.25
    TEXTURE = mushroom.png
    COLLISION_ANALYSIS_STEP = 5

 ### Explanation:

 * `POSITION` - Parameter sets the position of the monsters's physical area on the screen. It has the following format - `X:Y`.
 * `SIZE` - Parameter sets the size of the monsters's physical area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - Parameter sets the angle of the monsters's physical area on the screen.
 * `SPRITE_POSITION` - Parameter sets the position of the sprite's area on the screen. It has the following format - `X:Y`.
 * `SPRITE_SIZE` - Parameter sets the size of the sprite's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `SPRITE_ANGLE` - Parameter sets the angle of the sprite's area on the screen. 
 * `SPEED` - physical object's speed. It has the following format - `X_SPEED:Y_SPEED`.
 * `PUNCH_POWER` - mushroom's push power.
 * `ELASTICITY_LEVEL` - the percentage of vertical speed that the player will return to when he jumps a mushroom.
 * `TEXTURE` - path to image file.
 * `COLLISION_ANALYSIS_STEP` - the collision frequency factor depends on the accuracy of the collision, but the performance suffers.