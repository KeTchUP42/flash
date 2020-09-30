//
// Created by roman on 29.09.2020.
//

#include "Implementer.h"
#include "../generators/obstacles/DullBlockGenerator.h"
#include "../generators/effects/GravityEffectGenerator.h"
#include "../generators/sprites/BackgroundSpriteGenerator.h"

Generating::Generator *
Generating::implement(const std::string &alias, SourcePool &pool, Screen::StateChangeable *context) noexcept {
    using namespace Generating;
    //obstacles
    if (alias == "DullBlock")
        return new DullBlockGenerator(pool);

    //effects
    if (alias == "GravityEffect")
        return new GravityEffectGenerator(pool);

    //sprites
    if (alias == "BackgroundSprite")
        return new BackgroundSpriteGenerator(pool);

    //todo: Add alias implementation.
    return nullptr;
}