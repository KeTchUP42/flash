//
// Created by roman on 01.09.2020.
//

#ifndef FLASH_BASESCREENSTATE_H
#define FLASH_BASESCREENSTATE_H

#include "ScreenState.h"
#include "../../../../objects/auxiliary/components/sprite/sprite-box/base/ISpriteBox.h"

namespace Screen {

    class BaseScreenState : public ScreenState {
    public:
        void load(StateChangeable *context, Managers::DataManager *dataManager, sf::RenderTarget &target) override;

        void refresh() override;

        void draw(sf::RenderTarget &target) const noexcept override;

        void update(const sf::Event &event, sf::RenderWindow &sender) noexcept override;

    protected:
        std::shared_ptr<Components::ISpriteBox> _background;
    };
}

#endif //FLASH_BASESCREENSTATE_H
