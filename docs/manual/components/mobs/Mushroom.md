 ## Mushroom

 Mushroom is a harmless mob, which simply pushes all mobs. Players can also jump on them.

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

 * `POSITION` - Parameter sets the position of the mobs's physical area on the screen. It has the following format - `X:Y`.
 * `SIZE` - Parameter sets the size of the mobs's physical area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - Parameter sets the angle of the mobs's physical area on the screen.
 * `SPRITE_POSITION` - Parameter sets the position of the sprite's area on the screen. It has the following format - `X:Y`.
 * `SPRITE_SIZE` - Parameter sets the size of the sprite's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `SPRITE_ANGLE` - Parameter sets the angle of the sprite's area on the screen. 
 * `SPEED` - Material object's speed. It has the following format - `X_SPEED:Y_SPEED`.
 * `PUNCH_POWER` - Mushroom's push power.
 * `ELASTICITY_LEVEL` - The percentage of vertical speed that the player will return to when he jumps a mushroom.
 * `TEXTURE` - Path to image file.
 * `COLLISION_ANALYSIS_STEP` - The collision frequency factor depends on the accuracy of the collision, but the performance suffers.