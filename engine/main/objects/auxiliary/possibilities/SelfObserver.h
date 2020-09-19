//
// Created by roman on 15.09.2020.
//

#ifndef FLASH_SELFOBSERVER_H
#define FLASH_SELFOBSERVER_H

namespace Possibilities {

    /**
     * @brief The base class of the SelfObserver class hierarchy. Important interface, uses in components communication.
     * @namespace Possibilities
     *
     * This class defines base SelfObserver interface.
    */
    template<class Event, class Sender>
    class SelfObserver {
    public:
        SelfObserver() = default;

        /**
         * @brief Method uses for components communication. From top to down.
         * @param event Some information in event DTO class object.
         * @param sender Class sender.
         */
        virtual void selfUpdateDown(const Event &event, Sender &sender) = 0;

        /**
         * @brief Method uses for components communication. From down to top.
         * @param event Some information in event DTO class object.
         * @param sender Class sender.
         */
        virtual void selfUpdateUp(const Event &event, Sender &sender) = 0;

        virtual ~SelfObserver() = default;
    };
}

#endif //FLASH_SELFOBSERVER_H
