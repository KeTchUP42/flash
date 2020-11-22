//
// Created by roman on 22.11.2020.
//

#ifndef FLASH_SLIME_H
#define FLASH_SLIME_H

#include "../../common/base/BaseMob.h"
#include "properties/SlimeProperties.h"

namespace Mobs {

    class Slime : public BaseMob {
    public:
        explicit Slime(
                const MobProperties &properties,
                const Components::Area &area,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<::Material::Algorithms> &algorithms,
                const SlimeProperties &params
        );

        void selfAction(Unite::Unifier *unifier) override;

    private:
        Mobs::Slime *createSmallerSlime(
                const Mobs::MobProperties &properties,
                const Mobs::SlimeProperties &slimeProperties) const;

    protected:
        SlimeProperties m_slime;
    };
}

#endif //FLASH_SLIME_H
