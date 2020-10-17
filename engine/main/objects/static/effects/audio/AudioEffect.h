//
// Created by roman on 17.10.2020.
//

#ifndef FLASH_AUDIOEFFECT_H
#define FLASH_AUDIOEFFECT_H

#include "../Effect.h"

namespace Effects {

    /**
     * @brief The base class of the AudioEffect class hierarchy.
     * @namespace Effects
     *
     * This class defines base AudioEffect realization.
    */
    class AudioEffect : public Effect {
    public:
        AudioEffect(const std::shared_ptr<sf::Music> &audio) : m_audio(audio) {}

    protected:
        std::shared_ptr<sf::Music> m_audio;
    };
}

#endif //FLASH_AUDIOEFFECT_H
