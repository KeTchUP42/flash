//
// Created by roman on 12.10.2020.
//

#include "area.h"

Components::Area Generate::physicalArea(const IniUtil::Analyzer::IniBlock &data) noexcept {
    Components::Point point(std::stof(data.at("X")), std::stof(data.at("Y")));
    Components::Size size(std::atoi(data.at("WIDTH").c_str()), std::atoi(data.at("HEIGHT").c_str()));
    float angle = std::stof(data.at("ANGLE"));
    return Components::Area(point, size, angle);
}

Components::Area Generate::spriteArea(const IniUtil::Analyzer::IniBlock &data) noexcept {
    Components::Point point(std::stof(data.at("SPRITE_X")), std::stof(data.at("SPRITE_Y")));
    Components::Size size(std::atoi(data.at("SPRITE_WIDTH").c_str()), std::atoi(data.at("SPRITE_HEIGHT").c_str()));
    float angle = std::stof(data.at("ANGLE"));
    return Components::Area(point, size, angle);
}
