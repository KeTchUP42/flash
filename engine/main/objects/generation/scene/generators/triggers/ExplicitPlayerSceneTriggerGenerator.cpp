//
// Created by roman on 30.09.2020.
//

#include "ExplicitPlayerSceneTriggerGenerator.h"
#include "../../../../static/triggers/scene/player/PlayerSceneTrigger.h"
#include "../../../../static/triggers/scene/player/handlers/ExplicitPositionPlayerHandler.h"
#include "../reduction/ElementaryReduction.h"
#include "../reduction/AreaReduction.h"

Generate::ExplicitPlayerSceneTriggerGenerator::
ExplicitPlayerSceneTriggerGenerator(Generate::Pools::SourcePool &pool, Screen::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Generate::ExplicitPlayerSceneTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addTrigger(new Triggers::PlayerSceneTrigger(
            data.at("NEXT_SCENE"), commonArea(data),
            new Triggers::ExplicitPositionPlayerHandler(position(data, "TARGET")), m_context));
}
