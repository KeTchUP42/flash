//
// Created by roman on 27.09.2020.
//

#include "SourcePool.h"

Generate::Pools::SourcePool::SourcePool(Managers::DataManager *manager)
        : m_algpool(), m_manager(manager) {}

std::shared_ptr<sf::Texture> Generate::Pools::SourcePool::getTexture(const std::string &filename, const sf::Rect<int> &area) {
    std::string key = filename +
                      ":" + std::to_string(area.left) + ":" + std::to_string(area.top) +
                      ":" + std::to_string(area.width) + ":" + std::to_string(area.height);

    if (m_textures[key].get() == nullptr) {
        m_textures[key] = m_manager->getTextureManager()->loadTexture(filename, area);
    }
    return m_textures[key];
}

std::shared_ptr<sf::Image> Generate::Pools::SourcePool::getImage(const std::string &filename) {
    if (m_images[filename].get() == nullptr) {
        m_images[filename] = m_manager->getTextureManager()->loadImage(filename);
    }

    return m_images[filename];
}

std::shared_ptr<sf::Music> Generate::Pools::SourcePool::getMusic(const std::string &filename) {
    return m_manager->getAudioManager()->loadMusic(filename);
}

std::shared_ptr<sf::Font> Generate::Pools::SourcePool::getFont(const std::string &filename) {
    if (m_fonts[filename].get() == nullptr) {
        m_fonts[filename] = m_manager->getFontManager()->loadFont(filename);
    }

    return m_fonts[filename];
}

std::string Generate::Pools::SourcePool::getVariable(const std::string &name) const noexcept {
    return m_variables.at(name);
}

void Generate::Pools::SourcePool::setVariable(const std::string &name, const std::string &value) noexcept {
    m_variables[name] = value;
}

Generate::Pools::AlgorithmsPool *Generate::Pools::SourcePool::getAlgpool() noexcept {
    return &m_algpool;
}

Managers::DataManager *Generate::Pools::SourcePool::getManager() const noexcept {
    return m_manager;
}
