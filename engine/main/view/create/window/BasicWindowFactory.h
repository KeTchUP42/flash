//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_BASICWINDOWFACTORY_H
#define FLASH_BASICWINDOWFACTORY_H

#include "WindowFactory.h"

namespace ViewCreate {

    class BasicWindowFactory : public WindowFactory {
    public:
        std::shared_ptr<WindowView::Window>
        create(const std::string &filename, Managers::DataManager *manager) const override;
    };
}
#endif //FLASH_BASICWINDOWFACTORY_H
