//
// Created by roman on 07.10.2020.
//

#include "StaticCollision.h"

bool Material::StaticCollision::abscissaMoveAble(Material::MaterialObject *object, Material::MaterialObject *processed) const noexcept {
    if (object == processed) return false;
    return staticAbscissaCollision(*object, *processed);
}

bool Material::StaticCollision::ordinateMoveAble(Material::MaterialObject *object, Material::MaterialObject *processed) const noexcept {
    if (object == processed) return false;
    return staticOrdinateCollision(*object, *processed);
}