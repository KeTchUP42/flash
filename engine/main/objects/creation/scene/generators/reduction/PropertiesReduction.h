//
// Created by roman on 12.10.2020.
//

#ifndef FLASH_PROPERTIES_REDUCTION_H
#define FLASH_PROPERTIES_REDUCTION_H

#include "../../../../material/common/properties/MaterialProperties.h"
#include "../../../../material/mobs/common/properties/MobProperties.h"
#include "../../../../material/obstacles/common/properties/ObstacleProperties.h"
#include "../../../../../../utils/Ini/analyzer/Analyzer.h"

namespace Creation {
    namespace RD {
        /**
         * @brief  Function creates MaterialProperties object from given data.
         * @param data Ini data.
         * @return New MaterialProperties object.
         */
        Material::MaterialProperties loadMaterialProperties(const IniUtil::Analyzer::IniBlock &data);

        /**
         * @brief Function creates MobProperties object from given data.
         * @param data Ini data.
         * @return New MobProperties object.
         */
        Mobs::MobProperties loadMobProperties(const IniUtil::Analyzer::IniBlock &data);

        /**
         * @brief Function creates ObstacleProperties object from given data.
         * @param data Ini data.
         * @return New ObstacleProperties object.
         */
        Obstacles::ObstacleProperties loadObstacleProperties(const IniUtil::Analyzer::IniBlock &data);
    }
}

#endif //FLASH_PROPERTIES_REDUCTION_H
