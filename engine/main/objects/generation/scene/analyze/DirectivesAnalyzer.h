//
// Created by roman on 02.10.2020.
//

#ifndef FLASH_DIRECTIVESANALYZER_H
#define FLASH_DIRECTIVESANALYZER_H

#include "../pools/SourcePool.h"
#include "../../../../view/windows/base/window/Window.h"

namespace Generate {

    class DirectivesAnalyzer {
    public:
        DirectivesAnalyzer(Pools::SourcePool &sourcePool);

        /**
         * @brief Method read ini data and configures render window and source pool.
         * @param data Ini data.
         */
        void analyze(const IniUtil::Analyzer::IniBlock &data, View::Window &window);

        virtual ~DirectivesAnalyzer() = default;

    private:
        Pools::SourcePool &m_sourcePool;
    };
}

#endif //FLASH_DIRECTIVESANALYZER_H