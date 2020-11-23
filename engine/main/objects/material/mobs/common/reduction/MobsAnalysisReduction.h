//
// Created by roman on 23.11.2020.
//

#ifndef FLASH_MOBSANALYSISREDUCTION_H
#define FLASH_MOBSANALYSISREDUCTION_H

#include "../base/Mob.h"

namespace Mobs {
    namespace RD {
        /**
         * @brief The function contains the logic of analysis and verification of object health. It can correct it if necessary.
        */
        void healthAnalysis(Mobs::Mob &mob) noexcept;
    }
}
#endif //FLASH_MOBSANALYSISREDUCTION_H
