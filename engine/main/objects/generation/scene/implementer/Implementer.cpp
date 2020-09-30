//
// Created by roman on 29.09.2020.
//

#include "Implementer.h"
#include "../generators/obstacles/DullBlockGenerator.h"

Generating::Generator *
Generating::implement(const std::string &alias, SourcePool &pool, Screen::StateChangeable *context) noexcept {
    using namespace Generating;
    if (alias == "DullBlock")
        return new DullBlockGenerator(pool);
    //todo: Add alias implementation.
    return nullptr;
}