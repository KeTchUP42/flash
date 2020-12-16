//
// Created by roman on 02.10.2020.
//

#ifndef FLASH_DIRECTIVESANALYZER_H
#define FLASH_DIRECTIVESANALYZER_H

#include "../pools/SourcePool.h"
#include "../../../../view/windows/common/window/Window.h"

namespace Creation {

    class DirectivesAnalyzer {
    public:
        DirectivesAnalyzer(Pools::SourcePool &sourcePool);

        /**
         * @brief Method reads ini-data and configures render window and source pool.
         * @param data Ini data.
         */
        void analyze(const IniUtil::Analyzer::IniBlock &data, View::Window &window);

        ~DirectivesAnalyzer() = default;

    private:
        Pools::SourcePool &m_sourcePool;
    };
}

#endif //FLASH_DIRECTIVESANALYZER_H
