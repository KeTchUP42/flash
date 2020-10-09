//
// Created by roman on 08.09.2020.
//

#ifndef FLASH_PLAYER_H
#define FLASH_PLAYER_H

#include "../../control/KeyAlias.h"
#include "../../../../../auxiliary/components/sprite/primitive/ISpriteBox.h"
#include "../../../../common/MaterialObject.h"
#include "../properties/PlayerProperties.h"
#include "../../../../../auxiliary/possibilities/Physical.h"
#include "../../../../../auxiliary/components/elementary/area/Area.h"

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
    class Player : public Material::MaterialObject,
                   public Possibilities::Physical<Mobs::PlayerProperties> {
    public:
        /**
         * @brief Base player constructor.
         * @param sprite Player's sprite.
         */
        explicit Player(const Mobs::PlayerProperties &properties, const Components::Area &area,
                        const std::shared_ptr<Components::ISpriteBox> &sprite);

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
         * @brief Method changes player's sprite texture.
         * @param texture New texture.
         */
        void loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept;

        bool collision(float x, float y) const noexcept override;

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Components::Point &point) noexcept override;

        void addSpeed(float offsetX, float offsetY) noexcept override;

        void setSpeed(const Components::Speed &speed) noexcept override;

        const Mobs::PlayerProperties &getProperties() const noexcept override;

        const Components::Speed &getSpeed() const noexcept override;

        const Components::Point &getPosition() const noexcept override;

        const Components::Size &getSize() const noexcept override;

        const std::map<KeyAlias, sf::Keyboard::Key> &getKeyMap() const noexcept;

        const std::shared_ptr<Components::ISpriteBox> &getSprite() const noexcept;

        float getRotation() const noexcept override;

        void setPosition(const Components::Point &point) noexcept override;

        void setPosition(float x, float y) noexcept override;

        void setSize(const Components::Size &size) noexcept override;

        void setRotation(float angle) noexcept override;

        virtual ~Player() = default;

    protected:
        Mobs::PlayerProperties m_properties;
        std::map<KeyAlias, sf::Keyboard::Key> m_keyMap;
        Components::Area m_area;
        std::shared_ptr<Components::ISpriteBox> m_sprite;
    };
}

#endif //FLASH_PLAYER_H
