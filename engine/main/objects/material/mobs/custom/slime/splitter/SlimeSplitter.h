//
// Created by roman on 25.11.2020.
//

#ifndef FLASH_SLIMESPLITTER_H
#define FLASH_SLIMESPLITTER_H

#include <functional>

#include "../../../common/properties/MobProperties.h"
#include "../properties/SlimeProperties.h"

namespace Mobs {
    class Slime;
}

namespace Mobs {

    class SlimeSplitter {
    public:
        SlimeSplitter(float splittingCoefficient);

        /**
          * @brief Method creates a smaller slime uses splitting coefficient.
          * @param slime Base parent slime.
          * @param properties Previously created mob properties object.
          * @param slimeProperties Previously created slime properties object.
          * @return New Slime.
          */
        Slime *split(Mobs::Slime &slime, const Mobs::MobProperties &properties, const Mobs::SlimeProperties &slimeProperties) const;

        virtual ~SlimeSplitter() = default;

    private:
        const float m_splittingCoefficient;
    };
}

#include "../Slime.h"

#endif //FLASH_SLIMESPLITTER_H
