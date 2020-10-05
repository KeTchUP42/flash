//
// Created by roman on 02.10.2020.
//

#ifndef FLASH_BLOCKANALYZE_H
#define FLASH_BLOCKANALYZE_H

#include "../pools/SourcePool.h"

namespace Generate {

    /**
     * @brief Method read ini data and configures render window and source pool.
     * @param data Ini data.
     */
    void analyzeIniBlock(const IniUtil::Analyzer::IniBlock &data, Pools::SourcePool &sourcePool, sf::RenderWindow &window);
}

#endif //FLASH_BLOCKANALYZE_H
