//
// Created by roman on 07.08.2020.
//

#ifndef FLASH_EXCEPTIONCODES_H
#define FLASH_EXCEPTIONCODES_H

namespace KernelExceptions {

    /**
     * Enume with program exception default codes.
     */
    enum ExceptionCodes {
        RUNTIME_EXCEPTION = 1,
        LOGIC_ERROR = 2,
        INVALID_ARGUMENT = 3,
        //..
    };
}

#endif //FLASH_EXCEPTIONCODES_H
