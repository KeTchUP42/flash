//
// Created by roman on 06.09.2020.
//

#ifndef FLASH_STONEWALLSPRITEFACTORY_H
#define FLASH_STONEWALLSPRITEFACTORY_H

#include "SpriteFactory.h"

namespace ComponentsGenerating {

    class StoneWallSpriteFactory : public SpriteFactory {
    public:
        std::shared_ptr<Components::ISprite>
        createSprite(const Components::Point &point, const Components::Size &size,
                     Managers::DataManager *manager) const override;
    };
}

#endif //FLASH_STONEWALLSPRITEFACTORY_H
