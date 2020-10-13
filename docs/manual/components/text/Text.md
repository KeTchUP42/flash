 ## Text

 This component allows you to display any text information on the screen.

 Configuration block example:

    [Text]
    X = 100
    Y = 100
    ANGLE = 0
    STRING = SOME TEXT
    CHARACTER_SIZE = 30
    OUTLINE_COLOR = 255:0:0:255
    FILL_COLOR = 255:0:0:255
    LETTER_SPACING = 1
    LINE_SPACING = 1
    OUTLINE_THICKNESS = 0
    STYLE = Regular
    FONT = font.ttf
    
 ### Explanation:

 * `X`, `Y` and `ANGLE` -  options allow you to specify the position and orientation of text on the screen.
 * `STRING` - displayed text.
 *  Color is set by four parameters - `255:0:0:255`, where `r:g:b:alpha`.
 * `FONT` - font file.
 * Available styles:
     * Regular
     * Bold
     * Italic
     * Underlined
     * StrikeThrough