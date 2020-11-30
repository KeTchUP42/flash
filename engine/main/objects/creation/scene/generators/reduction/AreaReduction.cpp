//
// Created by roman on 12.10.2020.
//

#include "AreaReduction.h"
#include "ElementaryReduction.h"

Components::Area Creation::RD::commonArea(const IniUtil::Analyzer::IniBlock &data) {
    float angle = std::stof(data.at("ANGLE"));
    return Components::Area(RD::position(data, "POSITION"), RD::size(data, "SIZE"), angle);
}

Components::Area Creation::RD::spriteArea(const IniUtil::Analyzer::IniBlock &data) {
    float angle = std::stof(data.at("SPRITE_ANGLE"));
    return Components::Area(RD::position(data, "SPRITE_POSITION"), RD::size(data, "SPRITE_SIZE"), angle);
}

Components::Area Creation::RD::area(const IniUtil::Analyzer::IniBlock &data, const std::string &position, const std::string &size, const std::string &angle) {
    return Components::Area(RD::position(data, position), RD::size(data, size), std::stof(data.at(angle)));
}
