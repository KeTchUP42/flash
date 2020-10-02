//
// Created by roman on 27.09.2020.
//

#include "SceneGenerator.h"
#include "../../../../utils/Ini/IniProcessor.h"

#include <regex>

Generating::SceneGenerator::SceneGenerator(Screen::StateChangeable *context, Managers::DataManager *manager)
        : m_source_pool(manager), m_gen_pool(m_source_pool, context),
          m_configurator(m_source_pool), m_context(context), m_manager(manager) {}

void Generating::SceneGenerator::loadScene(const std::string &filename, Unite::Unifier &unifier, sf::RenderWindow &target) {
    using namespace IniUtil;
    Analyzer::IniData data = m_manager->getSceneManager()->load(filename);

    for (const auto &block: data) {
        if (block.first == IniUtil::IniProcessor::NONAME_BLOCK) {
            m_configurator.configure(block.second, target);
            continue;
        }
        m_gen_pool.load(std::regex_replace(block.first, std::regex{"_.*"}, ""))->load(block.second, unifier, target);
    }
}
