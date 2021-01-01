//
// Created by roman on 26.09.2020.
//

#ifndef FLASH_TRANSITSCREENSTATE_H
#define FLASH_TRANSITSCREENSTATE_H

#include "common-base/ScreenState.h"
#include "../../../../objects/unifier/common/Unifier.h"

namespace View {

    class TransitScreenState : public ScreenState {
    public:
        TransitScreenState(const std::string &filename, Unite::Unifier *unifier);

        void load(StateChangeable *context, Managers::DataManager *manager, View::Window &window) override;

        void refresh() override;

        void draw(sf::RenderWindow &target) const noexcept override;

        void update(const sf::Event &event, View::Window &sender) override;

    protected:
        std::shared_ptr<Unite::Unifier> m_unifier;
    };
}

#endif //FLASH_TRANSITSCREENSTATE_H
