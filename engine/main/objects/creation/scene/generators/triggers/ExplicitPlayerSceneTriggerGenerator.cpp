//
// Created by roman on 30.09.2020.
//

#include "ExplicitPlayerSceneTriggerGenerator.h"
#include "../../../../static/triggers/scene/player/PlayerSceneTrigger.h"
#include "../../../../static/triggers/scene/player/handlers/ExplicitPositionPlayerHandler.h"
#include "../reduction/ElementaryReduction.h"
#include "../reduction/AreaReduction.h"

Creation::ExplicitPlayerSceneTriggerGenerator::
ExplicitPlayerSceneTriggerGenerator(Creation::Pools::SourcePool &pool, View::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Creation::ExplicitPlayerSceneTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::PlayerSceneTrigger(
            data.at("NEXT_SCENE"), RD::commonArea(data),
            new Triggers::ExplicitPositionPlayerHandler(RD::position(data, "TARGET")), m_context));
}
