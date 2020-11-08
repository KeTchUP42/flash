//
// Created by roman on 08.11.2020.
//

#include "Size.h"

bool Components::operator==(const Components::Size &left, const Components::Size &right) noexcept {
    return (left.width == right.width) && (left.height == right.height);
}

bool Components::operator!=(const Components::Size &left, const Components::Size &right) noexcept {
    return !(right == left);
}