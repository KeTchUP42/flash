 ## Jumping player

 This realization of the player can only jump and has one possible sprite state.

 **Configuration block example:**

    [JumpingPlayer]
    POSITION = 610:565
    SIZE = 30:30
    ANGLE = 0
    SPRITE_POSITION = 610:565
    SPRITE_SIZE = 30:30
    SPRITE_ANGLE = 0
    MAX_HEALTH_POINTS = 100
    HEALTH_POINTS = 100
    SPEED = 0:0
    MOVE_SPEED = 3
    MAX_MOVE_SPEED = 20
    JUMP_DASH_SPEED = 15
    TEXTURE = [image-path]
    KEYMAP = [config-path]
    COLLISION_ANALYSIS_STEP = 5

 ### Explanation:

 * `POSITION` - The parameter sets the position of the player's physical area on the screen. It has the following format - `X:Y`.
 * `SIZE` - The parameter sets the size of the player's physical area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - The parameter sets the angle of the player's physical area on the screen.
 * `SPRITE_POSITION` - The parameter sets the position of the sprite's area on the screen. It has the following format - `X:Y`.
 * `SPRITE_SIZE` - The parameter sets the size of the sprite's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `SPRITE_ANGLE` - The parameter sets the angle of the sprite's area on the screen. 
 * `MAX_HEALTH_POINTS` - The parameter of maximum health points.
 * `HEALTH_POINTS` - The parameter sets health points which are necessary for the process of life activities.
 * `SPEED` - The parameter sets material object's speed. It has the following format - `X_SPEED:Y_SPEED`.
 * `MOVE_SPEED` - The speed value which increase at the push of a button.
 * `MAX_MOVE_SPEED` - The maximum speed that a player can achieve when moving independently.
 * `JUMP_DASH_SPEED` - The parameter sets speed received vertical at each jump.
 * `TEXTURE` - Path to image file in the appropriate directory.
 * `KEYMAP` - Path to keys config file. [1]
 * `COLLISION_ANALYSIS_STEP` - The collision frequency factor depends on the accuracy of the collision, but the performance suffers.

 [1] **Example:**

    [MAP]
    Right = 3
    Left = 0
    Jump = 57
