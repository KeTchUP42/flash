//
// Created by roman on 31.08.2020.
//

#ifndef FLASH_PRIMARYBACKGROUNDFACTORY_H
#define FLASH_PRIMARYBACKGROUNDFACTORY_H

#include "BackGroundSpriteBoxFactory.h"

namespace Components {

    class PrimaryBackGroundFactory : public BackGroundSpriteBoxFactory {
    public:
        std::shared_ptr<Components::ISpriteBox>
        createSpriteBox(Managers::DataManager *dataManager, const Size &size) const override;
    };
}

#endif //FLASH_PRIMARYBACKGROUNDFACTORY_H
