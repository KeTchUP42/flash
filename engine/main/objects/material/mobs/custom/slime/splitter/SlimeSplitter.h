//
// Created by roman on 25.11.2020.
//

#ifndef FLASH_SLIMESPLITTER_H
#define FLASH_SLIMESPLITTER_H

#include "../../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../properties/SlimeMobProperties.h"
#include "../../../common/base/AnalyzingMob.h"

namespace Mobs {

    /**
     * @brief Pre-announcement of an incomplete Slime type to prevent cyclic dependence.
     */
    class Slime;

    /**
     * @brief The class is responsible for encapsulating the code associated with slime splitting.
     * @namespace Mobs
     *
     * This class defines SlimeSplitter realization.
    */
    class SlimeSplitter {
    public:
        /**
         * @brief Default constructor.
         * @param splittingCoefficient Splitting coefficient.
         */
        explicit SlimeSplitter(float splittingCoefficient);

        /**
         * @brief Method returns split slime area.
         * @param slime Main parent slime.
         * @return New slime area.
         */
        Components::Area splitArea(const Mobs::Slime &slime) const noexcept;

        /**
         * @brief Method returns split slime sprite.
         * @param slime Main parent slime.
         * @return New slime sprite.
         */
        std::shared_ptr<Components::ISpriteBox> splitSprite(const Mobs::Slime &slime) const noexcept;

        /**
         * @brief Method returns split slime algorithms.
         * @param slime Main parent slime.
         * @return New algorithms.
         */
        std::shared_ptr<Material::Algorithms> splitAlgorithms(const Mobs::Slime &slime) const noexcept;

        /**
         * @brief Method returns split slime properties.
         * @param properties Main slime properties.
         * @return New slime properties.
         */
        Mobs::SlimeProperties splitProperties(const Mobs::SlimeProperties &properties) const noexcept;

    private:
        const float SPLITTING_COEFFICIENT;
    };

    /**
     * @brief Function creates a smaller slime uses splitting coefficient.
     * @param splitter Slime configured splitter.
     * @param slime Parent slime.
     * @param properties All slime properties data.
     * @return New Slime.
     */
    std::shared_ptr<Slime> split(const Mobs::SlimeSplitter &splitter, const Mobs::Slime &slime, const Mobs::SlimeMobProperties &properties);
}

#include "../Slime.h"

#endif //FLASH_SLIMESPLITTER_H
