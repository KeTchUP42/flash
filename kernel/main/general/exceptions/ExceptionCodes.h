//
// Created by roman on 07.08.2020.
//

#ifndef FLASH_EXCEPTIONCODES_H
#define FLASH_EXCEPTIONCODES_H

namespace KernelExceptions {

    class ExceptionCodes {
        ExceptionCodes() = delete;

    public:
        static constexpr int RUNTIME_EXCEPTION = 1;
        static constexpr int LOGIC_ERROR = 2;
        static constexpr int INVALID_ARGUMENT = 3;
        //..
    };
}

#endif //FLASH_EXCEPTIONCODES_H
