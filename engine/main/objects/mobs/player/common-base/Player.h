//
// Created by roman on 08.09.2020.
//

#ifndef FLASH_PLAYER_H
#define FLASH_PLAYER_H

#include "../../shared/Mob.h"
#include "../control/KeyAlias.h"
#include "../../../auxiliary/components/sprite/common/box/ISpriteBox.h"

#include <map>
#include <string>
#include <memory>

namespace Mobs {

    /**
     * @brief The base class of the Player class hierarchy.
     * @namespace Mobs
     *
     * This class defines base Player interface.
    */
    class Player : public Mob {
    public:
        /**
         * @brief Base player constructor.
         * @param sprite Player's sprite.
         */
        explicit Player(const std::shared_ptr<Components::ISpriteBox> &sprite);

        /**
         * @brief Method loads new player's key map. Keys under special names used in player's controlling.
         * @param keyMap New key-map.
         */
        void loadKeyMap(const std::map<KeyAlias, sf::Keyboard::Key> &keyMap) noexcept;

        /**
         * @brief Method loads key map from config file.
         * @param filename Config file name.
         * @param manager Manager for data search.
         */
        virtual void loadKeyMap(const std::string &filename, Managers::DataManager *manager) = 0;

        /**
         * @brief Method changes player's sprite.
         * @param texture New sprite.
         */
        void loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept;

        bool collision(float x, float y) const noexcept override;

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Components::Point &point) noexcept override;

        void addSpeed(float offsetX, float offsetY) noexcept override;

        void setMoveSpeed(const Components::Speed &speed) noexcept override;

        const Components::Speed &getMoveSpeed() const noexcept override;

        const Components::Point &getPosition() const noexcept override;

        const Components::Size &getSize() const noexcept override;

        float getRotation() const noexcept override;

        virtual ~Player() = default;

    protected:
        Components::Speed _speed;
        std::map<KeyAlias, sf::Keyboard::Key> _keyMap;
        std::shared_ptr<Components::ISpriteBox> _sprite;
    };
}

#endif //FLASH_PLAYER_H
