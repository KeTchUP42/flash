//
// Created by roman on 10.09.2020.
//

#ifndef FLASH_STARTLEVELFACTORY_H
#define FLASH_STARTLEVELFACTORY_H

#include "LevelUnifierFactory.h"

namespace LevelGenerating {

    class StartLevelFactory : public LevelUnifierFactory {
    public:
        std::shared_ptr<Unite::Unifier>
        loadLevel(const sf::Vector2u &size, Screen::StateChangeable *context, Managers::DataManager *manager) const override;
    };
}

#endif //FLASH_STARTLEVELFACTORY_H
