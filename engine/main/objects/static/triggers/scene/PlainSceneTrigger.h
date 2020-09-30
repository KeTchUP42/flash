//
// Created by roman on 26.09.2020.
//

#ifndef FLASH_PLAINSCENETRIGGER_H
#define FLASH_PLAINSCENETRIGGER_H

#include "SceneTrigger.h"

namespace Triggers {

    class PlainSceneTrigger : public SceneTrigger {
    public:
        explicit PlainSceneTrigger(const std::string &filename, const Components::Area &area, Screen::StateChangeable *context);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;
    };
}

#endif //FLASH_PLAINSCENETRIGGER_H
