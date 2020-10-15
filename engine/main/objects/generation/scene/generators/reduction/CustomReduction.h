//
// Created by roman on 13.10.2020.
//

#ifndef FLASH_ALGORITHMS_REDUCTION_H
#define FLASH_ALGORITHMS_REDUCTION_H

#include "../../../../material/common/algorithms/Algorithms.h"
#include "../../pools/SourcePool.h"

namespace Generate {

    /**
     * @brief Function loads algorithms facade class object form given data.
     * @param data Ini data.
     * @param pool Source pool.
     * @return New Algorithms object.
     */
    std::shared_ptr<Material::Algorithms> loadAlgorithms(const IniUtil::Analyzer::IniBlock &data, Generate::Pools::SourcePool &pool);

    /**
     * @brief Function loads and configures sf::Music class object.
     * @param data Ini data.
     * @param pool Source pool.
     * @return New sf::Music object.
     */
    std::shared_ptr<sf::Music> loadMusic(const IniUtil::Analyzer::IniBlock &data, Generate::Pools::SourcePool &pool);
}

#endif //FLASH_ALGORITHMS_REDUCTION_H
