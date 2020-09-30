//
// Created by roman on 27.09.2020.
//

#include "EngineConfigurator.h"

Managers::DataManager *Setup::EngineConfigurator::load(const IniProcessorUtil::Analyzer::IniBlock &block) const {
    using namespace Managers;
    AudioManager *audioManager = new AudioManager(block.at("PATH") + "/" + block.at("audio"));
    ConfigManager *configManager = new ConfigManager(block.at("PATH") + "/" + block.at("config"));
    FontManager *fontManager = new FontManager(block.at("PATH") + "/" + block.at("fonts"));
    LogManager *logManager = new LogManager(block.at("PATH") + "/" + block.at("logs"));
    SceneManager *sceneManager = new SceneManager(block.at("PATH") + "/" + block.at("scenes"));
    TextureManager *textureManager = new TextureManager(block.at("PATH") + "/" + block.at("textures"));

    return new DataManager(audioManager, configManager, fontManager, logManager, sceneManager, textureManager);
}