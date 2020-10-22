 ## Scenes

 All scenes are described in configuration files that describe all objects on the screen.  
 Scenes were mainly conceived to provide a convenient description of levels. Scenes can be linked together using different triggers.  

 **Simple level example:**

    [BackGroundSprite]
    TEXTURE = background/dungeon_back.png

    [GravityEffect]
    X_ACCELERATION = 0
    Y_ACCELERATION = 0.65

    [Text]
    POSITION = 510:400
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
    POSITION = 610:570
    SIZE = 30:30
    ANGLE = 0
    SPRITE_POSITION = 610:570
    SPRITE_SIZE = 30:30
    SPRITE_ANGLE = 0
    HEALTH_POINTS = 100
    SPEED = 0:0
    MOVE_SPEED = 5
    MAX_MOVE_SPEED = 20
    JUMP_SPEED = 20
    TEXTURE = mobs/player/mush.png
    KEYMAP = keys/keymap.ini
    COLLISION_ANALYSIS_STEP = 5

    [DullBlock_0]
    POSITION = 575:600
    SIZE = 100:100
    ANGLE = 0
    SPEED = 0:0
    ELASTIC_COEFFICIENT = 0.5
    FRICTION_COEFFICIENT = 0.85
    IS_FIXED = 1
    TEXTURE = structure/walls/stone/stone_wall_1.jpg
    COLLISION_ANALYSIS_STEP = 5

    [DullBlock_1]
    POSITION = 475:600
    SIZE = 100:100
    ANGLE = 0
    SPEED = 0:0
    ELASTIC_COEFFICIENT = 0.5
    FRICTION_COEFFICIENT = 0.85
    IS_FIXED = 1
    TEXTURE = structure/walls/stone/stone_wall_2.jpg
    COLLISION_ANALYSIS_STEP = 5

    [DullBlock_2]
    POSITION = 675:600
    SIZE = 100:100
    ANGLE = 0
    SPEED = 0:0
    ELASTIC_COEFFICIENT = 0.5
    FRICTION_COEFFICIENT = 0.85
    IS_FIXED = 1
    TEXTURE = structure/walls/stone/stone_wall_3.jpg
    COLLISION_ANALYSIS_STEP = 5
