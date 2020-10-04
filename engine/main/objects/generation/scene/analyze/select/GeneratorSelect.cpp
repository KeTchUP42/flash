//
// Created by roman on 29.09.2020.
//

#include "GeneratorSelect.h"
#include "../../generators/obstacles/DullBlockGenerator.h"
#include "../../generators/effects/GravityEffectGenerator.h"
#include "../../generators/sprites/BackgroundSpriteGenerator.h"
#include "../../generators/triggers/ExplicitPlayerSceneTriggerGenerator.h"
#include "../../generators/monsters/MushroomGenerator.h"
#include "../../generators/players/BasicPlayerGenerator.h"

Generate::Generator *
Generate::Select::select(const std::string &name, Pools::SourcePool &pool, Screen::StateChangeable *context) {
    using namespace Generate;
    //effects
    if (name == "GravityEffect")
        return new GravityEffectGenerator(pool);

    //monsters
    if (name == "Mushroom")
        return new MushroomGenerator(pool);

    //obstacles
    if (name == "DullBlock")
        return new DullBlockGenerator(pool);

    //players
    if (name == "BasicPlayer")
        return new BasicPlayerGenerator(pool);

    //sprites
    if (name == "BackgroundSprite")
        return new BackgroundSpriteGenerator(pool);

    //triggers
    if (name == "ExplicitPlayerSceneTrigger")
        return new ExplicitPlayerSceneTriggerGenerator(pool, context);

    return nullptr;
}