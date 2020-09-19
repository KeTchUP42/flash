//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_MOBCOLLISION_H
#define FLASH_MOBCOLLISION_H

#include "CollisionStrategy.h"
#include "PlayerCollision.h"
#include "MonsterCollision.h"

#include <memory>

namespace Material {

    class MobCollision : public CollisionStrategy<Material::MaterialObject *, Material::MaterialObject *> {
    public:
        explicit MobCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY);

        Material::MaterialObject *abscissaMoveAble(Material::MaterialObject *object) const noexcept override;

        Material::MaterialObject *ordinateMoveAble(Material::MaterialObject *object) const noexcept override;

        void setAnalysisStepX(float analysisStepX) noexcept;

        void setAnalysisStepY(float analysisStepY) noexcept;

        const std::shared_ptr<Material::PlayerCollision> &getPlayerCollision() const noexcept;

        const std::shared_ptr<Material::MonsterCollision> &getMonsterCollision() const noexcept;

    protected:
        std::shared_ptr<Material::PlayerCollision> _playerCollision;
        std::shared_ptr<Material::MonsterCollision> _monsterCollision;
    };
}


#endif //FLASH_MOBCOLLISION_H
