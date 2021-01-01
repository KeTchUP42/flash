//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_MOVINGCOLLISION_H
#define FLASH_MOVINGCOLLISION_H

#include "../../MaterialObject.h"
#include "../algorithms/coordinates/CoordinatesCalculation.h"
#include "../algorithms/collision/MovingCollisionAlgorithms.h"

#include <list>

namespace Material {

    class MovingCollision {
    public:
        MovingCollision(float analysisStepX, float analysisStepY);

        template<class Type>
        Type *abscissaMoveAble(Material::MaterialObject *object, const std::list<std::shared_ptr<Type>> &objects) const noexcept;

        template<class Type>
        Type *ordinateMoveAble(Material::MaterialObject *object, const std::list<std::shared_ptr<Type>> &objects) const noexcept;

        template<class Type>
        Type *abscissaMoveAble(Material::MaterialObject *object, const std::list<Type *> &objects) const noexcept;

        template<class Type>
        Type *ordinateMoveAble(Material::MaterialObject *object, const std::list<Type *> &objects) const noexcept;

        bool abscissaMoveAble(Material::MaterialObject *object, Material::MaterialObject *processed) const noexcept;

        bool ordinateMoveAble(Material::MaterialObject *object, Material::MaterialObject *processed) const noexcept;

        std::pair<float, float> getAnalysisStep() const noexcept;

        float getAnalysisStepX() const noexcept;

        float getAnalysisStepY() const noexcept;

    private:
        const float ANALYSIS_STEP_X;
        const float ANALYSIS_STEP_Y;
    };

    template<class Type>
    Type *Material::MovingCollision::
    abscissaMoveAble(Material::MaterialObject *object, const std::list<std::shared_ptr<Type>> &objects) const noexcept {
        if (object->getSpeed().xSpeed == 0) return nullptr;

        Components::Point objectMinCoordinates = minCoordinates(*object);
        Components::Point objectMaxCoordinates = maxCoordinates(*object);

        for (const std::shared_ptr<Type> &processed : objects) {

            if (processed.get() == object) continue;

            if (movingAbscissaCollision(objectMinCoordinates, objectMaxCoordinates, *object, *processed, ANALYSIS_STEP_Y)) {
                return processed.get();
            }
        }
        return nullptr;
    }

    template<class Type>
    Type *Material::MovingCollision::
    ordinateMoveAble(Material::MaterialObject *object, const std::list<std::shared_ptr<Type>> &objects) const noexcept {
        if (object->getSpeed().ySpeed == 0) return nullptr;

        Components::Point objectMinCoordinates = minCoordinates(*object);
        Components::Point objectMaxCoordinates = maxCoordinates(*object);

        for (const std::shared_ptr<Type> &processed : objects) {

            if (processed.get() == object) continue;

            if (movingOrdinateCollision(objectMinCoordinates, objectMaxCoordinates, *object, *processed, ANALYSIS_STEP_X)) {
                return processed.get();
            }
        }
        return nullptr;
    }

    template<class Type>
    Type *MovingCollision::abscissaMoveAble(Material::MaterialObject *object, const std::list<Type *> &objects) const noexcept {
        if (object->getSpeed().xSpeed == 0) return nullptr;

        Components::Point objectMinCoordinates = minCoordinates(*object);
        Components::Point objectMaxCoordinates = maxCoordinates(*object);

        for (Type *processed : objects) {

            if (processed == object) continue;

            if (movingAbscissaCollision(objectMinCoordinates, objectMaxCoordinates, *object, *processed, ANALYSIS_STEP_Y)) {
                return processed;
            }
        }
        return nullptr;
    }

    template<class Type>
    Type *MovingCollision::ordinateMoveAble(Material::MaterialObject *object, const std::list<Type *> &objects) const noexcept {
        if (object->getSpeed().ySpeed == 0) return nullptr;

        Components::Point objectMinCoordinates = minCoordinates(*object);
        Components::Point objectMaxCoordinates = maxCoordinates(*object);

        for (Type *processed : objects) {

            if (processed == object) continue;

            if (movingOrdinateCollision(objectMinCoordinates, objectMaxCoordinates, *object, *processed, ANALYSIS_STEP_X)) {
                return processed;
            }
        }
        return nullptr;
    }
}

#endif //FLASH_MOVINGCOLLISION_H
