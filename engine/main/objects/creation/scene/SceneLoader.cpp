//
// Created by roman on 27.09.2020.
//

#include "SceneLoader.h"
#include "../../../../utils/Ini/IniProcessor.h"
#include "../../../support/exceptions/InvalidArgument.h"

#include <regex>

Creation::SceneLoader::SceneLoader(View::StateChangeable *context, Managers::DataManager *manager)
        : m_source_pool(manager), m_analyzer(m_source_pool), m_generators_pool(m_source_pool, context), m_manager(manager) {}

void Creation::SceneLoader::loadScene(const std::string &filename, Unite::Unifier &unifier, View::Window &window) {
    using namespace Exceptions;
    IniUtil::Analyzer::IniData data = m_manager->getSceneManager()->load(filename);
    try {
        m_analyzer.analyze(data[IniUtil::IniProcessor::NONAME_BLOCK], window);
    } catch (std::exception &exception) {
        throw InvalidArgument("Syntax error when describing the directives in file \"" + filename + "\".");
    }
    std::shared_ptr<Generator> generator;

    for (const auto &block: data) {
        if (block.first == IniUtil::IniProcessor::NONAME_BLOCK) continue;

        if ((generator = m_generators_pool.load(std::regex_replace(block.first, std::regex{"_.*"}, ""))) != nullptr) {
            try {
                generator->load(block.second, unifier, window);
            } catch (std::exception &exception) {
                throw InvalidArgument("Syntax error of the object description in block \"" + block.first + "\" in file \"" + filename + "\".");
            }
        } else {
            throw InvalidArgument("Invalid object's configuration block name \"" + block.first + "\" in file \"" + filename + "\".");
        }
    }
}
