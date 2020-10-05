//
// Created by roman on 29.09.2020.
//

#include "GeneratorSelect.h"
#include "../../generators/effects/GravityEffectGenerator.h"
#include "../../generators/monsters/MushroomGenerator.h"
#include "../../generators/obstacles/DullBlockGenerator.h"
#include "../../generators/players/BasicPlayerGenerator.h"
#include "../../generators/sprites/BackgroundSpriteGenerator.h"
#include "../../generators/sprites/BackSpriteGenerator.h"
#include "../../generators/sprites/FrontSpriteGenerator.h"
#include "../../generators/triggers/ExplicitPlayerSceneTriggerGenerator.h"
#include "../../generators/triggers/AbscissaPlayerSceneTriggerGenerator.h"
#include "../../generators/triggers/OrdinatePlayerSceneTriggerGenerator.h"

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
    if (name == "BackSprite")
        return new BackSpriteGenerator(pool);
    if (name == "FrontSprite")
        return new FrontSpriteGenerator(pool);

    //triggers
    if (name == "ExplicitPlayerSceneTrigger")
        return new ExplicitPlayerSceneTriggerGenerator(pool, context);
    if (name == "AbscissaPlayerSceneTrigger")
        return new AbscissaPlayerSceneTriggerGenerator(pool, context);
    if (name == "OrdinatePlayerSceneTrigger")
        return new OrdinatePlayerSceneTriggerGenerator(pool, context);

    return nullptr;
}