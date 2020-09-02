//
// Created by roman on 31.08.2020.
//

#ifndef FLASH_PLAINSPRITEBOX_H
#define FLASH_PLAINSPRITEBOX_H

#include "base/ISpriteBox.h"

namespace Components {

    class PlainSpriteBox : public ISpriteBox {
    public:
        PlainSpriteBox() = default;

        /**
         * @brief Method returns SpriteBox Point.
         * @return Sprite point.
         */
        virtual const Point &getPoint() const noexcept = 0;

        /**
         * @brief Method returns SpriteBox Size.
         * @return Sprite size.
         */
        virtual const Size &getSize() const noexcept = 0;
    };
}

#endif //FLASH_PLAINSPRITEBOX_H
