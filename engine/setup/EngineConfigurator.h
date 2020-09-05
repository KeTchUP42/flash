//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_ENGINECONFIGURATOR_H
#define FLASH_ENGINECONFIGURATOR_H

#include "Configurator.h"

namespace Setup {

    class EngineConfigurator : public Configurator {
    public:
        explicit EngineConfigurator(const std::string &filename)
                : Configurator(filename) {}

        Managers::DataManager *load() const override;
    };
}
#endif //FLASH_ENGINECONFIGURATOR_H
