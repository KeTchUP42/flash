//
// Created by roman on 12.10.2020.
//

#ifndef FLASH_PROPERTIES_REDUCTION_H
#define FLASH_PROPERTIES_REDUCTION_H

#include "../../../../material/obstacles/common/properties/ObstacleProperties.h"
#include "../../../../material/mobs/player/common/properties/PlayerProperties.h"
#include "../../../../material/mobs/monsters/common/properties/MonsterProperties.h"
#include "../../../../../../utils/Ini/analyzer/Analyzer.h"

namespace Generate {

    /**
     * @brief Function creates MonsterProperties object from given data.
     * @param data Ini data.
     * @return New MonsterProperties object.
     */
    Mobs::MonsterProperties loadMonsterProperties(const IniUtil::Analyzer::IniBlock &data);

    /**
     * @brief Function creates PlayerProperties object from given data.
     * @param data Ini data.
     * @return New PlayerProperties object.
     */
    Mobs::PlayerProperties loadPlayerProperties(const IniUtil::Analyzer::IniBlock &data);

    /**
     * @brief Function creates ObstacleProperties object from given data.
     * @param data Ini data.
     * @return New ObstacleProperties object.
     */
    Obstacles::ObstacleProperties loadObstacleProperties(const IniUtil::Analyzer::IniBlock &data);
}

#endif //FLASH_PROPERTIES_REDUCTION_H
