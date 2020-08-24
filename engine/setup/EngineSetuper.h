//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_ENGINESETUPER_H
#define FLASH_ENGINESETUPER_H

#include "Setuper.h"

namespace Setup {

    class EngineSetuper : public Setuper {
    public:
        explicit EngineSetuper(const std::string &filename)
                : Setuper(filename) {}

        DataManagers::DataManager *load() const override;
    };
}
#endif //FLASH_ENGINESETUPER_H
