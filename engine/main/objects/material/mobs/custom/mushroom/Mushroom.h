//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_MUSHROOM_H
#define FLASH_MUSHROOM_H

#include "../../common/base/AnalyzingMob.h"
#include "properties/MushroomProperties.h"

namespace Mobs {

    class Mushroom : public AnalyzingMob {
    public:
        Mushroom(
                const Material::MaterialProperties &material_properties,
                const Mobs::MobProperties &properties,
                const Components::Area &area,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<Material::Algorithms> &algorithms,
                const Mobs::MushroomProperties &params
        );

        void selfAction(Unite::Unifier *unifier) override;

    protected:
        Mobs::MushroomProperties m_mushroom;
    };
}

#endif //FLASH_MUSHROOM_H
