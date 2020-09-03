//
// Created by roman on 03.09.2020.
//

#ifndef FLASH_REFRESHABLE_H
#define FLASH_REFRESHABLE_H

namespace Capabilities {

    /**
     * @brief The base class of the Refreshable class hierarchy.
     * @namespace Capabilities
     *
     * This class defines base Refreshable interface.
    */
    class Refreshable {
    public:
        Refreshable() = default;

        /**
         * @brief Method uses for components refresh logic.
         */
        virtual void refresh() = 0;

        virtual ~Refreshable() = default;
    };
}

#endif //FLASH_REFRESHABLE_H
