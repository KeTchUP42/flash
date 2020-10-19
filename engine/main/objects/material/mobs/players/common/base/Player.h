//
// Created by roman on 08.09.2020.
//

#ifndef FLASH_PLAYER_H
#define FLASH_PLAYER_H

#include "../../../../../auxiliary/components/sprite/primitive/ISpriteBox.h"
#include "../../../../../auxiliary/components/elementary/area/Area.h"
#include "../../../../../../view/windows/base/observer/Observer.h"
#include "../../../../../auxiliary/possibilities/Physical.h"
#include "../../../common/base/Mob.h"
#include "../../control/KeyAlias.h"

namespace Mobs {

    /**
     * @brief The class represents the base class of all managed mobiles - players.
     * @namespace Mobs
     *
     * This class defines base Player interface and realization.
    */
    class Player : public Mobs::Mob,
                   public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        /**
         * @brief Base player constructor.
         * @param sprite Player's sprite.
         */
        explicit Player(const Mobs::MobProperties &properties, const Components::Area &area,
                        const std::shared_ptr<Components::ISpriteBox> &sprite);

        /**
         * @brief Method loads new player's key map. Keys under special names used in player's controlling.
         * @param keyMap New key-map.
         */
        void loadKeyMap(const std::map<KeyAlias, sf::Keyboard::Key> &keyMap) noexcept;

        /**
         * @brief Method loads key map from config file. Method created for easier player configuring.
         * @param filename Config file name.
         * @param manager Manager for data search.
         */
        virtual void loadKeyMap(const std::string &filename, Managers::DataManager *manager) = 0;

        /**
         * @brief Method returns player's keymap.
         * @return KeyMap.
         */
        const std::map<KeyAlias, sf::Keyboard::Key> getKeyMap() const noexcept;

        virtual ~Player() = default;

    protected:
        std::map<KeyAlias, sf::Keyboard::Key> m_keyMap;
    };
}

#endif //FLASH_PLAYER_H
