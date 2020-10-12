//
// Created by roman on 12.10.2020.
//

#include "TextGenerator.h"
#include "../../../../../../utils/math/algorithms.h"

Generate::TextGenerator::TextGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

static sf::Color color(const std::vector<std::string> &color) noexcept;

static sf::Text::Style style(const std::string &style) noexcept;

void Generate::TextGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    using namespace Components;
    Text *text = new Text(data.at("STRING"), m_source.getFont(data.at("FONT")));
    text->getText().setPosition(std::atof(data.at("X").c_str()), std::atof(data.at("Y").c_str()));
    text->getText().rotate(std::atof(data.at("ANGLE").c_str()));
    text->getText().setCharacterSize(std::atoi(data.at("CHARACTER_SIZE").c_str()));
    text->getText().setOutlineColor(color(MathUtils::split(data.at("OUTLINE_COLOR"), ':')));
    text->getText().setFillColor(color(MathUtils::split(data.at("FILL_COLOR"), ':')));
    text->getText().setLetterSpacing(std::atof(data.at("LETTER_SPACING").c_str()));
    text->getText().setLineSpacing(std::atof(data.at("LINE_SPACING").c_str()));
    text->getText().setOutlineThickness(std::atof(data.at("OUTLINE_THICKNESS").c_str()));
    text->getText().setStyle(style(data.at("STYLE")));
    unifier.addText(text);
}

static sf::Color color(const std::vector<std::string> &color) noexcept {
    sf::Uint8 r = std::atoi(color.at(0).c_str());
    sf::Uint8 g = std::atoi(color.at(1).c_str());
    sf::Uint8 b = std::atoi(color.at(2).c_str());
    sf::Uint8 alpha = std::atoi(color.at(3).c_str());
    return sf::Color(r, g, b, alpha);
}

static sf::Text::Style style(const std::string &style) noexcept {
    if (style == "Bold")
        return sf::Text::Style::Bold;
    if (style == "Italic")
        return sf::Text::Style::Italic;
    if (style == "Underlined")
        return sf::Text::Style::Underlined;
    if (style == "StrikeThrough")
        return sf::Text::Style::StrikeThrough;
    return sf::Text::Style::Regular;
}