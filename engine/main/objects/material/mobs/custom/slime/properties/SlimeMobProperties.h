//
// Created by roman on 04.01.2021.
//

#ifndef PRIMARYWINDOW_H_SLIMEMOBPROPERTIES_H
#define PRIMARYWINDOW_H_SLIMEMOBPROPERTIES_H

#include "../../../../common/properties/MaterialProperties.h"
#include "../../../common/properties/MobProperties.h"
#include "../properties/SlimeProperties.h"

namespace Mobs {

    /**
     * @brief All slime properties.
     */
    struct SlimeMobProperties {
        Material::MaterialProperties material_properties;
        Mobs::MobProperties mob_properties;
        Mobs::SlimeProperties slime_properties;
    };
}

#endif //PRIMARYWINDOW_H_SLIMEMOBPROPERTIES_H
