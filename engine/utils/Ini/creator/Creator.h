//
// Created by roman on 21.11.2020.
//

#ifndef FLASH_CREATOR_H
#define FLASH_CREATOR_H

#include "../analyzer/Analyzer.h"

namespace IniUtil {

    /**
     * @brief The interface of the Creator strategy class hierarchy. Uses in IniProcessor.
     * @namespace IniUtil
     *
     * This class defines base interface of Creator classes.
    */
    class Creator {
    public:
        Creator() = default;

        /**
         * @brief Method generates string struct from IniData object.
         * @param data Ini-data.
         */
        virtual std::string create(const Analyzer::IniData &data) const = 0;

        virtual ~Creator() = default;
    };
}

#endif //FLASH_CREATOR_H
