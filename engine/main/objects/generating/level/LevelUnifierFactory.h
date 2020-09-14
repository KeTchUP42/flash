//
// Created by roman on 10.09.2020.
//

#ifndef FLASH_LEVELUNIFIERFACTORY_H
#define FLASH_LEVELUNIFIERFACTORY_H

#include "../../unifier/common-base/Unifier.h"
#include "../../../data/manager/DataManager.h"
#include "../../../view/windows/screen/context-abilities/StateChangeable.h"

#include <memory>

namespace LevelGenerating {

    /**
     * @brief The base class of the LevelUnifierFactory factory class hierarchy.
     * @namespace LevelGenerating
     *
     * This class defines base LevelUnifierFactory interface.
    */
    class LevelUnifierFactory {
    public:
        LevelUnifierFactory() = default;

        /**
         * @brief Method creates new Unifier with objects.
         * @param size Screen size for scale.
         * @param context Window context.
         * @param manager Data manager.
         * @return New Unifier.
         */
        virtual std::shared_ptr<Unite::Unifier>
        loadLevel(const sf::Vector2u &size, Screen::StateChangeable *context, Managers::DataManager *manager) const = 0;

        virtual ~LevelUnifierFactory() = default;
    };
}

#endif //FLASH_LEVELUNIFIERFACTORY_H
