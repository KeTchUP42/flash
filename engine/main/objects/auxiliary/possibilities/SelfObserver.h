//
// Created by roman on 15.09.2020.
//

#ifndef FLASH_SELFOBSERVER_H
#define FLASH_SELFOBSERVER_H

namespace Possibilities {

    /**
     * @brief The base class of the SelfObserver class hierarchy. Important interface, uses in app components communication.
     * @namespace Possibilities
     *
     * This class defines base SelfObserver interface.
    */
    template<class Event, class Sender>
    class SelfObserver {
    public:
        SelfObserver() = default;

        /**
         * @brief Method uses for components communication.
         * @param event Some information in event DTO class object.
         * @param sender Class sender.
         */
        virtual void selfUpdate(const Event &event, Sender &sender) = 0;

        virtual ~SelfObserver() = default;
    };
}

#endif //FLASH_SELFOBSERVER_H
