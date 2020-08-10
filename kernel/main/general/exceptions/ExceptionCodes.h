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
        RUNTIME_EXCEPTION = 100,
        LOGIC_ERROR = 200,
        INVALID_ARGUMENT = 300,
        //..
    };
}

#endif //FLASH_EXCEPTIONCODES_H
