//
// Created by roman on 12.10.2020.
//

#include "AreaReduction.h"
#include "ElementaryReduction.h"

Components::Area Generate::physicalArea(const IniUtil::Analyzer::IniBlock &data) {
    float angle = std::stof(data.at("ANGLE"));
    return Components::Area(position(data, "POSITION"), size(data, "SIZE"), angle);
}

Components::Area Generate::spriteArea(const IniUtil::Analyzer::IniBlock &data) {
    float angle = std::stof(data.at("SPRITE_ANGLE"));
    return Components::Area(position(data, "SPRITE_POSITION"), size(data, "SPRITE_SIZE"), angle);
}
