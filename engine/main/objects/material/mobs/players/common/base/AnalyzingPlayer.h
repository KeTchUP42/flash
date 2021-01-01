//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_ANALYZINGPLAYER_H
#define FLASH_ANALYZINGPLAYER_H

#include "Player.h"
#include "../../../../common/algorithms/Algorithms.h"

namespace Mobs {

    class AnalyzingPlayer : public Player {
    public:
        AnalyzingPlayer(
                const Material::MaterialProperties &material_properties,
                const Mobs::MobProperties &properties,
                const Components::Area &area,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<Material::Algorithms> &algorithms
        ) : Player(material_properties, properties, area, sprite), m_algorithms(algorithms) {}

    protected:
        std::shared_ptr<Material::Algorithms> m_algorithms;
    };
}

#endif //FLASH_ANALYZINGPLAYER_H
