//
// Created by roman on 27.09.2020.
//

#ifndef FLASH_GENERATOR_H
#define FLASH_GENERATOR_H

#include "../pools/SourcePool.h"
#include "../../../unifier/common/Unifier.h"

namespace Generate {

    /**
     * @brief The base class of the Generator class hierarchy.
     * @namespace Generate
     *
     * This class defines base Generator interface.
    */
    class Generator {
    public:
        Generator(Pools::SourcePool &pool) : m_sourcePool(pool) {}

        /**
         * @brief Method generats new object from data and adds it to unifier.
         * @param data Object data.
         * @param unifier Target unifier.
         */
        virtual void
        load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) = 0;

    protected:
        Pools::SourcePool &m_sourcePool;
    };
}

#endif //FLASH_GENERATOR_H
