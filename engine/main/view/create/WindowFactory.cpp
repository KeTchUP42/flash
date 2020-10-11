//
// Created by roman on 23.08.2020.
//

#include "WindowFactory.h"
#include "../windows/custom/primary/PrimaryWindow.h"
#include "../windows/base/observers/WindowCloseObserver.h"
#include "../windows/screen/states/InitialScreenState.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>

std::shared_ptr<WindowView::Window>
ViewCreate::WindowFactory::create(const std::string &filename, Managers::DataManager *manager) {
    IniUtil::Analyzer::IniData iniData = manager->getConfigManager()->loadIni(filename);

    //context settings
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = std::atoi(iniData["CONTEXT_SETTINGS"]["depthBits"].c_str());
    contextSettings.stencilBits = std::atoi(iniData["CONTEXT_SETTINGS"]["stencilBits"].c_str());
    contextSettings.antialiasingLevel = std::atoi(iniData["CONTEXT_SETTINGS"]["antialiasingLevel"].c_str());
    contextSettings.majorVersion = std::atoi(iniData["CONTEXT_SETTINGS"]["majorVersion"].c_str());
    contextSettings.minorVersion = std::atoi(iniData["CONTEXT_SETTINGS"]["minorVersion"].c_str());
    contextSettings.attributeFlags = std::atoi(iniData["CONTEXT_SETTINGS"]["attributeFlags"].c_str());
    contextSettings.sRgbCapable = std::atoi(iniData["CONTEXT_SETTINGS"]["sRgbCapable"].c_str());

    //size
    int width = std::atoi(iniData["WINDOW"]["width"].c_str());
    int height = std::atoi(iniData["WINDOW"]["height"].c_str());

    //style
    sf::Uint32 style = sf::Style::Default;
    std::string styleName = iniData["WINDOW"]["style"];
    std::transform(styleName.begin(), styleName.end(), styleName.begin(),
                   [](unsigned char ch) { return std::tolower(ch); });

    if (styleName == "fullscreen")
        style = sf::Style::Fullscreen;

    //window
    using namespace WindowView;
    PrimaryWindow *window = new PrimaryWindow(sf::VideoMode(width, height), iniData["WINDOW"]["title"], style, contextSettings,
                                              new Screen::InitialScreenState(iniData["SCENE"]["launch"]), manager);
    //fps
    window->setFramerateLimit(std::atoi(iniData["WINDOW"]["fps"].c_str()));
    //sync
    window->setVerticalSyncEnabled((std::atoi(iniData["WINDOW"]["VerticalSync"].c_str()) == 1));

    window->configure(); // Mathod calls initialization mathod.
    return std::shared_ptr<WindowView::Window>(window);
}