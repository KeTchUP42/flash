 ## Platform block

 This facility is conceived as a platform for transporting monsters and players.  
 Block changes its direction when it encounters any other obstacles.

 **Configuration block example:**

    [PlatformBlock]
    X = 210
    Y = 500
    WIDTH = 80
    HEIGHT = 40
    ANGLE = 0
    X_SPEED = 1
    Y_SPEED = 0
    ELASTIC_COEFFICIENT = 0.2
    FRICTION_COEFFICIENT = 0.4
    IS_FIXED = 1
    TEXTURE = wall.jpg
    COLLISION_ANALYSIS_STEP = 5

 ### Explanation:
    
 * `X`, `Y`, `WIDTH`, `HEIGHT` and `ANGLE` - options allow you to specify the position and orientation of block's physical area on the screen.
 * `X_SPEED` and `Y_SPEED` - physical object's speed.
 * `ELASTIC_COEFFICIENT` - this coefficient uses in jumps calculations.
 * `FRICTION_COEFFICIENT` - this coefficient uses in movement calculations.
 * `IS_FIXED` - if this flag is not set, the obstacle will be affected by static effects.
 * `TEXTURE` - path to image file.
 * `COLLISION_ANALYSIS_STEP` - the collision frequency factor depends on the accuracy of the collision, but the performance suffers.