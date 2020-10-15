//
// Created by roman on 27.09.2020.
//

#include "SceneGenerator.h"
#include "../../../../utils/Ini/IniProcessor.h"
#include "../../../other/exceptions/InvalidArgument.h"

#include <regex>

Generate::SceneGenerator::SceneGenerator(Screen::StateChangeable *context, Managers::DataManager *manager)
        : m_sourcePool(manager), m_analyzer(m_sourcePool), m_generatorsPool(m_sourcePool, context), m_manager(manager) {}

void Generate::SceneGenerator::loadScene(const std::string &filename, Unite::Unifier &unifier, sf::RenderWindow &target) {
    IniUtil::Analyzer::IniData data = m_manager->getSceneManager()->load(filename);
    m_analyzer.analyze(data[IniUtil::IniProcessor::NONAME_BLOCK], target);
    std::shared_ptr<Generator> generator;

    for (const auto &block: data) {
        if (block.first == IniUtil::IniProcessor::NONAME_BLOCK) continue;

        if ((generator = m_generatorsPool.load(std::regex_replace(block.first, std::regex{"_.*"}, ""))) != nullptr) {
            generator->load(block.second, unifier, target);
        } else {
            throw PreferredExceptions::InvalidArgument("Invalid object's name \"" + block.first + "\" in file \"" + filename + "\".");
        }
    }
}
