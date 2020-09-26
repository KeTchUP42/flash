//
// Created by roman on 12.09.2020.
//

#ifndef FLASH_COLLISIONSTRATEGY_H
#define FLASH_COLLISIONSTRATEGY_H

namespace Unite {
    class Unifier;
}

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
        /**
         * @brief Method checks move able for "X" line.
         * @param object Processed object.
         */
        virtual Result abscissaMoveAble(Processed object, Unite::Unifier *unifier) const noexcept = 0;

        /**
         * @brief Method checks move able for "Y" line.
         * @param object Processed object.
         */
        virtual Result ordinateMoveAble(Processed object, Unite::Unifier *unifier) const noexcept = 0;

        virtual ~CollisionStrategy() = default;
    };
}

#include "../../../unifier/common-base/Unifier.h"

#endif //FLASH_COLLISIONSTRATEGY_H
