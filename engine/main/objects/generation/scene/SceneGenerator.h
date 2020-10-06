//
// Created by roman on 27.09.2020.
//

#ifndef FLASH_SCENEGENERATOR_H
#define FLASH_SCENEGENERATOR_H

#include "../../../view/windows/screen/context-abilities/StateChangeable.h"
#include "../../../data/manager/DataManager.h"
#include "../../unifier/common/Unifier.h"
#include "generators/Generator.h"
#include "pools/GeneratorsPool.h"
#include "pools/SourcePool.h"
#include "analyze/BlockAnalyzer.h"

namespace Generate {

    /**
     * @brief The SceneGenerator class.
     * @namespace Generate
     *
     * This class defines SceneGenerator realization.
    */
    class SceneGenerator {
    public:
        explicit SceneGenerator(Screen::StateChangeable *context, Managers::DataManager *manager);

        /**
         * @brief Method fills Unifier with objects.
         * @param filename Config file path.
         * @param unifier Unifier.
         * @param target Target render window.
         */
        void loadScene(const std::string &filename, Unite::Unifier &unifier, sf::RenderWindow &target);

    protected:
        /**
         * @brief Source pool.
         */
        Pools::SourcePool m_source_pool;

        /**
         * @brief Block analyzer.
         */
        Generate::BlockAnalyzer m_analyzer;

        /**
         * @brief Generators pool.
         */
        Pools::GeneratorsPool m_generators_pool;

        /**
         * @brief Do not call "delete" for this ptr.
         */
        Managers::DataManager *m_manager;
    };
}

#endif //FLASH_SCENEGENERATOR_H
