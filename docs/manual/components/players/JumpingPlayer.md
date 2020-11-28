 ## Jumping player

 This realization of the player can only jump and has one possible sprite state.

 **Configuration block example:**

    [JumpingPlayer]
    POSITION = 600:370
    SIZE = 30:30
    ANGLE = 0
    SPRITE_POSITION = 600:370
    SPRITE_SIZE = 30:30
    SPRITE_ANGLE = 0
    MAX_HEALTH_POINTS = 100
    HEALTH_POINTS = 100
    SPEED = 0:0
    MOVE_SPEED = 3
    MAX_MOVE_SPEED = 20
    JUMP_SPEED = 15
    TEXTURE = [image-path]
    KEYMAP = [config-path]
    COLLISION_ANALYSIS_STEP = 5

 ### Explanation:

 * `POSITION` - Parameter sets the position of the player's physical area on the screen. It has the following format - `X:Y`.
 * `SIZE` - Parameter sets the size of the player's physical area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - Parameter sets the angle of the player's physical area on the screen. 
 * `SPRITE_POSITION` - Parameter sets the position of the sprite's area on the screen. It has the following format - `X:Y`.
 * `SPRITE_SIZE` - Parameter sets the size of the sprite's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `SPRITE_ANGLE` - Parameter sets the angle of the sprite's area on the screen. 
 * `MAX_HEALTH_POINTS` - The parameter of maximum health points.
 * `HEALTH_POINTS` - Health points. Necessary for the process of life activities.
 * `SPEED` - Material object's speed. It has the following format - `X_SPEED:Y_SPEED`.
 * `MOVE_SPEED` - Speed increase at the push of a button.
 * `MAX_MOVE_SPEED` - Maximum speed that a player can achieve when moving independently.
 * `JUMP_SPEED` - Speed obtained by jumping.
 * `TEXTURE` - Path to image file in the appropriate directory.
 * `KEYMAP` - Path to keys config file. [1]
 * `COLLISION_ANALYSIS_STEP` - The collision frequency factor depends on the accuracy of the collision, but the performance suffers.

 [1] **Example:**

    [MAP]
    Right = 3
    Left = 0
    Jump = 57
    Use = 4
