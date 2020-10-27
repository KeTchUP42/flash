//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_GENERATORSELECTOR_H
#define FLASH_GENERATORSELECTOR_H

#include "../generators/Generator.h"
#include "../../../../view/windows/screen/context-abilities/StateChangeable.h"

namespace Generate {

    class GeneratorSelector {
    public:
        explicit GeneratorSelector(Pools::SourcePool &pool, View::StateChangeable *context);

        /**
         * @brief Function contains selecting and creating logic.
         * @param alias Generator's alias.
         * @return Implemented generator.
         */
        Generator *select(const std::string &alias) const noexcept;

        virtual ~GeneratorSelector() = default;

    private:
        Pools::SourcePool &m_pool;
        View::StateChangeable *m_context;
    };
}

#endif //FLASH_GENERATORSELECTOR_H
