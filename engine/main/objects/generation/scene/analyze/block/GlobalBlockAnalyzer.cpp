//
// Created by roman on 02.10.2020.
//

#include "GlobalBlockAnalyzer.h"

Generate::GlobalBlockAnalyzer::GlobalBlockAnalyzer(Generate::Pools::SourcePool &sourcePool)
        : m_source_pool(sourcePool) {}

void Generate::GlobalBlockAnalyzer::analyze(const IniUtil::Analyzer::IniBlock &data, sf::RenderWindow &window) {

    for (const auto &line : data) {
        if (line.first == "SET_TITLE") {
            window.setTitle(line.second);
            continue;
        }
        if (line.first == "SET_RENDER_WIDTH") {
            window.setSize(sf::Vector2<unsigned int>(std::atoi(line.second.c_str()), window.getSize().y));
            continue;
        }
        if (line.first == "SET_RENDER_HEIGHT") {
            window.setSize(sf::Vector2<unsigned int>(window.getSize().x, std::atoi(line.second.c_str())));
            continue;
        }
        if (line.first == "SET_FPS") {
            window.setFramerateLimit(std::atoi(line.second.c_str()));
            continue;
        }
        //..
        m_source_pool.setVariable(line.first, line.second);
    }
}
