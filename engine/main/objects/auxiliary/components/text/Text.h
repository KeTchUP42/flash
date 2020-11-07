//
// Created by roman on 11.10.2020.
//

#ifndef FLASH_TEXT_H
#define FLASH_TEXT_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "../../possibilities/Drawable.h"
#include "../../possibilities/Moving.h"
#include "../../possibilities/Rotatable.h"

namespace Components {

    /**
     * @brief Class for work with visual text information.
     * @namespace Components
     *
     * This class is a wrap for sf::Text from SFML.
    */
    class Text : public Possibilities::Moving,
                 public Possibilities::Drawable<sf::RenderTarget> {
    public:
        explicit Text(const std::string &string, sf::Font *font);

        explicit Text(const std::string &string, const std::shared_ptr<sf::Font> &font);

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        /**
         * @brief Method returns pointer for original sf::Text object.
         * @return sf::Text pointer.
         */
        sf::Text &getText() const noexcept;

    private:
        std::shared_ptr<sf::Font> m_font;
        std::shared_ptr<sf::Text> m_text;
    };
}

#endif //FLASH_TEXT_H
