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
         * @param filename Window config filename.
         * @param dataManager Resource data manager.
         * @return New Window.
         */
        virtual std::shared_ptr<WindowView::Window>
        createWindow(const std::string &filename, Managers::DataManager *dataManager) const = 0;

        /**
         * @brief Base factory method. You can add any additional logic to it.
         * This method WILL NOT delete DataManager!
         *
         * @param handle sf::WindowHandle
         * @param dataManager Resource data manager.
         * @return New Window.
         */
        virtual std::shared_ptr<WindowView::Window>
        createWindow(sf::WindowHandle handle, Managers::DataManager *dataManager) const = 0;

        virtual ~WindowFactory() = default;
    };
}
#endif //FLASH_WINDOWFACTORY_H
