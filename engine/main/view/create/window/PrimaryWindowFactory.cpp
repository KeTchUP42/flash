//
// Created by roman on 23.08.2020.
//

#include "PrimaryWindowFactory.h"
#include "../../windows/custom/PrimaryWindow/PrimaryWindow.h"
#include "../../windows/base/observers/WindowCloseObserver.h"
#include "../../../objects/screen/state/BaseScreenState.h"

#include <cstdlib>

std::shared_ptr<WindowView::Window>
ViewCreate::PrimaryWindowFactory::createWindow(DataManagers::DataManager *dataManager, const std::string &filename) const {
    IniProcessorUtil::Analyzer::IniData iniData = dataManager->getConfigManager()->loadIni(filename);

    sf::ContextSettings contextSettings;
    contextSettings.depthBits = std::atoi(iniData["ContextSettings"]["depthBits"].c_str());
    contextSettings.stencilBits = std::atoi(iniData["ContextSettings"]["stencilBits"].c_str());
    contextSettings.antialiasingLevel = std::atoi(iniData["ContextSettings"]["antialiasingLevel"].c_str());
    contextSettings.majorVersion = std::atoi(iniData["ContextSettings"]["majorVersion"].c_str());
    contextSettings.minorVersion = std::atoi(iniData["ContextSettings"]["minorVersion"].c_str());
    contextSettings.attributeFlags = std::atoi(iniData["ContextSettings"]["attributeFlags"].c_str());

    int width = std::atoi(iniData["Window"]["width"].c_str());
    int height = std::atoi(iniData["Window"]["height"].c_str());

    using namespace WindowView;
    //todo: Make ScreenState choosing with config.
    Window *window = new PrimaryWindow(sf::VideoMode(width, height), iniData["Window"]["title"],
                                       sf::Style::Default, contextSettings, new Screen::BaseScreenState(),
                                       dataManager); // If you need you can change sf::Style.
    window->setFramerateLimit(std::atoi(iniData["Window"]["fps"].c_str()));
    //..
    return std::shared_ptr<WindowView::Window>(window);
}

std::shared_ptr<WindowView::Window>
ViewCreate::PrimaryWindowFactory::createWindow(sf::WindowHandle handle, DataManagers::DataManager *dataManager) const {
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;

    using namespace WindowView;
    Window *window = new PrimaryWindow(handle, contextSettings, new Screen::BaseScreenState(), dataManager);
    //..
    return std::shared_ptr<WindowView::Window>(window);
}
