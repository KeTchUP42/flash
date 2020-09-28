//
// Created by roman on 02.08.2020.
//

#include "Engine.h"
#include "../setup/EngineConfigurator.h"
#include "../main/other/exceptions/Exception.h"
#include "../main/view/create/window/PrimaryWindowFactory.h"

Program::Engine::Engine(const std::string &filename) {
    Setup::EngineConfigurator configurator;
    m_manager = configurator.load(filename);
}

int Program::Engine::start() const {
    try {
        ViewCreate::PrimaryWindowFactory factory;
        std::shared_ptr<WindowView::Window> window = factory.create("win/primary.ini", m_manager);
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
