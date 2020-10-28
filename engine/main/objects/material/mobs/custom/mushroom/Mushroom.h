//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_MUSHROOM_H
#define FLASH_MUSHROOM_H

#include "../../common/base/BaseMob.h"
#include "properties/MushroomProperties.h"
#include "mind/MushroomMind.h"

namespace Mobs {

    class Mushroom : public BaseMob {
    public:
        explicit Mushroom(
                const Mobs::MobProperties &properties, const Components::Area &area,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<Material::Algorithms> &algorithms,
                const Mobs::MushroomProperties &params
        );

        friend class MushroomMind;

        void selfAction(Unite::Unifier *unifier) override;

    protected:
        MushroomMind m_mind;
        Mobs::MushroomProperties m_mushroom;
    };
}

#endif //FLASH_MUSHROOM_H
