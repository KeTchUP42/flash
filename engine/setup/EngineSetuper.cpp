//
// Created by roman on 24.08.2020.
//

#include "EngineSetuper.h"
#include "../utils/Ini/BaseIniProcessor.h"
#include "../main/data/manager/StandardDataManager.h"
#include "../main/data/manager/audio-manager/MusicManager.h"
#include "../main/data/manager/font-manager/BaseFontManager.h"
#include "../main/data/manager/log-manager/BaseLogManager.h"
#include "../main/data/manager/texture-manager/BaseTextureManager.h"

DataManagers::DataManager *Setup::EngineSetuper::load() const {
    using namespace IniProcessorUtil;
    BaseIniProcessor iniProcessor(_config);
    Analyzer::IniData iniData = iniProcessor.fullparse();

    using namespace DataManagers;
    AudioManager *audioManager = new MusicManager(iniData["DATA"]["AppData"] + "/" + iniData["DATA"]["audio"]);
    FontManager *fontManager = new BaseFontManager(iniData["DATA"]["AppData"] + "/" + iniData["DATA"]["fonts"]);
    LogManager *logManager = new BaseLogManager(iniData["DATA"]["AppData"] + "/" + iniData["DATA"]["logs"]);
    TextureManager *textureManager = new BaseTextureManager(iniData["DATA"]["AppData"] + "/" + iniData["DATA"]["textures"]);

    return new StandardDataManager(audioManager, fontManager, logManager, textureManager);
}
