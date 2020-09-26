//
// Created by roman on 12.09.2020.
//

#ifndef FLASH_COLLISIONSTRATEGY_H
#define FLASH_COLLISIONSTRATEGY_H

#include "../../../unifier/common-base/Unifier.h"

namespace Material {

    /**
     * @brief The base class of the CollisionStrategy class hierarchy. These classes contains collision algorithms.
     * @namespace Material
     *
     * This class defines base CollisionStrategy interface.
    */
    template<class Processed, class Result>
    class CollisionStrategy {
    public:
        CollisionStrategy(Unite::Unifier *unifier) : _unifier(unifier) {}

        /**
         * @brief Method checks move able for "X" line.
         * @param object Processed object.
         */
        virtual Result abscissaMoveAble(Processed object) const noexcept = 0;

        /**
         * @brief Method checks move able for "Y" line.
         * @param object Processed object.
         */
        virtual Result ordinateMoveAble(Processed object) const noexcept = 0;

        virtual ~CollisionStrategy() = default;

    protected:
        Unite::Unifier *_unifier;
    };
}

#endif //FLASH_COLLISIONSTRATEGY_H
