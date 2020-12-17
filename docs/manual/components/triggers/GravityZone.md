 ## GravityZone

 This trigger gives some acceleration for all mobs or players who enters the trigger area.  
 It generates atomic triggers, each of which is responsible for processing its own objects.

 **Configuration block example:**

    [GravityZone]
    POSITION = 475:500
    SIZE = 100:100
    ANGLE = 0
    X_ACCELERATION = 0
    Y_ACCELERATION = 0.8

 ### Explanation:

 * `POSITION` - The parameter sets the position of the trigger's area on the screen. It has the following format - `X:Y`.
 * `SIZE` - The parameter sets the size of the trigger's area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - The parameter sets the angle of the trigger's area on the screen.