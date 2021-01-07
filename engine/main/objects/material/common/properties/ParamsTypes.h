//
// Created by roman on 07.01.2021.
//

#ifndef FLASH_PARAMSTYPES_H
#define FLASH_PARAMSTYPES_H

#include <bits/stl_pair.h>

namespace Material {

    using INT_PARAM = int;
    using BYTE_PARAM = char;
    using UINT_PARAM = unsigned int;
    using UBYTE_PARAM = unsigned char;
    using FRAC_PARAM = float;
    using BOOL_PARAM = bool;

    template<typename T>
    using PAIR = std::pair<T, T>;
}

#endif //FLASH_PARAMSTYPES_H
