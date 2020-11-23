//
// Created by roman on 20.10.2020.
//

#include "KeyMapBuilder.h"

Creation::RD::KeyMapBuilder::KeyMapBuilder(const std::string &filename, Creation::Pools::SourcePool &source)
        : m_keydata(source.getManager()->getConfigManager()->loadIni(filename)) {}

Creation::RD::KeyMapBuilder &Creation::RD::KeyMapBuilder::setKey(Mobs::KeyAlias alias, const std::string &block, const std::string &field) {
    m_keyMap[alias] = static_cast<sf::Keyboard::Key>(std::atoi(m_keydata.at(block).at(field).c_str()));
    return *this;
}

const std::map<Mobs::KeyAlias, sf::Keyboard::Key> &Creation::RD::KeyMapBuilder::getKeyMap() const noexcept {
    return m_keyMap;
}

Creation::RD::KeyMapBuilder &Creation::RD::KeyMapBuilder::resetKeyMap() noexcept {
    m_keyMap = std::map<Mobs::KeyAlias, sf::Keyboard::Key>();
    return *this;
}
