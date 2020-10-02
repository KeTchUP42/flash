//
// Created by roman on 27.09.2020.
//

#ifndef FLASH_SOURCEPOOL_H
#define FLASH_SOURCEPOOL_H

#include "../../../../data/manager/DataManager.h"
#include "AlgorithmsPool.h"

#include <map>

namespace Generating {

    namespace Pools {

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
            Generating::Pools::AlgorithmsPool *getAlgpool() noexcept;

            /**
             * @brief Method returns data manager.
             * @return Manager.
             */
            Managers::DataManager *getManager() const noexcept;

        protected:

            /**
             * @brief Algorithms pool.
             */
            AlgorithmsPool m_algpool;

            /**
             * @brief Do not call "delete" for this ptr.
             */
            Managers::DataManager *m_manager;

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
             * @brief Global scene variables.
             */
            std::map<std::string, std::string> m_variables;
        };
    }
}
#endif //FLASH_SOURCEPOOL_H
