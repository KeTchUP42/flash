//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_ALGORITHMSPOOL_H
#define FLASH_ALGORITHMSPOOL_H

#include "../../../material/common/collision/Collision.h"

namespace Creation {

    namespace Pools {

        /**
         * @brief The class allows caching objects that represent wrappers for algorithms.
         * @namespace Creation::Pools
         *
         * This class defines AlgorithmsPool realization.
        */
        class AlgorithmsPool {
        public:
            /**
             * @brief Method loads collsion.
             * @return Collision.
             */
            std::shared_ptr<Material::Collision> loadCollision(const std::pair<float, float> &params) noexcept;

        private:
            /**
             * @brief Collision cache.
             */
            std::map<std::pair<float, float>, std::shared_ptr<Material::Collision>> m_collision;
        };
    }
}
#endif //FLASH_ALGORITHMSPOOL_H
