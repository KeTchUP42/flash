//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_GENERATORSPOOL_H
#define FLASH_GENERATORSPOOL_H

#include "../generators/Generator.h"
#include "../../../../view/windows/screen/context-abilities/StateChangeable.h"
#include "../analyze/GeneratorSelector.h"

#include <map>
#include <memory>
#include <string>

namespace Generate {

    namespace Pools {

        /**
         * @brief The GeneratorsPool class.
         * @namespace Pools
         *
         * This class defines GeneratorsPool realization.
        */
        class GeneratorsPool {
        public:
            explicit GeneratorsPool(SourcePool &pool, Screen::StateChangeable *context);

            /**
             * @brief Method returns generator with alias.
             * @param alias Generator's alias.
             * @return Generator's pointer.
             */
            std::shared_ptr<Generator> load(const std::string &alias);

        protected:
            /**
             * @brief Generators selector.
             */
            Generate::GeneratorSelector m_selector;

            /**
             * @brief Cache with generators.
             */
            std::map<std::string, std::shared_ptr<Generator>> m_generators;
        };
    }
}
#endif //FLASH_GENERATORSPOOL_H
