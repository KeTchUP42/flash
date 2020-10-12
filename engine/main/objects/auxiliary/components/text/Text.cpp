//
// Created by roman on 11.10.2020.
//

#include "Text.h"

Components::Text::Text(const std::string &string, sf::Font *font)
        : m_font(font), m_text(new sf::Text(string, *font)) {}

Components::Text::Text(const std::string &string, const std::shared_ptr<sf::Font> &font)
        : m_font(font), m_text(new sf::Text(string, *font)) {}

void Components::Text::draw(sf::RenderTarget &target) const noexcept {
    target.draw(*m_text, sf::RenderStates::Default);
}

void Components::Text::move(float offsetX, float offsetY) noexcept {
    m_text->move(offsetX, offsetY);
}

sf::Text &Components::Text::getText() const noexcept {
    return *m_text;
}
