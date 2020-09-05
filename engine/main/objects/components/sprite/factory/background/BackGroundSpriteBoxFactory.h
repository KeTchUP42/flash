//
// Created by roman on 31.08.2020.
//

#ifndef FLASH_BACKGROUNDSPRITEBOXFACTORY_H
#define FLASH_BACKGROUNDSPRITEBOXFACTORY_H

#include "../../sprite-box/base/ISpriteBox.h"
#include "../../../../../data/manager/DataManager.h"

#include <memory>

namespace Components {

    /**
     * @brief The base class of the BackGroundSpriteBoxFactory class hierarchy.
     * @namespace Components
     *
     * This class is a sprite-factory interface. 
    */
    class BackGroundSpriteBoxFactory {
    public:
        BackGroundSpriteBoxFactory() = default;

        /**
         * @brief Main factory function which creates new background sprite box.
         * @param dataManager Manager which uses to get some data resources.
         * @param size Screen size.
         * @return SpriteBox.
         */
        virtual std::shared_ptr<Components::ISpriteBox>
        createSpriteBox(Managers::DataManager *dataManager, const Size &size) const = 0;

        virtual ~BackGroundSpriteBoxFactory() = default;
    };
}

#endif //FLASH_BACKGROUNDSPRITEBOXFACTORY_H
