//
// Created by roman on 31.08.2020.
//

#ifndef FLASH_BACKGROUNDSPRITEBOXFACTORY_H
#define FLASH_BACKGROUNDSPRITEBOXFACTORY_H

#include "../../sprite-box/base/ISpriteBox.h"
#include "../../../../../../data/manager/DataManager.h"

#include <memory>

namespace Components {

    namespace Factory {

        /**
         * @brief The base class of the BackGroundSpriteBoxFactory class hierarchy.
         * @namespace Components::Factory
         *
         * This class is a sprite-factory interface.
        */
        class BackGroundSpriteBoxFactory {
        public:
            BackGroundSpriteBoxFactory() = default;

            /**
             * @brief Main factory function which creates new background sprite box.
             * @param size Screen size.
             * @param dataManager Manager which uses to get some data resources.
             * @return SpriteBox.
             */
            virtual std::shared_ptr<Components::ISpriteBox>
            createSpriteBox(const Size &size, Managers::DataManager *dataManager) const = 0;

            virtual ~BackGroundSpriteBoxFactory() = default;
        };
    }
}
#endif //FLASH_BACKGROUNDSPRITEBOXFACTORY_H
