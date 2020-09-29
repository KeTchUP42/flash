//
// Created by roman on 27.09.2020.
//

#include "SourcePool.h"

Generating::SourcePool::SourcePool(Managers::DataManager *manager)
        : m_algpool(), m_manager(manager) {}

std::shared_ptr<sf::Texture> Generating::SourcePool::getTexture(const std::string &filename) {
    if (m_textures[filename].get() == nullptr) {
        m_textures[filename] = m_manager->getTextureManager()->loadTexture(filename);
    }

    return m_textures[filename];
}

std::shared_ptr<sf::Image> Generating::SourcePool::getImage(const std::string &filename) {
    if (m_images[filename].get() == nullptr) {
        m_images[filename] = m_manager->getTextureManager()->loadImage(filename);
    }

    return m_images[filename];
}

std::shared_ptr<sf::Music> Generating::SourcePool::getMusic(const std::string &filename) {
    if (m_music[filename].get() == nullptr) {
        m_music[filename] = m_manager->getAudioManager()->loadMusic(filename);
    }

    return m_music[filename];
}

std::shared_ptr<sf::Font> Generating::SourcePool::getFont(const std::string &filename) {
    if (m_fonts[filename].get() == nullptr) {
        m_fonts[filename] = m_manager->getFontManager()->loadFont(filename);
    }

    return m_fonts[filename];
}

const Generating::AlgorithmsPool &Generating::SourcePool::getAlgpool() const noexcept {
    return m_algpool;
}

