//
// Created by roman on 12.10.2020.
//

#ifndef FLASH_ALGORITHMS_UTIL_H
#define FLASH_ALGORITHMS_UTIL_H

#include <vector>
#include <string>

namespace Computations {

    /**
     * @brief Realization of split function.
     * @param data Processed string data.
     * @param delimiter Char delimiter.
     * @return Vector with splitted data.
     */
    std::vector<std::string> split(const std::string &data, const char delimiter) noexcept;

    /**
     * @brief Function returns random int number in [min, max] interval.
     * @param min Minimal possible value.
     * @param max Maximum possible value.
     * @return [min, max] value.
     */
    int random(int min, int max) noexcept;
}

#endif //FLASH_ALGORITHMS_UTIL_H
