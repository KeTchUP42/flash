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
        loadLevel(Screen::StateChangeable *context, Managers::DataManager *manager, sf::RenderWindow &target) const override;

        void loadLevel(Unite::Unifier *unifier, Screen::StateChangeable *context,
                       Managers::DataManager *manager, sf::RenderWindow &target) const override;
    };
}

#endif //FLASH_STARTLEVELFACTORY_H
