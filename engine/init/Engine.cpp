//
// Created by roman on 02.08.2020.
//

#include "Engine.h"
#include "../setup/EngineSetuper.h"
#include "../main/general/exceptions/Exception.h"
#include "../utils/logger/BaseLogger.h"
#include "../utils/writer/FileWriter.h"
#include "../main/view/create/window/PrimaryWindowFactory.h"

#define OK         0
#define EXCEPTION 255

Program::Engine::LOG Program::Engine::start() const noexcept {
    DataManagers::DataManager *dataManager;
    std::shared_ptr<WindowView::Window> window;
    try {
        Setup::EngineSetuper setuper("./config/flash.ini");
        dataManager = setuper.load();
        ViewCreate::PrimaryWindowFactory factory;
        window = factory.createWindow(dataManager, "primary.ini");
    }
    catch (PreferredExceptions::Exception &exception) {
        LoggerUtil::BaseLogger logger(new WriterUtil::FileWriter("./crash.log"));
        logger.critical("Exception code: " + std::to_string(exception.getCode()) + ". " + exception.getMessage());
        return EXCEPTION;
    }
    catch (...) {
        return EXCEPTION;
    }
    //todo: Split this method with usage of two objects - Starter and Process. They need to be in engine/init directory.
    std::shared_ptr<LoggerUtil::Logger> logger = dataManager->getLogManager()->createLoggerForFile("crash.log");

    try {
        window->start();
    }
    catch (PreferredExceptions::Exception &exception) {
        logger->critical("Exception code: " + std::to_string(exception.getCode()) + ". " + exception.getMessage());
        return EXCEPTION;
    }

    return OK;
}
