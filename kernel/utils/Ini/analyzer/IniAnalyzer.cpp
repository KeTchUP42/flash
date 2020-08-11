//
// Created by roman on 10.08.2020.
//

#include "IniAnalyzer.h"
#include "../IniProcessor.h"

IniProcessorUtil::Analyzer::IniData
IniProcessorUtil::IniAnalyzer::fullparse(const std::vector<std::string> &data) const noexcept {
    std::string blockName = IniProcessor::CONFIG_LINES_WITHOUT_BLOCK;

    //todo: write analyzer alg!!

    return IniProcessorUtil::Analyzer::IniData();
}
