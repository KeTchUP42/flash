//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_UNIFIER_H
#define FLASH_UNIFIER_H

#include "../../auxiliary/possibilities/Drawable.h"
#include "../../../view/windows/base/observer/Observer.h"
#include "../../../view/windows/screen/context-abilities/StateChangeable.h"
#include "../../mobs/player/base/Player.h"

namespace Mobs {
    class Player;
}

namespace Unite {

    class Unifier : public Possibilities::Drawable<sf::RenderWindow>,
                    public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        /**
         * @brief Base objects unifier constructor.
         * @param context Ptr for screen state context for triggers.
         */
        explicit Unifier(Screen::StateChangeable *context);

        /**
         * @brief Method deletes operator= method.
         * @return Unifier&
         */
        Unifier &operator=(const Unifier &) = delete;

        /**
         * @brief Method uses for components refresh logic.
         */
        virtual void refresh() = 0;

        /**
         * @brief Method adds new player.
         * @param player New player.
         */
        void addPlayer(Mobs::Player *player) noexcept;

        /**
         * @brief Method adds new player.
         * @param player New player.
         */
        void addPlayer(const std::shared_ptr<Mobs::Player> &player) noexcept;

        /**
         * @brief Method removes player.
         * @param player Existing player.
         */
        void removePlayer(const std::shared_ptr<Mobs::Player> &player) noexcept;

        /**
         * @brief Method returns const reference on players collection.
         * @return Const reference on players collection.
         */
        const std::list<std::shared_ptr<Mobs::Player>> &getPlayers() const noexcept;

        //..

        virtual ~Unifier() = default;

    protected:
        /**
         * @brief Do not call "delete" for this ptr. Uses in triggers.
         */
        Screen::StateChangeable *_context;

        /**
         * @brief Players.
         */
        std::list<std::shared_ptr<Mobs::Player>> _players;

        //..
    };
}

#endif //FLASH_UNIFIER_H
