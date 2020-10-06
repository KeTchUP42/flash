//
// Created by roman on 02.10.2020.
//

#ifndef FLASH_BLOCKANALYZER_H
#define FLASH_BLOCKANALYZER_H

#include "../pools/SourcePool.h"

namespace Generate {

    class BlockAnalyzer {
    public:
        BlockAnalyzer(Pools::SourcePool &sourcePool);

        /**
         * @brief Method read ini data and configures render window and source pool.
         * @param data Ini data.
         */
        void analyze(const IniUtil::Analyzer::IniBlock &data, sf::RenderWindow &window);

        virtual ~BlockAnalyzer() = default;

    protected:
        Pools::SourcePool &m_sourcePool;
    };
}

#endif //FLASH_BLOCKANALYZER_H
