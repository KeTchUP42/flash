//
// Created by roman on 27.09.2020.
//

#include "SceneGenerator.h"

#include <regex>

Generating::SceneGenerator::SceneGenerator(Screen::StateChangeable *context, Managers::DataManager *manager)
        : m_source_pool(manager), m_gen_pool(m_source_pool, context), m_context(context), m_manager(manager) {}

void Generating::SceneGenerator::loadScene(const std::string &filename, Unite::Unifier &unifier, sf::RenderWindow &target) {
    using namespace IniProcessorUtil;
    Analyzer::IniData data = m_manager->getSceneManager()->load(filename);

    for (Analyzer::IniData::const_iterator block = data.cbegin(); block != data.cend(); ++block) {
        if (block->first == "") continue;
        m_gen_pool.load(std::regex_replace(block->first, std::regex{"_.*"}, ""))->load(block->second, unifier, target);
    }
}
