//
// Created by roman on 06.09.2020.
//

#ifndef FLASH_SPRITEBOXFACTORY_H
#define FLASH_SPRITEBOXFACTORY_H

#include "../../sprite-box/base/ISpriteBox.h"
#include "../../../../../../data/manager/DataManager.h"

#include <memory>

namespace Components {

    namespace Factory {

        /**
         * @brief The base class of the SpriteBoxFactory class hierarchy.
         * @namespace Components::Factory
         *
         * This class is a sprite-factory interface.
        */
        class SpriteBoxFactory {
        public:
            SpriteBoxFactory() = default;

            /**
             * @brief Main factory function which creates new sprite box.
             * @param point Sprite box coordinates.
             * @param size Screen size.
             * @param dataManager Manager which uses to get some data resources.
             * @return SpriteBox.
            */
            virtual std::shared_ptr<Components::ISpriteBox>
            createSpriteBox(const Point &point, const Size &size, Managers::DataManager *dataManager) const = 0;

            virtual ~SpriteBoxFactory() = default;
        };
    }
}
#endif //FLASH_SPRITEBOXFACTORY_H
