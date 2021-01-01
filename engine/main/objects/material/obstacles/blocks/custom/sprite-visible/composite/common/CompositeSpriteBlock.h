//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_COMPOSITESPRITEBLOCK_H
#define FLASH_COMPOSITESPRITEBLOCK_H

#include "../../../../common/AnalyzingBlock.h"
#include "../../../../../../../auxiliary/components/sprite/primitive/ISpriteBox.h"

namespace Obstacles {

    class CompositeSpriteBlock : public AnalyzingBlock {
    public:
        CompositeSpriteBlock(
                const Material::MaterialProperties &material_properties,
                const ObstacleProperties &properties,
                const Components::Area &area,
                const std::shared_ptr<Components::ISprite> &sprite,
                const std::shared_ptr<Material::Algorithms> &algorithms
        );

        /**
         * @brief Method changes block's sprite.
         * @param sprite New sprite.
         */
        void loadNewSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept;

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Components::Point &point) noexcept override;

        virtual ~CompositeSpriteBlock() = default;

    protected:
        std::shared_ptr<Components::ISprite> m_sprite;
    };
}

#endif //FLASH_COMPOSITESPRITEBLOCK_H
