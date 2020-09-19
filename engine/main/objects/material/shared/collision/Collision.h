//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_COLLISION_H
#define FLASH_COLLISION_H

#include "CollisionStrategy.h"
#include "moving-collision/PlayerCollision.h"
#include "moving-collision/MonsterCollision.h"
#include "moving-collision/ObstacleCollision.h"

#include <memory>

namespace Material {

    class Collision : public CollisionStrategy<Material::MaterialObject *, Material::MaterialObject *> {
    public:
        explicit Collision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY);

        Material::MaterialObject *abscissaMoveAble(Material::MaterialObject *object) const noexcept override;

        Material::MaterialObject *ordinateMoveAble(Material::MaterialObject *object) const noexcept override;

        void setAnalysisStepX(float analysisStepX) noexcept;

        void setAnalysisStepY(float analysisStepY) noexcept;

        const std::shared_ptr<Material::PlayerCollision> &getPlayerCollision() const noexcept;

        const std::shared_ptr<Material::MonsterCollision> &getMonsterCollision() const noexcept;

        const std::shared_ptr<Material::ObstacleCollision> &getObstacleCollision() const;

    protected:
        std::shared_ptr<Material::PlayerCollision> _playerCollision;
        std::shared_ptr<Material::MonsterCollision> _monsterCollision;
        std::shared_ptr<Material::ObstacleCollision> _obstacleCollision;
    };
}


#endif //FLASH_COLLISION_H
