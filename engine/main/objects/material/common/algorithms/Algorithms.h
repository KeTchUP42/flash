//
// Created by roman on 28.09.2020.
//

#ifndef FLASH_ALGORITHMS_H
#define FLASH_ALGORITHMS_H

#include "../collision/Collision.h"

namespace Material {

    /**
     * @brief The Algorithms class. Class contains all algorithms facade class objects.
     * @namespace Material
     *
     * This class defines Algorithms realization.
    */
    class Algorithms {
    public:
        explicit Algorithms(const std::shared_ptr<Material::Collision> &collision);

        /**
         * @brief Method returns collision algorithms facade class object.
         */
        const Material::Collision &getCollision() const;

        virtual ~Algorithms() = default;

    protected:
        std::shared_ptr<Material::Collision> m_collision;
    };
}

#endif //FLASH_ALGORITHMS_H
