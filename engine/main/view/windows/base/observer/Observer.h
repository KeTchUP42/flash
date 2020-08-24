//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_OBSERVER_H
#define FLASH_OBSERVER_H

#include <SFML/Window.hpp>

namespace Windows {

    /**
     * @brief The base class of the Observer class hierarchy.
     * @namespace Windows
     *
     * This class defines base Observer interface.
    */
    template<class Sender, class Event>
    class Observer {
    public:
        Observer() = default;

        /**
         * @brief Sender calls this method every time any Event was.
         * @param event Event
         * @param window Sender
         */
        virtual void update(const Event &event, Sender &sender) noexcept = 0;

        virtual ~Observer() = default;
    };
}

#endif //FLASH_OBSERVER_H
