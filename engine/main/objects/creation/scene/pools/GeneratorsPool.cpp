//
// Created by roman on 29.09.2020.
//

#include "GeneratorsPool.h"

Creation::Pools::GeneratorsPool::GeneratorsPool(SourcePool &pool, View::StateChangeable *context)
        : m_selector(pool, context) {}

std::shared_ptr<Creation::Generator> Creation::Pools::GeneratorsPool::load(const std::string &alias) {
    if (m_generators[alias].get() == nullptr) {
        m_generators[alias] = std::shared_ptr<Generator>(m_selector.select(alias));
    }

    return m_generators[alias];
}
