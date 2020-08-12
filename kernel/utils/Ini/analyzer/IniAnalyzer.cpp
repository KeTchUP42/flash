//
// Created by roman on 10.08.2020.
//

#include "IniAnalyzer.h"
#include "../IniProcessor.h"
#include "../../trim/trim.h"

#include <regex>

IniProcessorUtil::Analyzer::IniData
IniProcessorUtil::IniAnalyzer::fullparse(const std::vector<std::string> &data) const noexcept {
    std::string sectionName = IniProcessor::CONFIG_LINES_WITHOUT_BLOCK;
    IniData result = IniData();
    result[sectionName] = IniLine();

    for (std::string line : data) {
        this->clear(line);
        if (line == "") continue;

        if (std::regex_match(line, std::regex{" *\\[[^\\]\\[]*\\] *"})) {
            std::smatch match;
            std::regex_search(line, match, std::regex{"\\[[^\\]\\[]*\\]"});

            sectionName = std::regex_replace(match.str(), std::regex{"\\[|\\]"}, "");
            result[sectionName] = IniLine();
            continue;
        }

        if (std::regex_match(line, std::regex("[^\\ \\=\n][^\\ \\=\n]* *\\= *.*"))) {
            std::smatch match;
            std::regex_search(line, match, std::regex{"[^\\ \\=\n][^\\ \\=\n]*"});
            std::string key = match.str();

            std::string value = line.replace(0, line.find('=') + 1, "");
            Trim::trim(value);

            result[sectionName][key] = value;
        }
    }
    return std::move(result);
}

void IniProcessorUtil::IniAnalyzer::clear(std::string &data) const noexcept {
    data = std::regex_replace(data, std::regex{";.*\n"}, "");
    data = std::regex_replace(data, std::regex{";.*"}, "");
    Trim::trim(data);
}
