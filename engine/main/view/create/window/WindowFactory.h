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
         * @param manager Resource data manager.
         * @return New Window.
         */
        virtual std::shared_ptr<WindowView::Window>
        create(const std::string &filename, Managers::DataManager *manager) const = 0;

        virtual ~WindowFactory() = default;
    };
}
#endif //FLASH_WINDOWFACTORY_H
