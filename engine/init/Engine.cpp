//
// Created by roman on 02.08.2020.
//

#include "Engine.h"
#include "../setup/EngineConfigurator.h"
#include "../main/other/exceptions/Exception.h"
#include "../main/view/create/window/BasicWindowFactory.h"
#include "../utils/Ini/BasicIniProcessor.h"

Program::Engine::Engine(const std::string &filename) {
    IniProcessorUtil::BasicIniProcessor iniProcessor(filename);
    IniProcessorUtil::Analyzer::IniData iniData = iniProcessor.fullparse();
    Setup::EngineConfigurator configurator;
    m_manager = configurator.load(iniData["DATA"]);
    m_windowSettingsFile = iniData["WINDOW"]["WindowSettingsFile"];
}

int Program::Engine::start() const {
    try {
        ViewCreate::BasicWindowFactory factory;
        std::shared_ptr<WindowView::Window> window = factory.create(m_windowSettingsFile, m_manager);
        window->start();
    }
    catch (PreferredExceptions::Exception &exception) {
        std::shared_ptr<LoggerUtil::Logger> logger = m_manager->getLogManager()->createLoggerForFile("crash.log");
        logger->critical("Exception code: " + std::to_string(exception.getCode()) + ". " + exception.getMessage());
        return exception.getCode();
    }
    return EXIT_SUCCESS;
}

Program::Engine::~Engine() {
    delete m_manager;
}
