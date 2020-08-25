//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_WINDOWFACTORY_H
#define FLASH_WINDOWFACTORY_H

#include <memory>

#include "../../windows/base/window/Window.h"
#include "../../../data/manager/DataManager.h"

namespace ViewCreate {

    /**
     * @brief The base class of the WindowFactory factory class hierarchy.
     * @namespace ViewCreate
     *
     * This class defines base WindowFactory interface.
    */
    class WindowFactory {
    public:
        WindowFactory() = default;

        /**
         * @brief Base factory method. You can add any additional logic to it.
         * This method WILL NOT delete DataManager!
         *
         * @param dataManager Resource data manager.
         * @param filename Window config filename.
         * @return new Window std::shared_pt<WindowView::Window>
         */
        virtual std::shared_ptr<WindowView::Window>
        createWindow(DataManagers::DataManager *dataManager, const std::string &filename) const = 0;

        /**
         * @brief Base factory method. You can add any additional logic to it.
         *
         * @param handle sf::WindowHandle
         * @param dataManager Resource data manager.
         * @return new Window std::shared_pt<WindowView::Window>
         */
        virtual std::shared_ptr<WindowView::Window>
        createWindow(sf::WindowHandle handle, DataManagers::DataManager *dataManager) const = 0;

        virtual ~WindowFactory() = default;
    };
}
#endif //FLASH_WINDOWFACTORY_H
