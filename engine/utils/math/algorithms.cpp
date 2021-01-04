//
// Created by roman on 12.10.2020.
//

#include "algorithms.h"

std::vector<std::string> Calculations::split(const std::string &data, const char delimiter) noexcept {
    std::size_t start = 0;
    std::size_t end = data.find_first_of(delimiter);
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

int Calculations::random(int min, int max) noexcept {
    return min + (rand() % (max - min + 1));
}
