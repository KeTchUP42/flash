//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_OBSERVER_H
#define FLASH_OBSERVER_H

namespace WindowView {

    /**
     * @brief The base class of the Observer class hierarchy.
     * @namespace WindowView
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
         * @param sender Sender
         */
        virtual void update(const Event &event, Sender &sender) = 0;

        virtual ~Observer() = default;
    };
}

#endif //FLASH_OBSERVER_H
