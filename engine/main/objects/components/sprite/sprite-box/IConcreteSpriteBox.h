//
// Created by roman on 31.08.2020.
//

#ifndef FLASH_ICONCRETESPRITEBOX_H
#define FLASH_ICONCRETESPRITEBOX_H

#include "base/ISpriteBox.h"

namespace Components {

    class IConcreteSpriteBox : public ISpriteBox {
    public:
        IConcreteSpriteBox() = default;

        /**
         * @brief Method returns SpriteBox Point.
         * @return const Point&
         */
        virtual const Point &getPoint() const noexcept = 0;

        /**
         * @brief Method returns SpriteBox Size.
         * @return const Size&
         */
        virtual const Size &getSize() const noexcept = 0;
    };
}

#endif //FLASH_ICONCRETESPRITEBOX_H
