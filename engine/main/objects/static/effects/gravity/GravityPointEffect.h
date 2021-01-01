//
// Created by roman on 08.10.2020.
//

#ifndef FLASH_GRAVITYPOINTEFFECT_H
#define FLASH_GRAVITYPOINTEFFECT_H

#include "../Effect.h"

namespace Effects {

    class GravityPointEffect : public Effect, public Possibilities::Moving {
    public:
        GravityPointEffect(const Components::Point &point, float acceleration);

        void applyEffect(Unite::Unifier *unifier) override;

        void move(float offsetX, float offsetY) noexcept override;

        const Components::Point &getPoint() const;

        void setPoint(const Components::Point &point) noexcept;

        void setPoint(float x, float y) noexcept;

    protected:
        Components::Point m_point;
        const float ACCELERATION;
    };
}

#endif //FLASH_GRAVITYPOINTEFFECT_H
