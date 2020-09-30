//
// Created by roman on 29.09.2020.
//

#include "Implementer.h"
#include "../generators/obstacles/DullBlockGenerator.h"
#include "../generators/effects/GravityEffectGenerator.h"
#include "../generators/sprites/BackgroundSpriteGenerator.h"
#include "../../../../other/exceptions/RuntimeException.h"
#include "../generators/triggers/SceneAreaTriggerGenerator.h"

Generating::Generator *
Generating::implement(const std::string &name, SourcePool &pool, Screen::StateChangeable *context) {
    using namespace Generating;
    //obstacles
    if (name == "DullBlock")
        return new DullBlockGenerator(pool);

    //effects
    if (name == "GravityEffect")
        return new GravityEffectGenerator(pool);

    //sprites
    if (name == "BackgroundSprite")
        return new BackgroundSpriteGenerator(pool);

    //triggers
    if (name == "SceneAreaTrigger")
        return new SceneAreaTriggerGenerator(pool, context);

    throw PreferredExceptions::RuntimeException("Invalid generator name: " + name);
}