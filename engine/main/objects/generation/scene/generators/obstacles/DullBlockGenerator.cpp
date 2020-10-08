//
// Created by roman on 29.09.2020.
//

#include "DullBlockGenerator.h"
#include "../../../../material/obstacles/blocks/sprite-visible/single/DullBlock.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"

Generate::DullBlockGenerator::DullBlockGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::DullBlockGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //point
    Components::Point point(std::stof(data.at("X")), std::stof(data.at("Y")));

    //size
    Components::Size size(std::atoi(data.at("WIDTH").c_str()), std::atoi(data.at("HEIGHT").c_str()));

    //angle
    float angle = std::stof(data.at("ANGLE"));

    //properties
    Components::Speed speed(std::stof(data.at("X_SPEED")), std::stof(data.at("Y_SPEED")));
    float elasticCoefficient = std::stof(data.at("ELASTIC_COEFFICIENT"));
    float frictionCoefficient = std::stof(data.at("FRICTION_COEFFICIENT"));
    bool isFixed = (std::atoi(data.at("IS_FIXED").c_str()) == 1);
    Obstacles::ObstacleProperties properties(speed, elasticCoefficient, frictionCoefficient, isFixed);

    //texture
    auto texture = m_source.getTexture(data.at("TEXTURE"));

    //algorithms
    std::pair<float, float> collisionParams = std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                                                           std::stof(data.at("COLLISION_ANALYSIS_STEP")));

    std::shared_ptr<Material::Algorithms> algorithms(
            new Material::Algorithms(m_source.getAlgpool()->loadCollision(collisionParams)));

    unifier.addObstacle(new Obstacles::DullBlock(properties,
                                                 std::make_shared<Components::SpriteBox>(
                                                         Components::Area(point, size, angle), texture), algorithms));
}
