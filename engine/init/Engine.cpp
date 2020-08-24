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
#define EXCEPTION -1

Program::Engine::LOG Program::Engine::start() const noexcept {
    using namespace DataManagers;
    DataManager *dataManager;
    std::shared_ptr<Windows::Window> window;
    try {
        Setup::EngineSetuper setuper("./config/flash.ini");
        dataManager = setuper.load();
        ViewCreate::PrimaryWindowFactory factory;
        window = factory.createWindow(dataManager, "primary.ini");
    }
    catch (...) {
        LoggerUtil::BaseLogger logger(new WriterUtil::FileWriter("./crash.log"));
        logger.critical("Ini config is invalid!");
        return EXCEPTION;
    }
    std::shared_ptr<LoggerUtil::Logger> logger = dataManager->getLogManager()->createLoggerForFile("crash.log");

    try {
        window->start();
    }
    catch (PreferredExceptions::Exception &exception) {
        logger->critical(std::to_string(exception.getCode()) + " : " + exception.getMessage());
        return EXCEPTION;
    }

    return OK;
}
