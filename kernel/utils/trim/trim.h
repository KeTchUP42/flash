//
// Created by roman on 12.08.2020.
//

#ifndef FLASH_TRIM_H
#define FLASH_TRIM_H

#include <algorithm>
#include <locale>

namespace Trim {

    /**
     * Trim from start (in place)
     * @param __s String to ltrim
     */
    static inline void ltrim(std::string &__s) {
        __s.erase(__s.begin(), std::find_if(__s.begin(), __s.end(), [](int ch) {
            return !std::isspace(ch);
        }));
    }

    /**
     * Trim from end (in place)
     * @param __s String to rtrim
     */
    static inline void rtrim(std::string &__s) {
        __s.erase(std::find_if(__s.rbegin(), __s.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), __s.end());
    }

    /**
     * Trim from both ends (in place)
     * @param __s String to trim
     */
    static inline void trim(std::string &__s) {
        ltrim(__s);
        rtrim(__s);
    }

    /**
     * Trim from start (copying)
     * @param __s String to ltrim_copy
     * @return
     */
    static inline std::string ltrim_copy(std::string __s) {
        ltrim(__s);
        return __s;
    }

    /**
     * Trim from end (copying)
     * @param __s String to rtrim_copy
     * @return
     */
    static inline std::string rtrim_copy(std::string __s) {
        rtrim(__s);
        return __s;
    }
}
#endif //FLASH_TRIM_H
