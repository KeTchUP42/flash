//
// Created by roman on 25.11.2020.
//

#ifndef FLASH_SLIMESPLITTER_H
#define FLASH_SLIMESPLITTER_H

#include "../../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../../../common/base/AnalyzingMob.h"
#include "../../../common/properties/MobProperties.h"
#include "../properties/SlimeProperties.h"

namespace Mobs {
    class Slime;
}

namespace Mobs {

    class SlimeSplitter {
    public:
        /**
         * @brief Default constructor.
         * @param splittingCoefficient Splitting coefficient.
         */
        SlimeSplitter(float splittingCoefficient);

        /**
         * @brief All slime properties.
         */
        struct SlimeProperties {
            Material::MaterialProperties material_properties;
            Mobs::MobProperties mob_properties;
            Mobs::SlimeProperties slime_properties;
        };

        /**
          * @brief Method creates a smaller slime uses splitting coefficient.
          * @param slime Main parent slime.
          * @param properties All slime properties data.
          * @return New Slime.
          */
        Slime *split(Mobs::Slime &slime, const SlimeProperties &properties) const;

        /**
         * @brief Method returns split slime area.
         * @param slime Main parent slime.
         * @return New slime area.
         */
        Components::Area splitSlimeArea(Mobs::Slime &slime) const noexcept;

        /**
         * @brief Method returns split slime sprite.
         * @param slime Main parent slime.
         * @return New slime sprite.
         */
        std::shared_ptr<Components::ISpriteBox> splitSlimeSprite(Mobs::Slime &slime) const noexcept;

        /**
         * @brief Method returns split slime algorithms.
         * @param slime Main parent slime.
         * @return New algorithms.
         */
        std::shared_ptr<Material::Algorithms> splitSlimeAlgorithms(Mobs::Slime &slime) const noexcept;

        /**
         * @brief Method returns split slime properties.
         * @param properties Main slime properties.
         * @return New slime properties.
         */
        Mobs::SlimeProperties splitSlimeProperties(const Mobs::SlimeProperties &properties) const noexcept;

        virtual ~SlimeSplitter() = default;

    private:
        const float SPLITTING_COEFFICIENT;
    };
}

#include "../Slime.h"

#endif //FLASH_SLIMESPLITTER_H
