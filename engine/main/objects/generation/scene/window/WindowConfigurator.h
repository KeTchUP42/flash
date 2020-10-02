//
// Created by roman on 02.10.2020.
//

#ifndef FLASH_WINDOWCONFIGURATOR_H
#define FLASH_WINDOWCONFIGURATOR_H

#include "../pools/SourcePool.h"

namespace Generating {

    class WindowConfigurator {
    public:
        WindowConfigurator(SourcePool &sourcePool);

        /**
         * @brief Method read ini data and configures render window.
         * @param data Ini data.
         */
        void configure(const IniUtil::Analyzer::IniBlock &data, sf::RenderWindow &window);

    protected:
        /**
         * @brief Source pool.
         */
        SourcePool &m_source_pool;
    };
}

#endif //FLASH_WINDOWCONFIGURATOR_H
