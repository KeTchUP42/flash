//
// Created by roman on 13.10.2020.
//

#include "CustomReduction.h"

std::shared_ptr<Material::Algorithms>
Creation::RD::loadAlgorithms(const IniUtil::Analyzer::IniBlock &data, Creation::Pools::SourcePool &pool) {
    return std::make_shared<Material::Algorithms>(pool.getAlgPool()->loadCollision(
            std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                         std::stof(data.at("COLLISION_ANALYSIS_STEP")))
    ));
}

std::shared_ptr<sf::Music>
Creation::RD::loadMusic(const IniUtil::Analyzer::IniBlock &data, Creation::Pools::SourcePool &pool) {
    std::shared_ptr<sf::Music> music = pool.getMusic(data.at("AUDIO"));
    music->setVolume(std::stof(data.at("AUDIO_VOLUME").c_str()));
    music->setLoop(static_cast<bool>(std::atoi(data.at("AUDIO_LOOP").c_str())));
    return music;
}
