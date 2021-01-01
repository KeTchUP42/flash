//
// Created by roman on 27.09.2020.
//

#ifndef FLASH_GENERATOR_H
#define FLASH_GENERATOR_H

#include "../pools/SourcePool.h"
#include "../../../unifier/common/Unifier.h"
#include "../../../../view/windows/common/window/Window.h"

namespace Creation {

    /**
     * @brief The base class of the Generators class hierarchy which use for scene objects creation.
     * @namespace Creation
     *
     * This class defines base Generator interface.
    */
    class Generator {
    public:
        explicit Generator(Pools::SourcePool &pool) : m_source(pool) {}

        /**
         * @brief Method generats new object from data and adds it to unifier.
         * @param data Ini data block.
         * @param unifier Target scene unifier.
         * @param window Target window.
         */
        virtual void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) = 0;

        virtual ~Generator() = default;

    protected:
        Pools::SourcePool &m_source;
    };
}

#endif //FLASH_GENERATOR_H
