 ## Basic player

 This is the basic and easiest implementation of a player.

 **Configuration block example:**

    [BasicPlayer]
    X = 600
    Y = 370
    WIDTH = 30
    HEIGHT = 30
    ANGLE = 0
    X_SPEED = 0
    Y_SPEED = 0
    MOVE_SPEED = 3
    MAX_MOVE_SPEED = 20
    JUMP_SPEED = 15
    SPRITE_X = 600
    SPRITE_Y = 370
    SPRITE_WIDTH = 30
    SPRITE_HEIGHT = 30
    TEXTURE = player.png
    KEYMAP = keys/keymap.ini
    COLLISION_ANALYSIS_STEP = 5

 ### Explanation:

 * `X`, `Y`, `WIDTH`, `HEIGHT` and `ANGLE` - options allow you to specify the position and orientation of mushroom's physical area on the screen.
 * `X_SPEED` and `Y_SPEED` - physical object's speed.
 * `MOVE_SPEED` - speed increase at the push of a button.
 * `MAX_MOVE_SPEED` - maximum speed that a player can achieve when moving independently.
 * `JUMP_SPEED` - speed obtained by jumping.
 * `SPRITE_X`, `SPRITE_Y`, `SPRITE_WIDTH` and `SPRITE_HEIGHT` - options allow you to specify the position and orientation of mushroom's sprite area on the screen.
 * `TEXTURE` - path to image file.
 * `KEYMAP` - path to keys config file. {1}
 * `COLLISION_ANALYSIS_STEP` - the collision frequency factor depends on the accuracy of the collision, but the performance suffers.
 
 {1} **Example:**  
    
    [MAP]
    Right = 3
    Left = 0
    Jump = 57
    Use = 4