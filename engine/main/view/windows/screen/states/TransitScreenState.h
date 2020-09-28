//
// Created by roman on 26.09.2020.
//

#ifndef FLASH_TRANSITSCREENSTATE_H
#define FLASH_TRANSITSCREENSTATE_H

#include "common-base/ScreenState.h"
#include "../../../../objects/unifier/common-base/Unifier.h"

namespace Screen {

    class TransitScreenState : public ScreenState {
    public:
        TransitScreenState(const std::shared_ptr<Unite::Unifier> &unifier);

        void load(StateChangeable *context, Managers::DataManager *manager, sf::RenderWindow &target) override;

        void refresh() override;

        void draw(sf::RenderWindow &target) const noexcept override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;

    protected:
        std::shared_ptr<Unite::Unifier> m_unifier;
    };
}

#endif //FLASH_TRANSITSCREENSTATE_H
