//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_GENERATORSPOOL_H
#define FLASH_GENERATORSPOOL_H

#include "../generators/Generator.h"
#include "../../../../view/windows/screen/context-abilities/StateChangeable.h"

#include <map>
#include <memory>
#include <string>

namespace Generating {

    /**
     * @brief The GeneratorsPool class.
     * @namespace Generating
     *
     * This class defines GeneratorsPool realization.
    */
    class GeneratorsPool {
    public:
        explicit GeneratorsPool(SourcePool &pool, Screen::StateChangeable *context);

        /**
         * @brief Method returns generator under alias.
         * @param alias Generator's alias.
         * @return Generator pointer.
         */
        std::shared_ptr<Generator> load(const std::string &alias) noexcept;

    protected:
        /**
         * @brief Source pool.
         */
        SourcePool &m_pool;

        /**
         * @brief Cache with generators.
         */
        std::map<std::string, std::shared_ptr<Generator>> m_generators;

        /**
         * @brief Do not call "delete" for this ptr.
         */
        Screen::StateChangeable *m_context;
    };
}

#endif //FLASH_GENERATORSPOOL_H
