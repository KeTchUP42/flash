//
// Created by roman on 04.10.2020.
//

#ifndef FLASH_PLAYERSCENETRIGGER_H
#define FLASH_PLAYERSCENETRIGGER_H

#include "../SceneTrigger.h"
#include "../../common/handler/Handler.h"

namespace Triggers {

    class PlayerSceneTrigger : public SceneTrigger {
    public:
        PlayerSceneTrigger(const std::string &filename, const Components::Area &area,
                           Handler<Mobs::Player> *handler, View::StateChangeable *context);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) override;

    protected:
        std::shared_ptr<Handler<Mobs::Player>> m_handler;
    };
}

#endif //FLASH_PLAYERSCENETRIGGER_H
