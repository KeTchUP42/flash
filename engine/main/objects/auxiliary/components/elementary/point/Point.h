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

        float x;
        float y;
    };

    /**
     * @brief Method overloads operator "+".
     * @param left Left operand.
     * @param right Right operand.
     */
    Point operator+(const Point &left, const Point &right);

    /**
     * @brief Method overloads operator "-".
     * @param left Left operand.
     * @param right Right operand.
     */
    Point operator-(const Point &left, const Point &right);

    /**
     * @brief Method overloads operator "+=".
     * @param left Left operand.
     * @param right Right operand.
     */
    Point &operator+=(Point &left, const Point &right);

    /**
     * @brief Method overloads operator "-=".
     * @param left Left operand.
     * @param right Right operand.
     */
    Point &operator-=(Point &left, const Point &right);

    /**
     * @brief Method overload comparison operator.
     * @param left Left operand.
     * @param right Compared object.
     */
    bool operator==(const Point &left, const Point &right) noexcept;

    /**
     * @brief Method overload comparison operator.
     * @param left Left operand.
     * @param right Compared object.
     */
    bool operator!=(const Point &left, const Point &right) noexcept;
}

#endif //FLASH_POINT_H
