//
// Created by roman on 30.09.2020.
//

#ifndef FLASH_SCENETRIGGER_H
#define FLASH_SCENETRIGGER_H

#include "../common/AreaTrigger.h"
#include "../../../../view/windows/screen/context-abilities/StateChangeable.h"

namespace Triggers {

    class SceneTrigger : public AreaTrigger {
    public:
        explicit SceneTrigger(const std::string &filename, const Components::Area &area, Screen::StateChangeable *context)
                : AreaTrigger(area), m_context(context), m_scene_filename(filename) {}

        void update(const sf::Event &event, sf::RenderWindow &sender) override {}

    protected:
        Screen::StateChangeable *m_context;
        std::string m_scene_filename;
    };
}

#endif //FLASH_SCENETRIGGER_H
