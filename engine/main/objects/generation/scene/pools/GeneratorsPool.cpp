//
// Created by roman on 29.09.2020.
//

#include "GeneratorsPool.h"

Generate::Pools::GeneratorsPool::GeneratorsPool(SourcePool &pool, Screen::StateChangeable *context)
        : m_selector(pool, context) {}

std::shared_ptr<Generate::Generator> Generate::Pools::GeneratorsPool::load(const std::string &alias) {
    if (m_generators[alias].get() == nullptr) {
        m_generators[alias] = std::shared_ptr<Generator>(m_selector.select(alias));
    }

    return m_generators[alias];
}
