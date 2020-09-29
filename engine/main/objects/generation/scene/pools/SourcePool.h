//
// Created by roman on 27.09.2020.
//

#ifndef FLASH_SOURCEPOOL_H
#define FLASH_SOURCEPOOL_H

#include "../../../../data/manager/DataManager.h"
#include "AlgorithmsPool.h"

#include <map>

namespace Generating {

    /**
     * @brief The SourcePool class.
     * @namespace Generating
     *
     * This class defines SourcePool realization.
    */
    class SourcePool {
    public:
        SourcePool(Managers::DataManager *manager);

        /**
         * @brief Method returns new Texture or Texture from cache.
         * @param filename Target file name.
         * @return Texture.
         */
        std::shared_ptr<sf::Texture> getTexture(const std::string &filename);

        /**
         * @brief Method returns new Image or Image from cache.
         * @param filename Target file name.
         * @return Image.
         */
        std::shared_ptr<sf::Image> getImage(const std::string &filename);

        /**
         * @brief Method returns new Music or Music from cache.
         * @param filename Target file name.
         * @return Music.
        */
        std::shared_ptr<sf::Music> getMusic(const std::string &filename);

        /**
         * @brief Method returns new Font or Font from cache.
         * @param filename Target file name.
         * @return Font.
         */
        std::shared_ptr<sf::Font> getFont(const std::string &filename);

        /**
         * @brief Method returns algorithms pool.
         * @return Algorithms pool.
         */
        const Generating::AlgorithmsPool &getAlgpool() const noexcept;

    protected:
        /**
         * @brief Texture cache.
         */
        std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;

        /**
         * @brief Image cache.
         */
        std::map<std::string, std::shared_ptr<sf::Image>> m_images;

        /**
         * @brief Music cache.
         */
        std::map<std::string, std::shared_ptr<sf::Music>> m_music;

        /**
         * @brief Font cache.
         */
        std::map<std::string, std::shared_ptr<sf::Font>> m_fonts;

        /**
         * @brief Algorithms pool.
         */
        AlgorithmsPool m_algpool;

        /**
         * @brief Do not call "delete" for this ptr.
         */
        Managers::DataManager *m_manager;
    };
}

#endif //FLASH_SOURCEPOOL_H
