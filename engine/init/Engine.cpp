//
// Created by roman on 02.08.2020.
//

#include "Engine.h"
#include "setup/EngineConfigurator.h"
#include "../main/other/exceptions/Exception.h"
#include "../main/view/create/WindowFactory.h"
#include "../utils/Ini/IniProcessor.h"

#include <memory>

Program::Engine::Engine(const std::string &filename) {
    IniUtil::IniProcessor processor(filename);
    IniUtil::Analyzer::IniData iniData = processor.fullparse();
    Setup::EngineConfigurator configurator;
    m_manager = configurator.loadDataManager(iniData["DATA"]);
    m_WindowSettingsFile = iniData["WINDOW"]["WindowSettingsFile"];
}

int Program::Engine::start() const {
    try {
        ViewCreate::WindowFactory factory;
        std::shared_ptr<WindowView::Window> window = factory.create(m_WindowSettingsFile, m_manager);
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
