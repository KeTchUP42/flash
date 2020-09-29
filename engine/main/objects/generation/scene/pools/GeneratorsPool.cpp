//
// Created by roman on 29.09.2020.
//

#include "GeneratorsPool.h"
#include "../implementer/Implementer.h"

Generating::GeneratorsPool::GeneratorsPool(SourcePool &pool, Screen::StateChangeable *context)
        : m_pool(pool), m_context(context) {}

std::shared_ptr<Generating::Generator> Generating::GeneratorsPool::load(const std::string &alias) noexcept {
    if (m_generators[alias].get() == nullptr) {
        m_generators[alias] = std::shared_ptr<Generator>(implement(alias, m_pool, m_context));
    }

    return m_generators[alias];
}
