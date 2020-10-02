//
// Created by roman on 02.10.2020.
//

#include "WindowConfigurator.h"

Generating::WindowConfigurator::WindowConfigurator(Generating::SourcePool &sourcePool)
        : m_source_pool(sourcePool) {}

void Generating::WindowConfigurator::configure(const IniUtil::Analyzer::IniBlock &data, sf::RenderWindow &window) {

    for (const auto &line : data) {
        if (line.first == "SET_TITLE") window.setTitle(line.second);
        if (line.first == "SET_RENDER_WIDTH") {
            window.setSize(sf::Vector2<unsigned int>(std::atoi(line.second.c_str()), window.getSize().y));
        }
        if (line.first == "SET_RENDER_HEIGHT") {
            window.setSize(sf::Vector2<unsigned int>(window.getSize().x, std::atoi(line.second.c_str())));
        }
        if (line.first == "SET_FPS") window.setFramerateLimit(std::atoi(line.second.c_str()));
    }
}
