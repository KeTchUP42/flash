//
// Created by roman on 12.10.2020.
//

#ifndef FLASH_REDUCING_H
#define FLASH_REDUCING_H

#include "../../../../auxiliary/components/elementary/area/Area.h"
#include "../../../../../../utils/Ini/analyzer/Analyzer.h"

namespace Generate {

    /**
     * @brief Function generates general objects area.
     * @param data Ini data.
     * @return Physical area.
     */
    Components::Area physicalArea(const IniUtil::Analyzer::IniBlock &data) noexcept;

    /**
     * @brief Function generates sprite area.
     * @param data Ini data.
     * @return Sprite area.
     */
    Components::Area spriteArea(const IniUtil::Analyzer::IniBlock &data) noexcept;
}
#endif //FLASH_AREA_H
