 ## Basic player

 This is the basic and easiest implementation of a player.

 **Configuration block example:**

    [BasicPlayer]
    POSITION = 600:370
    SIZE = 30:30
    ANGLE = 0
    SPRITE_POSITION = 600:370
    SPRITE_SIZE = 30:30
    SPRITE_ANGLE = 0
    SPEED = 0:0
    MOVE_SPEED = 3
    MAX_MOVE_SPEED = 20
    JUMP_SPEED = 15
    TEXTURE = player.png
    KEYMAP = keys/keymap.ini
    COLLISION_ANALYSIS_STEP = 5

 ### Explanation:

 * `POSITION` - Parameter sets the position of the player's physical area on the screen. It has the following format - `X:Y`.
 * `SIZE` - Parameter sets the size of the player's physical area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - Parameter sets the angle of the player's physical area on the screen. 
 * `SPRITE_POSITION` - Parameter sets the position of the sprite's area on the screen. It has the following format - `X:Y`.
 * `SPRITE_SIZE` - Parameter sets the size of the sprite's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `SPRITE_ANGLE` - Parameter sets the angle of the sprite's area on the screen. 
 * `SPEED` - physical object's speed. It has the following format - `X_SPEED:Y_SPEED`.
 * `MOVE_SPEED` - speed increase at the push of a button.
 * `MAX_MOVE_SPEED` - maximum speed that a player can achieve when moving independently.
 * `JUMP_SPEED` - speed obtained by jumping.
 * `TEXTURE` - path to image file.
 * `KEYMAP` - path to keys config file. {1}
 * `COLLISION_ANALYSIS_STEP` - the collision frequency factor depends on the accuracy of the collision, but the performance suffers.
 
 {1} **Example:**  
    
    [MAP]
    Right = 3
    Left = 0
    Jump = 57
    Use = 4