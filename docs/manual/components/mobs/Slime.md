 ## Slime

 Slime is an aggressive monster that moves in a random direction and deals damage to all players on the way, throwing them away.
 It can be killed by jumping from above. If a slime of sufficient size, it falls apart into two smaller slimes.
 
 **Configuration block example:**

    [Slime]
    POSITION = 610:565
    SIZE = 30:30
    ANGLE = 0
    SPRITE_POSITION = 610:565
    SPRITE_SIZE = 30:30
    SPRITE_ANGLE = 0
    MAX_HEALTH_POINTS = 10
    HEALTH_POINTS = 10
    SPEED = 0:0
    MOVE_SPEED = 3
    JUMP_SPEED = 10
    JUMP_RATE = 50
    MIN_SPLIT_SIZE = 10
    PUNCH_POWER = 5
    PUNCH_DAMAGE = 10
    TEXTURE = mobs/monsters/slime/slime.png
    COLLISION_ANALYSIS_STEP = 5

 ### Explanation:

 * `POSITION` - Parameter sets the position of the mobs's physical area on the screen. It has the following format - `X:Y`.
 * `SIZE` - Parameter sets the size of the mobs's physical area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - Parameter sets the angle of the mobs's physical area on the screen.
 * `SPRITE_POSITION` - Parameter sets the position of the sprite's area on the screen. It has the following format - `X:Y`.
 * `SPRITE_SIZE` - Parameter sets the size of the sprite's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `SPRITE_ANGLE` - Parameter sets the angle of the sprite's area on the screen. 
 * `MAX_HEALTH_POINTS` - The parameter of maximum health points.
 * `HEALTH_POINTS` - Health points. Necessary for the process of life activities.
 * `SPEED` - Material object's speed. It has the following format - `X_SPEED:Y_SPEED`.
 * `MOVE_SPEED` - The parameter of speed obtained when moving horizontally by jump.
 * `JUMP_SPEED` - The parameter of speed obtained horizontally at each jump.
 * `JUMP_RATE` - The value determines the frequency of slime's jumps. The higher the value is, the jumps are less frequent.
 * `MIN_SPLIT_SIZE` - The minimum size to which the slime can be divided. Slime could not have any side less than 10 px.
 * `PUNCH_POWER` - Parameter sets slime's punch power.
 * `PUNCH_DAMAGE` - Parameter sets slime's punch damage.
 * `TEXTURE` - Path to image file in the appropriate directory.
 * `COLLISION_ANALYSIS_STEP` - The collision frequency factor depends on the accuracy of the collision, but the performance suffers.