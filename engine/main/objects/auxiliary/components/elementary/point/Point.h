//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_POINT_H
#define FLASH_POINT_H

namespace Components {

    /**
     * @brief Base component.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Point {

        /**
         * @brief Base constructor. Inits "x" and "y" by zero.
         */
        Point();

        /**
         * @brief Inits "x" and "y".
         * @param x coordinate.
         * @param y coordinate.
         */
        Point(float x, float y);

        /**
         * @brief Method overloads operator "+".
         * @param right Right operand.
         */
        Point operator+(const Point &right);

        /**
         * @brief Method overloads operator "-".
         * @param right Right operand.
         */
        Point operator-(const Point &right);

        /**
         * @brief Method overloads operator "+=".
         * @param right Right operand.
         */
        Point &operator+=(const Point &right);

        /**
         * @brief Method overloads operator "-=".
         * @param right Right operand.
         */
        Point &operator-=(const Point &right);

        /**
         * @brief Method overload comparison operator.
         * @param rhs Compared object.
         */
        bool operator==(const Point &rhs) const noexcept;

        /**
         * @brief Method overload comparison operator.
         * @param rhs Compared object.
         */
        bool operator!=(const Point &rhs) const noexcept;

        float x;
        float y;
    };
}

#endif //FLASH_POINT_H
