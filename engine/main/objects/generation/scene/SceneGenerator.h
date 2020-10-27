//
// Created by roman on 27.09.2020.
//

#ifndef FLASH_SCENEGENERATOR_H
#define FLASH_SCENEGENERATOR_H

#include "../../../view/windows/screen/context-abilities/StateChangeable.h"
#include "../../../data/manager/DataManager.h"
#include "../../unifier/common/Unifier.h"
#include "analyze/DirectivesAnalyzer.h"
#include "generators/Generator.h"
#include "pools/GeneratorsPool.h"
#include "pools/SourcePool.h"

namespace Generate {

    /**
     * @brief The SceneGenerator class. The class is responsible for uploading scenes to the unifier.
     * @namespace Generate
     *
     * This class defines SceneGenerator realization.
    */
    class SceneGenerator {
    public:
        explicit SceneGenerator(View::StateChangeable *context, Managers::DataManager *manager);

        /**
         * @brief Method fills Unifier with objects.
         * @param filename Config file path.
         * @param unifier Scene unifier.
         * @param window Target render window.
         */
        void loadScene(const std::string &filename, Unite::Unifier &unifier, View::Window &window);

    private:
        /**
         * @brief Source pool.
         */
        Pools::SourcePool m_sourcePool;

        /**
         * @brief Directives analyzer.
         */
        Generate::DirectivesAnalyzer m_analyzer;

        /**
         * @brief Generators pool.
         */
        Pools::GeneratorsPool m_generatorsPool;

        /**
         * @brief Do not call "delete" for this ptr.
         */
        Managers::DataManager *m_manager;
    };
}

#endif //FLASH_SCENEGENERATOR_H
