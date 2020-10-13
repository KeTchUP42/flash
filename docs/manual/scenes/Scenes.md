 # Scenes

 **All** scenes are described in configuration files that describe all objects on the screen.  
 Scenes were mainly conceived to provide a convenient description of levels. The levels are linked to each other by triggers.  

 **Simple** level example:

    [BackGroundSprite]
    TEXTURE = background/dungeon_back.png

    [GravityEffect]
    X_ACCELERATION = 0
    Y_ACCELERATION = 0.65

    [Text]
    X = 510
    Y = 400
    ANGLE = 0
    STRING = Welcome!
    CHARACTER_SIZE = 50
    OUTLINE_COLOR = 255:0:0:255
    FILL_COLOR = 135:100:150:255
    LETTER_SPACING = 1
    LINE_SPACING = 1
    OUTLINE_THICKNESS = 2
    STYLE = Italic
    FONT = sansation.ttf

    [BasicPlayer]
    X = 610
    Y = 570
    WIDTH = 30
    HEIGHT = 30
    ANGLE = 0
    X_SPEED = 0
    Y_SPEED = 0
    MOVE_SPEED = 5
    MAX_MOVE_SPEED = 20
    JUMP_SPEED = 25
    SPRITE_X = 610
    SPRITE_Y = 570
    SPRITE_WIDTH = 30
    SPRITE_HEIGHT = 30
    TEXTURE = mobs/player/mush.png
    KEYMAP = keys/keymap.ini
    COLLISION_ANALYSIS_STEP = 5

    [DullBlock_0]
    X = 575
    Y = 600
    WIDTH = 100
    HEIGHT = 100
    ANGLE = 0
    X_SPEED = 0
    Y_SPEED = 0
    ELASTIC_COEFFICIENT = 0.5
    FRICTION_COEFFICIENT = 0.85
    IS_FIXED = 1
    TEXTURE = structure/walls/stone/stone_wall_1.jpg
    COLLISION_ANALYSIS_STEP = 5

    [DullBlock_1]
    X = 475
    Y = 600
    WIDTH = 100
    HEIGHT = 100
    ANGLE = 0
    X_SPEED = 0
    Y_SPEED = 0
    ELASTIC_COEFFICIENT = 0.5
    FRICTION_COEFFICIENT = 0.85
    IS_FIXED = 1
    TEXTURE = structure/walls/stone/stone_wall_2.jpg
    COLLISION_ANALYSIS_STEP = 5

    [DullBlock_2]
    X = 675
    Y = 600
    WIDTH = 100
    HEIGHT = 100
    ANGLE = 0
    X_SPEED = 0
    Y_SPEED = 0
    ELASTIC_COEFFICIENT = 0.5
    FRICTION_COEFFICIENT = 0.85
    IS_FIXED = 1
    TEXTURE = structure/walls/stone/stone_wall_3.jpg
    COLLISION_ANALYSIS_STEP = 5
