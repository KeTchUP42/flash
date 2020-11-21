//
// Created by roman on 21.11.2020.
//

#include "IniCreator.h"

#include "../IniProcessor.h"

std::string IniUtil::IniCreator::create(const IniUtil::Analyzer::IniData &data) const {
    std::string inidata;
    for (const auto &block: data) {
        if (block.first == IniProcessor::NONAME_BLOCK) {
            for (Analyzer::IniBlock::const_reverse_iterator line = block.second.rbegin();
                 line != block.second.rend(); ++line) {
                inidata = line->first + " = " + line->second + "\n" + inidata;
            }
            continue;
        }

        inidata.append("\n[" + block.first + "]\n");
        for (const auto &line: block.second) {
            inidata.append(line.first + " = " + line.second + "\n");
        }
    }
    return inidata;
}
