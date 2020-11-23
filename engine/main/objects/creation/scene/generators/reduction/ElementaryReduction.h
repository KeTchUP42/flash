//
// Created by roman on 15.10.2020.
//

#ifndef FLASH_ELEMENTARYREDUCTION_H
#define FLASH_ELEMENTARYREDUCTION_H

#include <SFML/Graphics/Color.hpp>
#include "../../../../auxiliary/components/elementary/speed/Speed.h"
#include "../../../../auxiliary/components/elementary/size/Size.h"
#include "../../../../auxiliary/components/elementary/point/Point.h"
#include "../../../../../../utils/Ini/analyzer/Analyzer.h"
#include "../../../../../../utils/math/algorithms.h"

namespace Creation {
    namespace RD {
        /**
         * @brief Function creates Point struct object from given data.
         * @param data Ini data.
         * @param field Field name.
         * @return New Point object.
         */
        Components::Point position(const IniUtil::Analyzer::IniBlock &data, const std::string &field);

        /**
         * @brief Function creates Size struct object from given data.
         * @param data Ini data.
         * @param field Field name.
         * @return New Size object.
         */
        Components::Size size(const IniUtil::Analyzer::IniBlock &data, const std::string &field);

        /**
         * @brief Function creates Speed struct object from given data.
         * @param data Ini data.
         * @param field Field name.
         * @return New Speed object.
         */
        Components::Speed speed(const IniUtil::Analyzer::IniBlock &data, const std::string &field);

        /**
         * @brief Function creates sf::Color struct object from given data.
         * @param data Ini data.
         * @param field Field name.
         * @return New sf::Color object.
         */
        sf::Color color(const IniUtil::Analyzer::IniBlock &data, const std::string &field);

        /**
         * @brief Function creates std::pair<unsigned int, unsigned int> struct object from given data.
         * @param data Ini data.
         * @param field Field name.
         * @return std::pair<unsigned int, unsigned int> object.
         */
        std::pair<unsigned int, unsigned int> upair(const IniUtil::Analyzer::IniBlock &data, const std::string &field);
    }
}

#endif //FLASH_ELEMENTARYREDUCTION_H
