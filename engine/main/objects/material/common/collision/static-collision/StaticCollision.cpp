//
// Created by roman on 07.10.2020.
//

#include "StaticCollision.h"

bool Material::StaticCollision::abscissaMoveAble(Material::MaterialObject *object1, Material::MaterialObject *object2) const noexcept {
    if (object1 == object2) return false;
    return staticAbscissaCollision(*object1, *object2);
}

bool Material::StaticCollision::ordinateMoveAble(Material::MaterialObject *object1, Material::MaterialObject *object2) const noexcept {
    if (object1 == object2) return false;
    return staticOrdinateCollision(*object1, *object2);
}

bool Material::StaticCollision::collision(const Possibilities::PhysicallySituated &object1, const Possibilities::PhysicallySituated &object2) const noexcept {
    return Material::collision(object1, object2);
}