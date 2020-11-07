//
// Created by roman on 01.11.2020.
//

#ifndef FLASH_BLOCK_H
#define FLASH_BLOCK_H

#include "../../common/Obstacle.h"
#include "../../../../auxiliary/possibilities/rectangle/Rectangle.h"

namespace Obstacles {

    class Block : public Obstacle, public Possibilities::Rectangle {
    public:
        Block(const ObstacleProperties &properties) : Obstacle(properties) {}

        void updateCoordinates() noexcept override;

        virtual ~Block() = default;
    };
}

#endif //FLASH_BLOCK_H
