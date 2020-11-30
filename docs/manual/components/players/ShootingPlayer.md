 ## Shooting player

 This realization of the player extends jumping player and adds shooting possibility.

 **Configuration block example:**

    [ShootingPlayer]
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
    BULLETS_FLIGHT_SPEED = 30
    BULLETS_DAMAGE = 10
    BULLETS_UNDER_EFFECTS = 1
    BULLETS_SIZE = 10:10
    BULLETS_ANGLE = 0
    BULLETS_SPRITE_SIZE = 10:10
    BULLETS_SPRITE_ANGLE = 0
    BULLETS_RIGHT_TEXTURE = [image-path]
    BULLETS_LEFT_TEXTURE = [image-path]
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
 * `SPEED` - The parameter sets material object's speed. It has the following format - `X_SPEED:Y_SPEED`.
 * `MOVE_SPEED` - Speed increase at the push of a button.
 * `MAX_MOVE_SPEED` - Maximum speed that a player can achieve when moving independently.
 * `JUMP_DASH_SPEED` - The parameter sets speed received vertical at each jump.
 * `BULLETS_FLIGHT_SPEED` - The parameter sets initial speed of a bullet that is given to it at creation.
 * `BULLETS_DAMAGE` - The parameter sets the damage caused by the bullet when it hits the target.
 * `BULLETS_UNDER_EFFECTS` - If this flag is not set, the particle will be affected by static effects.
 * `BULLETS_SIZE` - The parameter sets the size of the physical area of the bullet. It has the following format - `WIDTH:HEIGHT`.
 * `BULLETS_ANGLE` - The parameter sets the angle of rotation of the physical area of the bullet.
 * `BULLETS_SPRITE_SIZE` - The parameter sets the size of the bullet sprite. It has the following format - `WIDTH:HEIGHT`.
 * `BULLETS_SPRITE_ANGLE` - This parameter sets the angle of rotation of the bullet sprite.
 * `BULLETS_RIGHT_TEXTURE` - The path to the image file in the appropriate directory, using as a texture for the right side bullet.
 * `BULLETS_LEFT_TEXTURE` - The path to the image file in the appropriate directory, using as a texture for the left side bullet.
 * `TEXTURE` - Path to image file in the appropriate directory.
 * `KEYMAP` - Path to keys config file. [1]
 * `COLLISION_ANALYSIS_STEP` - The collision frequency factor depends on the accuracy of the collision, but the performance suffers.

 [1] **Example:**

    [MAP]
    Right = 3
    Left = 0
    Jump = 57
    ShootRight = 72
    ShootLeft = 71
