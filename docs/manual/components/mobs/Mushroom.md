 ## Mushroom

 Mushroom is a harmless mob, which simply pushes all other mobs. Players can also jump on them.

 **Configuration block example:**

    [Mushroom]
    POSITION = 100:100
    SIZE = 30:30
    ANGLE = 0
    SPRITE_POSITION = 100:100
    SPRITE_SIZE = 30:30
    SPRITE_ANGLE = 0
    MAX_HEALTH_POINTS = 10
    HEALTH_POINTS = 10
    SPEED = 0:0
    PUNCH_POWER = 5
    ELASTICITY_LEVEL = 0.25
    TEXTURE = [image-path]
    COLLISION_ANALYSIS_STEP = 5

 ### Explanation:

 * `POSITION` - The parameter sets the position of the mobs physical area on the screen. It has the following format - `X:Y`.
 * `SIZE` - The parameter sets the size of the mobs physical area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - The parameter sets the angle of the mobs physical area on the screen.
 * `SPRITE_POSITION` - The parameter sets the position of the sprite's area on the screen. It has the following format - `X:Y`.
 * `SPRITE_SIZE` - The parameter sets the size of the sprite's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `SPRITE_ANGLE` - The parameter sets the angle of the sprite's area on the screen.
 * `MAX_HEALTH_POINTS` - The parameter of maximum health points.
 * `HEALTH_POINTS` - The parameter sets health points which are necessary for the process of life activities.
 * `SPEED` - The parameter sets material object's speed. It has the following format - `X_SPEED:Y_SPEED`.
 * `PUNCH_POWER` - The parameter sets mushroom's push power.
 * `ELASTICITY_LEVEL` - The percentage of vertical speed that the player will return to when he jumps a mushroom.
 * `TEXTURE` - Path to image file in the appropriate directory.
 * `COLLISION_ANALYSIS_STEP` - The collision frequency factor depends on the accuracy of the collision, but the performance suffers.