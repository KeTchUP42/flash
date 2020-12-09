//
// Created by roman on 08.09.2020.
//

#ifndef FLASH_PLAYER_H
#define FLASH_PLAYER_H

#include "../../../../../auxiliary/components/sprite/primitive/ISpriteBox.h"
#include "../../../../../auxiliary/components/elementary/area/Area.h"
#include "../../../../../../view/windows/common/observer/Observer.h"
#include "../../../../../auxiliary/possibilities/Peculiar.h"
#include "../../common/control/KeyAlias.h"
#include "../../../common/base/Mob.h"

namespace Mobs {

    /**
     * @brief The class represents the base class of all controlled mobs - players.
     * @namespace Mobs
     *
     * This class defines base Player interface and realization.
    */
    class Player : public Mobs::Mob,
                   public View::Observer<sf::Event, View::Window> {
    public:
        /**
         * @brief Default player constructor.
         * @param material_properties Material properties.
         * @param properties Mob properties object.
         * @param area Mob physical area.
         * @param sprite Player's sprite.
         */
        explicit Player(const Material::MaterialProperties &material_properties,
                        const Mobs::MobProperties &properties,
                        const Components::Area &area,
                        const std::shared_ptr<Components::ISpriteBox> &sprite);

        /**
         * @brief Method loads new player's key map. Keys under special names used in player's controlling.
         * @param keyMap New key-map.
         */
        void loadKeyMap(const std::map<KeyAlias, sf::Keyboard::Key> &keyMap) noexcept;

        /**
         * @brief Method returns player's keymap.
         * @return KeyMap.
         */
        const std::map<KeyAlias, sf::Keyboard::Key> &getKeyMap() const noexcept;

        /**
         * @brief Method contains event handling player logic.
         * @param event Event object.
         * @param unifier Scene unifier.
         */
        virtual void handleEvent(const sf::Event &event, Unite::Unifier *unifier) noexcept = 0;

        /**
         * @brief Method calls "handleEvent" method for all caught events.
         * @param unifier Scene unifier.
         */
        void handleEventsList(Unite::Unifier *unifier);

        /**
         * @brief Method catches all window events and puts them to m_events list.
         * @param event Window event.
         * @param sender Window object.
         */
        void update(const sf::Event &event, View::Window &sender) override;

        virtual ~Player() = default;

    protected:
        std::map<KeyAlias, sf::Keyboard::Key> m_keyMap;
        std::list<sf::Event> m_events;
    };
}

#endif //FLASH_PLAYER_H
