//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_AREATRIGGER_H
#define FLASH_AREATRIGGER_H

#include "Trigger.h"
#include "../../../auxiliary/components/elementary/area/Area.h"
#include "../../../auxiliary/possibilities/rectangle/MaterialRectangle.h"
#include "../../../material/common/collision/algorithms/collision/CommonCollisionAlgorithms.h"
#include "../../../auxiliary/computations/CoordinatesComputations.h"

namespace Triggers {

    /**
     * @brief The base class of the AreaTrigger class hierarchy.
     * @namespace Triggers
     *
     * This class defines base AreaTrigger interface and realization.
    */
    class AreaTrigger : public Trigger, public Possibilities::MaterialRectangle {
    public:
        AreaTrigger(const Components::Area &area) : m_area(area), m_coordinates(Calculations::coordinates(*this)) {}

        void update(const sf::Event &event, View::Window &sender) override;

        const Components::Coordinates &getCoordinates() const noexcept override;

        const Components::Point &getPosition() const noexcept override;

        const Components::Size &getSize() const noexcept override;

        float getRotation() const noexcept override;

    protected:
        Components::Area m_area;
        Components::Coordinates m_coordinates;
    };
}

#endif //FLASH_AREATRIGGER_H
