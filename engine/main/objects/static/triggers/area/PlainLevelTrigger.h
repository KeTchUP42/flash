//
// Created by roman on 26.09.2020.
//

#ifndef FLASH_PLAINLEVELTRIGGER_H
#define FLASH_PLAINLEVELTRIGGER_H

#include "AreaTrigger.h"
#include "../../../../view/windows/screen/context-abilities/StateChangeable.h"

namespace Triggers {

    class PlainLevelTrigger : public AreaTrigger {
    public:
        explicit PlainLevelTrigger(const Components::Area &area, Screen::StateChangeable *context);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;

    protected:
        Screen::StateChangeable *m_context;
    };
}

#endif //FLASH_PLAINLEVELTRIGGER_H
