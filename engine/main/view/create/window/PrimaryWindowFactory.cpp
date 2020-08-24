//
// Created by roman on 23.08.2020.
//

#include "PrimaryWindowFactory.h"
#include "../../windows/custom/PrimaryWindow/PrimaryWindow.h"
#include "../../windows/base/observers/WindowCloseObserver.h"

#include <cstdlib>

std::shared_ptr<Windows::Window>
ViewCreate::PrimaryWindowFactory::createWindow(DataManagers::DataManager *dataManager, const std::string &filename) const {
    IniProcessorUtil::Analyzer::IniData data = dataManager->getConfigManager()->load(filename);

    sf::ContextSettings contextSettings;
    contextSettings.depthBits = std::atoi(data["ContextSettings"]["depthBits"].c_str());
    contextSettings.stencilBits = std::atoi(data["ContextSettings"]["stencilBits"].c_str());
    contextSettings.antialiasingLevel = std::atoi(data["ContextSettings"]["antialiasingLevel"].c_str());
    contextSettings.majorVersion = std::atoi(data["ContextSettings"]["majorVersion"].c_str());
    contextSettings.minorVersion = std::atoi(data["ContextSettings"]["minorVersion"].c_str());
    contextSettings.attributeFlags = std::atoi(data["ContextSettings"]["attributeFlags"].c_str());

    using namespace Windows;
    int width = std::atoi(data["Window"]["width"].c_str());
    int height = std::atoi(data["Window"]["height"].c_str());

    Window *window = new PrimaryWindow(sf::VideoMode(width, height), data["Window"]["title"],
                                       sf::Style::Default, contextSettings, dataManager);
    window->addObserver(new WindowCloseObserver());
    //..
    return std::shared_ptr<Windows::Window>(window);
}

std::shared_ptr<Windows::Window>
ViewCreate::PrimaryWindowFactory::createWindow(sf::WindowHandle handle, DataManagers::DataManager *dataManager) const {
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;

    using namespace Windows;
    Window *window = new PrimaryWindow(handle, contextSettings, dataManager);
    window->addObserver(new WindowCloseObserver());
    //..
    return std::shared_ptr<Windows::Window>(window);
}
