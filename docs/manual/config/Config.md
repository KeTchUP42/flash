 ## What configuration files needed to start?

 There is a global configuration file that contains information about the location of the required data.  
 This global file must have the path `./config/flash.ini` relative to the main binary file.  
 It also contains the location of the configuration file for the program window.  

 **An example of a global configuration file:**

    [DATA]
    ; Path to the program data directory:
    PATH = ./data

    ; Names of main data catalogues:
    audio = audio
    config = config
    fonts = fonts
    logs = logs
    scenes = scenes
    textures = textures

    [WINDOW]
    ; Window config file path:
    WindowSettingsFile = win/primary.ini
    
 **An example of a window configuration file:**

    [WINDOW]
    ; Window title:
    title = Flash

    ; Window view style. Window style is default.
    ; Аvailable styles:
    ; 1. Default
    ; 2. Fullscreen
    style = Default

    ; Window video-mode properties:
    width = 1280
    height = 720

    ; Window vertical sync enabled:
    VerticalSync = 0

    ; Window FPS:
    fps = 50

    [SCENE]
    ; File with init scene:
    launch = levels/level_1.ini

    [CONTEXT_SETTINGS]
    ;Bits of the depth buffer:
    depthBits = 24
    ;Bits of the stencil buffer:
    stencilBits = 8
    ;Level of antialiasing:
    antialiasingLevel = 0
    ;Major number of the context version to create:
    majorVersion = 1
    ;Minor number of the context version to create:
    minorVersion = 1
    ;The attribute flags to create the context with:
    attributeFlags = 0
    ; Whether the context framebuffer is sRGB capable:
    sRgbCapable = 0
