//
// Created by roman on 15.09.2020.
//

#ifndef FLASH_PECULIAR_H
#define FLASH_PECULIAR_H

namespace Possibilities {

    /**
     * @brief The base class of the Peculiar class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base Peculiar interface.
    */
    template<class Properties>
    class Peculiar {
    public:
        Peculiar() = default;

        /**
         * @brief Method returns object's properties.
         * @return Object's properties.
         */
        virtual const Properties &getProperties() const noexcept = 0;

        virtual ~Peculiar() = default;
    };
}

#endif //FLASH_PECULIAR_H
