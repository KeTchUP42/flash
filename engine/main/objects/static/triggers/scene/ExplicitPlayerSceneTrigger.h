//
// Created by roman on 26.09.2020.
//

#ifndef FLASH_EXPLICITPLAYERSCENETRIGGER_H
#define FLASH_EXPLICITPLAYERSCENETRIGGER_H

#include "SceneTrigger.h"

namespace Triggers {

    class ExplicitPlayerSceneTrigger : public SceneTrigger {
    public:
        explicit ExplicitPlayerSceneTrigger(const std::string &filename, const Components::Area &area,
                                            const Components::Point &target, Screen::StateChangeable *context);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;

    protected:
        Components::Point m_target;
    };
}

#endif //FLASH_EXPLICITPLAYERSCENETRIGGER_H
