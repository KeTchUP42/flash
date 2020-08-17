//
// Created by roman on 17.08.2020.
//

#ifndef FLASH_AUDIOPLAYBACK_H
#define FLASH_AUDIOPLAYBACK_H

#include <string>

namespace Audio {

    void playMusic(const std::string &filename) noexcept;

    void playMusicAsync(const std::string &filename) noexcept;

    void playSound(const std::string &filename) noexcept;

    void playSoundAsync(const std::string &filename) noexcept;
}

#endif //FLASH_AUDIOPLAYBACK_H
