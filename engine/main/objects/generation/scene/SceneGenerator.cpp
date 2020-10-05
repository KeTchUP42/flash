//
// Created by roman on 27.09.2020.
//

#include "SceneGenerator.h"
#include "../../../../utils/Ini/IniProcessor.h"
#include "analyze/BlockAnalyze.h"
#include "../../../other/exceptions/InvalidArgument.h"

#include <regex>

Generate::SceneGenerator::SceneGenerator(Screen::StateChangeable *context, Managers::DataManager *manager)
        : m_source_pool(manager), m_generators_pool(m_source_pool, context),
          m_manager(manager) {}

void Generate::SceneGenerator::loadScene(const std::string &filename, Unite::Unifier &unifier, sf::RenderWindow &target) {
    IniUtil::Analyzer::IniData data = m_manager->getSceneManager()->load(filename);
    std::shared_ptr<Generator> generator;

    for (const auto &block: data) {
        if (block.first == IniUtil::IniProcessor::NONAME_BLOCK) {
            Generate::analyzeIniBlock(block.second, m_source_pool, target);
            continue;
        }
        if ((generator = m_generators_pool.load(std::regex_replace(block.first, std::regex{"_.*"}, ""))) != nullptr) {
            generator->load(block.second, unifier, target);
        } else {
            throw PreferredExceptions::InvalidArgument("Invalid generator's name \"" + block.first + "\" in file \"" + filename + "\".");
        }
    }
}
