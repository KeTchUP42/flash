//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_WINDOW_H
#define FLASH_WINDOW_H

#include <list>
#include <memory>
#include <thread>
#include <SFML/Graphics.hpp>

#include "../observer/Observer.h"

namespace Windows {

    /**
     * @brief The base class of the Window class hierarchy.
     * @namespace Windows
     *
     * This class defines base Window interface.
    */
    class Window {
    public:

        /**
         * @brief Window observer type alias.
         */
        using Observer = Windows::Observer<sf::Window, sf::Event>;

        /**
         * @brief Constructor.
         * @param mode sf::VideoMode
         * @param title const sf::String&
         * @param style sf::Uint32
         * @param settings const sf::ContextSettings&
         */
        explicit Window(sf::VideoMode mode, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings);

        /**
         * @brief Constructor.
         * @param handle sf::WindowHandle
         * @param settings const sf::ContextSettings&
         */
        explicit Window(sf::WindowHandle handle, const sf::ContextSettings &settings);

        /**
         * @brief Method deletes operator= method.
         * @return Window&
         */
        Window &operator=(const Window &) = delete;

        /**
         * @brief Method adds new observer.
         * @param observer Window::Observer*
         */
        void addObserver(Observer *observer) noexcept;

        /**
         * @brief Method adds new observer.
         * @param observer const std::shared_ptr<Window::Observer> &
         */
        void addObserver(const std::shared_ptr<Observer> &observer) noexcept;

        /**
         * @brief Method removes observer.
         * @param observer const std::shared_ptr<Window::Observer> &
         */
        void removeObserver(const std::shared_ptr<Observer> &observer) noexcept;

        /**
         * @brief Method starts listening circle.
         */
        void start() noexcept;

        /**
         * @brief Method starts listening circle in thread.
         */
        std::thread startAsync() noexcept;

        /**
         * @brief Method notifies all observers with event.
         */
        void notify(const sf::Event &event) noexcept;

    protected:

        /**
         * @brief Method initializes all window components.
         */
        virtual void initialization() noexcept = 0;

        /**
         * @brief Method updates all window components.
         */
        virtual void update() noexcept = 0;

    public:
        virtual ~Window() = default;

    protected:
        std::list<std::shared_ptr<Observer>> _observers;
        sf::RenderWindow _window;
    };
}

#endif //FLASH_WINDOW_H
