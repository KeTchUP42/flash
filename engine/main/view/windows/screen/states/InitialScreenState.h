//
// Created by roman on 01.09.2020.
//

#ifndef FLASH_INITIALSCREENSTATE_H
#define FLASH_INITIALSCREENSTATE_H

#include "common-base/ScreenState.h"
#include "../../../../objects/auxiliary/components/sprite/common-base/ISprite.h"
#include "../../../../objects/unifier/common/Unifier.h"

namespace View {

    class InitialScreenState : public ScreenState {
    public:
        explicit InitialScreenState(const std::string &filename);

        void load(StateChangeable *context, Managers::DataManager *manager, View::Window &window) override;

        void refresh() override;

        void draw(sf::RenderWindow &target) const noexcept override;

        void update(const sf::Event &event, View::Window &sender) override;

    protected:
        std::shared_ptr<Unite::Unifier> m_unifier;
    };
}

#endif //FLASH_INITIALSCREENSTATE_H
