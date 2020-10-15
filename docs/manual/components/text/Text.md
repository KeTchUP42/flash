 ## Text

 This component allows you to display any text information on the screen.

 **Configuration block example:**

    [Text]
    POSITION = 100:100
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

 * `POSITION` - Parameter sets the position of the text on the screen. It has the following format - `X:Y`.
 * `ANGLE` - Parameter sets text's angle on the screen. 
 * `STRING` - Displayed text information.
 *  Color sets by four parameters - `255:0:0:255`, where `r:g:b:alpha`.
 * `FONT` - Font file.
 * Available styles:
     * Regular
     * Bold
     * Italic
     * Underlined
     * StrikeThrough