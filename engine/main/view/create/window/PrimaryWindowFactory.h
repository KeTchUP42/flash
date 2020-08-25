//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_PRIMARYWINDOWFACTORY_H
#define FLASH_PRIMARYWINDOWFACTORY_H

#include "WindowFactory.h"

namespace ViewCreate {

    class PrimaryWindowFactory : public WindowFactory {
    public:
        std::shared_ptr<WindowView::Window>
        createWindow(DataManagers::DataManager *dataManager, const std::string &filename) const override;

        std::shared_ptr<WindowView::Window>
        createWindow(sf::WindowHandle handle, DataManagers::DataManager *dataManager) const override;
    };
}
#endif //FLASH_PRIMARYWINDOWFACTORY_H
