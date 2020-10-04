//
// Created by roman on 02.10.2020.
//

#ifndef FLASH_GLOBALBLOCKANALYZER_H
#define FLASH_GLOBALBLOCKANALYZER_H

#include "../../pools/SourcePool.h"

namespace Generate {

    class GlobalBlockAnalyzer {
    public:
        GlobalBlockAnalyzer(Pools::SourcePool &sourcePool);

        /**
         * @brief Method read ini data and configures render window and source pool.
         * @param data Ini data.
         */
        void analyze(const IniUtil::Analyzer::IniBlock &data, sf::RenderWindow &window);

    protected:
        /**
         * @brief Source pool.
         */
        Pools::SourcePool &m_source_pool;
    };
}

#endif //FLASH_GLOBALBLOCKANALYZER_H
