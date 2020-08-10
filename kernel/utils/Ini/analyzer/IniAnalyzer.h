//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_INIANALYZER_H
#define FLASH_INIANALYZER_H

#include "Analyzer.h"

namespace IniParseUtil {

    class IniAnalyzer : public Analyzer {
    public:
        IniData fullparse(const std::vector<std::string> &data) const noexcept override;
    };
}

#endif //FLASH_INIANALYZER_H
