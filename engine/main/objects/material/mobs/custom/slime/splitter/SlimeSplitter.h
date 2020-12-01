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
         * @brief All slime properties data.
         */
        struct SlimeProperties {
            Material::MaterialProperties material_properties;
            Mobs::MobProperties mob_properties;
            Mobs::SlimeProperties slime_properties;
        };

        /**
          * @brief Method creates a smaller slime uses splitting coefficient.
          * @param slime Base parent slime.
          * @param properties All slime properties data.
          * @return New Slime.
          */
        Slime *split(Mobs::Slime &slime, const SlimeProperties &properties) const;

        virtual ~SlimeSplitter() = default;

    private:
        const float m_splittingCoefficient;
    };
}

#include "../Slime.h"

#endif //FLASH_SLIMESPLITTER_H
