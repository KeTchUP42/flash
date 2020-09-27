//
// Created by roman on 10.08.2020.
//

#include "IniAnalyzer.h"
#include "../IniProcessor.h"
#include "../../trim/trim.h"

#include <regex>

IniProcessorUtil::Analyzer::IniData
IniProcessorUtil::IniAnalyzer::fullparse(const std::vector<std::string> &lines) const noexcept {
    std::string blockName = IniProcessor::NONAME_BLOCK;
    IniData result = IniData();
    result[blockName] = IniBlock();

    for (std::string line : lines) {
        this->clear(line);
        if (line == "") continue;

        if (std::regex_match(line, std::regex{" *\\[[^\\]\\[]*\\] *"})) {
            std::smatch match;
            std::regex_search(line, match, std::regex{"\\[[^\\]\\[]*\\]"});

            blockName = std::regex_replace(match.str(), std::regex{"\\[|\\]"}, "");
            result[blockName] = IniBlock();
            continue;
        }

        if (std::regex_match(line, std::regex("[^\\ \\=\n][^\\=\n]*\\= *.*"))) {
            long pos = line.find('=');

            std::string key = line.substr(0, pos);
            Trim::trim(key);

            std::string value = line.substr(pos + 1);
            Trim::trim(value);

            result[blockName][key] = value;
        }
    }
    return result;
}

void IniProcessorUtil::IniAnalyzer::clear(std::string &data) const noexcept {
    data = std::regex_replace(data, std::regex{";.*\n"}, "");
    data = std::regex_replace(data, std::regex{";.*"}, "");
    Trim::trim(data);
}
