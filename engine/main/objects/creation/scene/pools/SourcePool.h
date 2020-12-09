//
// Created by roman on 27.09.2020.
//

#ifndef FLASH_SOURCEPOOL_H
#define FLASH_SOURCEPOOL_H

#include "../../../../data/manager/DataManager.h"
#include "AlgorithmsPool.h"

namespace Creation {

    namespace Pools {

        /**
         * @brief The class allows you to cache the data needed to create objects.
         * @namespace Creation::Pools
         *
         * This class defines SourcePool realization.
        */
        class SourcePool {
        public:
            SourcePool(Managers::DataManager *manager);

            /**
             * @brief Method returns new Texture or Texture from cache. Do not call any setters, it will change state all used textures.
             * @param filename Target texture file name.
             * @param area Image area.
             * @return Texture.
             */
            std::shared_ptr<sf::Texture> getTexture(const std::string &filename, const sf::Rect<int> &area = sf::IntRect());

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
             * @brief Method returns global variable.
             * @param name Variable name.
             * @return Variable.
             */
            std::string getVariable(const std::string &name) const noexcept;

            /**
             * @brief Method setts new variable.
             * @param name Variable name.
             * @param value Variable value.
             */
            void setVariable(const std::string &name, const std::string &value) noexcept;

            /**
             * @brief Method returns algorithms pool.
             * @return Algorithms pool.
             */
            Creation::Pools::AlgorithmsPool *getAlgPool() noexcept;

            /**
             * @brief Method returns data manager.
             * @return Manager.
             */
            Managers::DataManager *getManager() const noexcept;

        private:
            /**
             * @brief Algorithms pool.
             */
            AlgorithmsPool m_algpool;

            /**
             * @brief Do not call "delete" for this ptr.
             */
            Managers::DataManager *m_manager;

            /**
             * @brief Textures cache.
             */
            std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;

            /**
             * @brief Image cache.
             */
            std::map<std::string, std::shared_ptr<sf::Image>> m_images;

            /**
             * @brief Font cache.
             */
            std::map<std::string, std::shared_ptr<sf::Font>> m_fonts;

            /**
             * @brief Global scene variables.
             */
            std::map<std::string, std::string> m_variables;
        };
    }
}
#endif //FLASH_SOURCEPOOL_H
