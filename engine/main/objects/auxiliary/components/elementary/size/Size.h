//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_SIZE_H
#define FLASH_SIZE_H

namespace Components {

    /**
     * @brief The structure is used to describe the object size.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Size {
        /**
         * @brief Inits "width" and "height".
         * @param "width" value.
         * @param "height" value.
         */
        Size(unsigned int width, unsigned int height);

        /**
         * @brief Base constructor. Inits "width" and "height" by zero.
         */
        Size() : width(), height() {}

        unsigned int width;
        unsigned int height;
    };

    /**
     * @brief Method overloads comparison operator.
     * @param left Left operand.
     * @param right Compared object.
     */
    bool operator==(const Size &left, const Size &right) noexcept;

    /**
     * @brief Method overloads comparison operator.
     * @param left Left operand.
     * @param right Compared object.
     */
    bool operator!=(const Size &left, const Size &right) noexcept;
}

#endif //FLASH_SIZE_H
