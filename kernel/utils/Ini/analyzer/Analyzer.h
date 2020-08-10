//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_ANALYZER_H
#define FLASH_ANALYZER_H

#include <map>
#include <string>

namespace IniParseUtil {

    class Analyzer {
    public:
        using IniData = std::map<std::string, std::map<std::string, std::string>>;

        Analyzer &operator=(const Analyzer &) = delete;

        /**
         * Method returns full ini config data in IniData type.
         * Configs without own block name will bee in "" field
         *
         * @return Analyzer::IniData
         */
        virtual IniData fullparse(const std::string &) const noexcept = 0;

        //..
    };
}

#endif //FLASH_ANALYZER_H
