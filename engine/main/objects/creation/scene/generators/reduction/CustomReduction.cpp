//
// Created by roman on 13.10.2020.
//

#include "CustomReduction.h"

std::shared_ptr<Material::Algorithms>
Creation::loadAlgorithms(const IniUtil::Analyzer::IniBlock &data, Creation::Pools::SourcePool &pool) {
    //collision
    std::pair<float, float> collisionParams = std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                                                           std::stof(data.at("COLLISION_ANALYSIS_STEP")));
    return std::make_shared<Material::Algorithms>(pool.getAlgpool()->loadCollision(collisionParams));
}

std::shared_ptr<sf::Music>
Creation::loadMusic(const IniUtil::Analyzer::IniBlock &data, Creation::Pools::SourcePool &pool) {
    std::shared_ptr<sf::Music> music = pool.getMusic(data.at("AUDIO"));
    music->setVolume(std::atof(data.at("AUDIO_VOLUME").c_str()));
    music->setLoop(static_cast<bool>(std::atoi(data.at("AUDIO_LOOP").c_str())));
    return music;
}
