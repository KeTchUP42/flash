//
// Created by roman on 06.09.2020.
//

#ifndef FLASH_SPRITEFACTORY_H
#define FLASH_SPRITEFACTORY_H

#include "../../simple/base/ISprite.h"
#include "../../../../../../data/manager/DataManager.h"

#include <memory>

namespace Components {

    namespace Factory {

        /**
         * @brief The base class of the SpriteFactory class hierarchy.
         * @namespace Components::Factory
         *
         * This class is a sprite-factory interface.
        */
        class SpriteFactory {
        public:
            SpriteFactory() = default;

            /**
             * @brief Main factory function which creates new sprite.
             * @param point Sprite coordinates.
             * @param size Screen size.
             * @param dataManager Manager which uses to get some data resources.
             * @return Sprite.
            */
            virtual std::shared_ptr<Components::ISprite>
            createSprite(const Point &point, const Size &size, Managers::DataManager *dataManager) const = 0;

            virtual ~SpriteFactory() = default;
        };
    }
}
#endif //FLASH_SPRITEFACTORY_H
