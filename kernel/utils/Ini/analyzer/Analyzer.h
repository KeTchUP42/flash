//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_ANALYZER_H
#define FLASH_ANALYZER_H

#include <map>
#include <vector>
#include <string>

namespace IniProcessorUtil {

    /**
     *  @brief  The base class of the Analyzer strategy class hierarchy. Uses in IniProcessor hierarchy.
     *  @namespace IniProcessorUtil
     *
     *  This class defines base interface of Analyzer classes.
    */
    class Analyzer {
    public:
        using IniData = std::map<std::string, std::map<std::string, std::string>>;
        using IniLine = std::map<std::string, std::string>;

        Analyzer &operator=(const Analyzer &) = delete;

        /**
         * Method returns full ini config data in IniData type.
         * Configs without block will be in CONFIG_LINES_WITHOUT_BLOCK section.
         *
          * @param lines std::vector<std::string>
          * @return Analyzer::IniData
         */
        virtual IniData fullparse(const std::vector<std::string> &lines) const noexcept = 0;

        /**
         * Method clears data from comments and other.
         * Mostly used in other Analyzer methods.
         *
         * @param data
         */
        virtual void clear(std::string &data) const noexcept = 0;

        virtual ~Analyzer() = default;
    };
}

#endif //FLASH_ANALYZER_H
