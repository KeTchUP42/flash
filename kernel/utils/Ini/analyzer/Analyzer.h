//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_ANALYZER_H
#define FLASH_ANALYZER_H

#include <map>
#include <vector>
#include <string>

namespace IniProcessorUtil {

    class Analyzer {
    public:
        using IniData = std::map<std::string, std::map<std::string, std::string>>;

        Analyzer &operator=(const Analyzer &) = delete;

        /**
         * Method returns full ini config data in IniData type.
         * Configs without block will bee in "" field.
         *
          * @param data
          * @return Analyzer::IniData
         */
        virtual IniData fullparse(const std::vector<std::string> &data) const noexcept = 0;
    };
}

#endif //FLASH_ANALYZER_H
