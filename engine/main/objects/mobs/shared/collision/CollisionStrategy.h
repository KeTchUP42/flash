//
// Created by roman on 12.09.2020.
//

#ifndef FLASH_COLLISIONSTRATEGY_H
#define FLASH_COLLISIONSTRATEGY_H

#include "../../../unifier/common-base/Unifier.h"
#include "../Mob.h"

namespace Mobs {

    /**
     * @brief The base class of the CollisionStrategy class hierarchy. These classes contains collision algorithms.
     * @namespace Mobs
     *
     * This class defines base CollisionStrategy interface.
    */
    template<typename Result>
    class CollisionStrategy {
    public:
        CollisionStrategy(Unite::Unifier *unifier) : _unifier(unifier) {}

        /**
         * @brief Method checks move able for "X" line.
         * @param mob Processed mob.
         */
        virtual Result abscissaMoveAble(Mob *mob) const noexcept = 0;

        /**
         * @brief Method checks move able for "Y" line.
         * @param mob Processed mob.
         */
        virtual Result ordinateMoveAble(Mob *mob) const noexcept = 0;

        virtual ~CollisionStrategy() = default;

    protected:
        Unite::Unifier *_unifier;
    };
}

#endif //FLASH_COLLISIONSTRATEGY_H
