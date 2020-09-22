//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_COLLISION_H
#define FLASH_COLLISION_H

#include "CollisionStrategy.h"
#include "moving-collision/PlayerCollision.h"
#include "moving-collision/MonsterCollision.h"
#include "moving-collision/ObstacleCollision.h"
#include "static-collision/StaticObstacleCollision.h"
#include "static-collision/StaticPlayerCollision.h"
#include "static-collision/StaticMonsterCollision.h"

#include <memory>

namespace Material {

    class Collision : public CollisionStrategy<Material::MaterialObject *, Material::MaterialObject *> {
    public:
        explicit Collision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY);

        Material::MaterialObject *abscissaMoveAble(Material::MaterialObject *object) const noexcept override;

        Material::MaterialObject *ordinateMoveAble(Material::MaterialObject *object) const noexcept override;

        Mobs::Player *abscissaPlayerMoveAble(Material::MaterialObject *object) const noexcept;

        Mobs::Player *ordinatePlayerMoveAble(Material::MaterialObject *object) const noexcept;

        Mobs::Monster *abscissaMonsterMoveAble(Material::MaterialObject *object) const noexcept;

        Mobs::Monster *ordinateMonsterMoveAble(Material::MaterialObject *object) const noexcept;

        Obstacles::Obstacle *abscissaObstacleMoveAble(Material::MaterialObject *object) const noexcept;

        Obstacles::Obstacle *ordinateObstacleMoveAble(Material::MaterialObject *object) const noexcept;

        void setAnalysisStepX(float analysisStepX) noexcept;

        void setAnalysisStepY(float analysisStepY) noexcept;

        const std::shared_ptr<Material::PlayerCollision> &getPlayerCollision() const noexcept;

        const std::shared_ptr<Material::MonsterCollision> &getMonsterCollision() const noexcept;

        const std::shared_ptr<Material::ObstacleCollision> &getObstacleCollision() const noexcept;

        const std::shared_ptr<Material::StaticObstacleCollision> &getStaticObstacleCollision() const noexcept;

        const std::shared_ptr<Material::StaticPlayerCollision> &getStaticPlayerCollision() const noexcept;

        const std::shared_ptr<Material::StaticMonsterCollision> &getStaticMonsterCollision() const noexcept;

    protected:
        std::shared_ptr<Material::PlayerCollision> _playerCollision;
        std::shared_ptr<Material::MonsterCollision> _monsterCollision;
        std::shared_ptr<Material::ObstacleCollision> _obstacleCollision;

        std::shared_ptr<Material::StaticPlayerCollision> _staticPlayerCollision;
        std::shared_ptr<Material::StaticMonsterCollision> _staticMonsterCollision;
        std::shared_ptr<Material::StaticObstacleCollision> _staticObstacleCollision;
    };
}


#endif //FLASH_COLLISION_H
