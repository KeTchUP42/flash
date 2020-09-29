//
// Created by roman on 27.09.2020.
//

#include "EngineConfigurator.h"

#include "../utils/Ini/BasicIniProcessor.h"

Managers::DataManager *Setup::EngineConfigurator::load(const std::string &filename) const {
    IniProcessorUtil::BasicIniProcessor iniProcessor(filename);
    IniProcessorUtil::Analyzer::IniData iniData = iniProcessor.fullparse();

    using namespace Managers;
    AudioManager *audioManager = new AudioManager(iniData["DATA"]["PATH"] + "/" + iniData["DATA"]["audio"]);
    ConfigManager *configManager = new ConfigManager(iniData["DATA"]["PATH"] + "/" + iniData["DATA"]["config"]);
    FontManager *fontManager = new FontManager(iniData["DATA"]["PATH"] + "/" + iniData["DATA"]["fonts"]);
    LogManager *logManager = new LogManager(iniData["DATA"]["PATH"] + "/" + iniData["DATA"]["logs"]);
    SceneManager *sceneManager = new SceneManager(iniData["DATA"]["PATH"] + "/" + iniData["DATA"]["scenes"]);
    TextureManager *textureManager = new TextureManager(iniData["DATA"]["PATH"] + "/" + iniData["DATA"]["textures"]);

    return new DataManager(audioManager, configManager, fontManager, logManager, sceneManager, textureManager);
}