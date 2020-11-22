//
// Created by roman on 12.10.2020.
//

#include "algorithms.h"

#include <stdlib.h>

std::vector<std::string> Computations::split(const std::string &data, const char delimiter) noexcept {
    size_t start = 0;
    size_t end = data.find_first_of(delimiter);
    std::vector<std::string> output;

    while (end <= std::string::npos) {
        output.emplace_back(data.substr(start, end - start));
        if (end == std::string::npos)
            break;
        start = end + 1;
        end = data.find_first_of(delimiter, start);
    }
    return output;
}

int Computations::random(int min, int max) noexcept {
    return min + (rand() % static_cast<int>(max - min + 1));
}
