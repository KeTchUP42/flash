//
// Created by roman on 12.10.2020.
//

#ifndef FLASH_AREA_REDUCTION_H
#define FLASH_AREA_REDUCTION_H

#include "../../../../auxiliary/components/elementary/area/Area.h"
#include "../../../../../../utils/Ini/analyzer/Analyzer.h"

namespace Generate {

    /**
     * @brief Function generates general objects area.
     * @param data Ini data.
     * @return Common area.
     */
    Components::Area commonArea(const IniUtil::Analyzer::IniBlock &data);

    /**
     * @brief Function generates sprite area.
     * @param data Ini data.
     * @return Sprite area.
     */
    Components::Area spriteArea(const IniUtil::Analyzer::IniBlock &data);
}
#endif //FLASH_AREA_REDUCTION_H
