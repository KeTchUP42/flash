//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_ALGORITHMSPOOL_H
#define FLASH_ALGORITHMSPOOL_H

#include <string>
#include <memory>
#include <map>

#include "../../../material/common/collision/Collision.h"

namespace Generate {

    namespace Pools {

        /**
         * @brief The AlgorithmsPool class.
         * @namespace Pools
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

        protected:
            /**
             * @brief Collision cache.
             */
            std::map<std::pair<float, float>, std::shared_ptr<Material::Collision>> m_collision;
        };
    }
}
#endif //FLASH_ALGORITHMSPOOL_H
