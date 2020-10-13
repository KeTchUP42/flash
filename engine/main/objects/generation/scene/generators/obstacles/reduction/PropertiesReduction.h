//
// Created by roman on 12.10.2020.
//

#ifndef FLASH_PROPERTIES_REDUCTION_H
#define FLASH_PROPERTIES_REDUCTION_H

#include "../../../../../material/obstacles/common/properties/ObstacleProperties.h"
#include "../../../../../../../utils/Ini/analyzer/Analyzer.h"

namespace Generate {

    /**
     * @brief Function creates ObstacleProperties object from given data.
     * @param data Ini data.
     * @return New ObstacleProperties object.
     */
    Obstacles::ObstacleProperties loadObstacleProperties(const IniUtil::Analyzer::IniBlock &data) noexcept;
}

#endif //FLASH_PROPERTIES_REDUCTION_H
