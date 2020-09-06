//
// Created by roman on 23.08.2020.
//

#include "PrimaryWindowFactory.h"
#include "../../windows/custom/PrimaryWindow/PrimaryWindow.h"
#include "../../windows/base/observers/WindowCloseObserver.h"
#include "../../../objects/screen/state/BaseScreenState.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>

std::shared_ptr<WindowView::Window>
ViewCreate::PrimaryWindowFactory::createWindow(const std::string &filename, Managers::DataManager *dataManager) const {
    IniProcessorUtil::Analyzer::IniData iniData = dataManager->getConfigManager()->loadIni(filename);

    //context settings
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = std::atoi(iniData["ContextSettings"]["depthBits"].c_str());
    contextSettings.stencilBits = std::atoi(iniData["ContextSettings"]["stencilBits"].c_str());
    contextSettings.antialiasingLevel = std::atoi(iniData["ContextSettings"]["antialiasingLevel"].c_str());
    contextSettings.majorVersion = std::atoi(iniData["ContextSettings"]["majorVersion"].c_str());
    contextSettings.minorVersion = std::atoi(iniData["ContextSettings"]["minorVersion"].c_str());
    contextSettings.attributeFlags = std::atoi(iniData["ContextSettings"]["attributeFlags"].c_str());

    //size
    int width = std::atoi(iniData["Window"]["width"].c_str());
    int height = std::atoi(iniData["Window"]["height"].c_str());

    //style
    sf::Uint32 style = sf::Style::Default;
    std::string styleName = iniData["Window"]["style"];
    std::transform(styleName.begin(), styleName.end(), styleName.begin(),
                   [](unsigned char ch) { return std::tolower(ch); });

    if (styleName == "fullscreen")
        style = sf::Style::Fullscreen;

    //screen state
    //todo: Think to make ScreenState choosing with config.

    //window
    using namespace WindowView;
    Window *window = new PrimaryWindow(sf::VideoMode(width, height), iniData["Window"]["title"], style, contextSettings,
                                       new Screen::BaseScreenState(), dataManager);
    window->setFramerateLimit(std::atoi(iniData["Window"]["fps"].c_str()));
    //..
    return std::shared_ptr<WindowView::Window>(window);
}

std::shared_ptr<WindowView::Window>
ViewCreate::PrimaryWindowFactory::createWindow(sf::WindowHandle handle, Managers::DataManager *dataManager) const {
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;

    using namespace WindowView;
    Window *window = new PrimaryWindow(handle, contextSettings, new Screen::BaseScreenState(), dataManager);
    //..
    return std::shared_ptr<WindowView::Window>(window);
}
