//
// Created by roman on 24.08.2020.
//

#include "EngineConfigurator.h"
#include "../utils/Ini/BasicIniProcessor.h"
#include "../main/data/manager/StandardDataManager.h"
#include "../main/data/manager/audio-manager/MusicManager.h"
#include "../main/data/manager/config-manager/IniConfigManager.h"
#include "../main/data/manager/font-manager/BasicFontManager.h"
#include "../main/data/manager/log-manager/BasicLogManager.h"
#include "../main/data/manager/texture-manager/BasicTextureManager.h"

Managers::DataManager *Setup::EngineConfigurator::load() const {
    IniProcessorUtil::BasicIniProcessor iniProcessor(CONFIG_FILE_NAME);
    IniProcessorUtil::Analyzer::IniData iniData = iniProcessor.fullparse();

    using namespace Managers;
    AudioManager *audioManager = new MusicManager(iniData["DATA"]["AppData"] + "/" + iniData["DATA"]["audio"]);
    ConfigManager *configManager = new IniConfigManager(iniData["DATA"]["AppData"] + "/" + iniData["DATA"]["configs"]);
    FontManager *fontManager = new BasicFontManager(iniData["DATA"]["AppData"] + "/" + iniData["DATA"]["fonts"]);
    LogManager *logManager = new BasicLogManager(iniData["DATA"]["AppData"] + "/" + iniData["DATA"]["logs"]);
    TextureManager *textureManager = new BasicTextureManager(iniData["DATA"]["AppData"] + "/" + iniData["DATA"]["textures"]);

    return new StandardDataManager(audioManager, configManager, fontManager, logManager, textureManager);
}
