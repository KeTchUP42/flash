//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_ICOMPOSITESPRITE_H
#define FLASH_ICOMPOSITESPRITE_H

#include "../common-base/ISprite.h"

#include <memory>

namespace Components {

    /**
     * @brief The base class of the ICompositeSprite class hierarchy.
     * @namespace Components
     *
     * This class is a base composite component interface.
    */
    class ICompositeSprite : public ISprite {
    public:
        ICompositeSprite() = default;

        /**
         * @brief Method adds new sprite.
         * @param sprite New sprite.
         */
        virtual void addSprite(ISprite *sprite) noexcept = 0;

        /**
         * @brief Method adds new sprite.
         * @param sprite New sprite.
         */
        virtual void addSprite(const std::shared_ptr<ISprite> &sprite) noexcept = 0;

        /**
         * @brief Method removes sprite.
         * @param sprite Existing sprite.
         */
        virtual void removeSprite(ISprite *sprite) noexcept = 0;

        /**
         * @brief Method removes sprite.
         * @param sprite Existing sprite.
         */
        virtual void removeSprite(const std::shared_ptr<ISprite> &sprite) noexcept = 0;

        virtual ~ICompositeSprite() = default;
    };
}

#endif //FLASH_ICOMPOSITESPRITE_H
