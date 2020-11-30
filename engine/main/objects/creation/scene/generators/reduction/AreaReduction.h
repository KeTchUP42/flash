//
// Created by roman on 12.10.2020.
//

#ifndef FLASH_AREA_REDUCTION_H
#define FLASH_AREA_REDUCTION_H

#include "../../../../auxiliary/components/elementary/area/Area.h"
#include "../../../../../../utils/Ini/analyzer/Analyzer.h"

namespace Creation {
    namespace RD {
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

        /**
         * @brief Function generates area.
         * @param data Ini data.
         * @param position Position field name.
         * @param size Size field name.
         * @param angle Angle field name.
         * @return Area.
         */
        Components::Area area(const IniUtil::Analyzer::IniBlock &data, const std::string &position, const std::string &size, const std::string &angle);
    }
}
#endif //FLASH_AREA_REDUCTION_H
