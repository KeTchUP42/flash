//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_TRIGGER_H
#define FLASH_TRIGGER_H

namespace Triggers {

    /**
     * @brief The base class of the Trigger class hierarchy.
     * @namespace Triggers
     *
     * This class defines base Trigger interface.
    */
    class Trigger {
    public:
        Trigger() = default;

        virtual ~Trigger() = default;
    };
}

#endif //FLASH_TRIGGER_H
