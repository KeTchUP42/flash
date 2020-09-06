//
// Created by roman on 06.09.2020.
//

#ifndef FLASH_STONEWALLSPRITEFACTORY_H
#define FLASH_STONEWALLSPRITEFACTORY_H

#include "SpriteBoxFactory.h"

namespace Components {

    namespace Factory {

        class StoneWallSpriteFactory : public SpriteBoxFactory {
        public:
            std::shared_ptr<Components::ISpriteBox>
            createSpriteBox(const Point &point, const Size &size, Managers::DataManager *dataManager) const override;
        };
    }
}
#endif //FLASH_STONEWALLSPRITEFACTORY_H
