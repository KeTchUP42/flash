//
// Created by roman on 02.10.2020.
//

#include "BlockAnalyze.h"

void Generate::
analyzeIniBlock(const IniUtil::Analyzer::IniBlock &data, Pools::SourcePool &sourcePool, sf::RenderWindow &window) {

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
        sourcePool.setVariable(line.first, line.second);
    }
}
