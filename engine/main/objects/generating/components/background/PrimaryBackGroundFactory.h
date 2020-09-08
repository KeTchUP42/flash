//
// Created by roman on 31.08.2020.
//

#ifndef FLASH_PRIMARYBACKGROUNDFACTORY_H
#define FLASH_PRIMARYBACKGROUNDFACTORY_H

#include "BackGroundSpriteBoxFactory.h"

namespace ComponentsGenerating {

    class PrimaryBackGroundFactory : public BackGroundSpriteBoxFactory {
    public:
        std::shared_ptr<Components::ISprite>
        createSpriteBox(const Components::Size &size, Managers::DataManager *dataManager) const override;
    };
}

#endif //FLASH_PRIMARYBACKGROUNDFACTORY_H
