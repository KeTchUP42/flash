//
// Created by roman on 23.08.2020.
//

#include "PrimaryWindowFactory.h"
#include "../../windows/custom/primary/PrimaryWindow.h"
#include "../../windows/base/observers/WindowCloseObserver.h"
#include "../../windows/screen/states/InitialScreenState.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>

std::shared_ptr<WindowView::Window>
ViewCreate::PrimaryWindowFactory::create(const std::string &filename, Managers::DataManager *manager) const {
    IniProcessorUtil::Analyzer::IniData iniData = manager->getConfigManager()->loadIni(filename);

    //context settings
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = std::atoi(iniData["ContextSettings"]["depthBits"].c_str());
    contextSettings.stencilBits = std::atoi(iniData["ContextSettings"]["stencilBits"].c_str());
    contextSettings.antialiasingLevel = std::atoi(iniData["ContextSettings"]["antialiasingLevel"].c_str());
    contextSettings.majorVersion = std::atoi(iniData["ContextSettings"]["majorVersion"].c_str());
    contextSettings.minorVersion = std::atoi(iniData["ContextSettings"]["minorVersion"].c_str());
    contextSettings.attributeFlags = std::atoi(iniData["ContextSettings"]["attributeFlags"].c_str());
    contextSettings.sRgbCapable = std::atoi(iniData["ContextSettings"]["sRgbCapable"].c_str());

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

    //window
    using namespace WindowView;
    Window *window = new PrimaryWindow(sf::VideoMode(width, height), iniData["Window"]["title"], style,
                                       contextSettings, new Screen::InitialScreenState(), manager);
    //fps
    window->setFramerateLimit(std::atoi(iniData["Window"]["fps"].c_str()));

    return std::shared_ptr<WindowView::Window>(window);
}
