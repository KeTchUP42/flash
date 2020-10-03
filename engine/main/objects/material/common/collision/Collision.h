//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_COLLISION_H
#define FLASH_COLLISION_H

#include "CollisionStrategy.h"
#include "moving-collision/MovingPlayerCollision.h"
#include "moving-collision/MovingMonsterCollision.h"
#include "moving-collision/MovingObstacleCollision.h"
#include "static-collision/StaticObstacleCollision.h"
#include "static-collision/StaticPlayerCollision.h"
#include "static-collision/StaticMonsterCollision.h"

#include <memory>

namespace Material {

    class Collision final : public CollisionStrategy<Material::MaterialObject *, Material::MaterialObject *> {
    public:
        explicit Collision(float analysisStepX, float analysisStepY);

        Material::MaterialObject *
        abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;

        Material::MaterialObject *
        ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;

        Mobs::Player *abscissaPlayerMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept;

        Mobs::Player *ordinatePlayerMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept;

        Mobs::Monster *abscissaMonsterMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept;

        Mobs::Monster *ordinateMonsterMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept;

        Obstacles::Obstacle *abscissaObstacleMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept;

        Obstacles::Obstacle *ordinateObstacleMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept;

        void setAnalysisStepX(float analysisStepX) noexcept;

        void setAnalysisStepY(float analysisStepY) noexcept;

        const Material::MovingPlayerCollision &getMovingPlayerCollision() const noexcept;

        const Material::MovingMonsterCollision &getMovingMonsterCollision() const noexcept;

        const Material::MovingObstacleCollision &getMovingObstacleCollision() const noexcept;

        const Material::StaticObstacleCollision &getStaticObstacleCollision() const noexcept;

        const Material::StaticPlayerCollision &getStaticPlayerCollision() const noexcept;

        const Material::StaticMonsterCollision &getStaticMonsterCollision() const noexcept;

    private:
        Material::MovingPlayerCollision m_movingPlayerCollision;
        Material::MovingMonsterCollision m_movingMonsterCollision;
        Material::MovingObstacleCollision m_movingObstacleCollision;

        Material::StaticPlayerCollision m_staticPlayerCollision;
        Material::StaticMonsterCollision m_staticMonsterCollision;
        Material::StaticObstacleCollision m_staticObstacleCollision;
    };
}

#endif //FLASH_COLLISION_H
