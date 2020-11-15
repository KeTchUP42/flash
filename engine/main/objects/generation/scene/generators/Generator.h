//
// Created by roman on 27.09.2020.
//

#ifndef FLASH_GENERATOR_H
#define FLASH_GENERATOR_H

#include "../pools/SourcePool.h"
#include "../../../unifier/common/Unifier.h"
#include "../../../../view/windows/base/window/Window.h"

namespace Generate {

    /**
     * @brief The base class of the Generator class hierarchy.
     * @namespace Generate
     *
     * This class defines base Generator interface.
    */
    class Generator {
    public:
        Generator(Pools::SourcePool &pool) : m_source(pool) {}

        /**
         * @brief Method generats new object from data and adds it to unifier.
         * @param data Data object.
         * @param unifier Target unifier.
         * @param window Target window.
         */
        virtual void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) = 0;

    protected:
        Pools::SourcePool &m_source;
    };
}

#endif //FLASH_GENERATOR_H
