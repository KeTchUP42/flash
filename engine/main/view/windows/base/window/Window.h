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

namespace View {

    /**
     * @brief The class is a convenient wrapper above the library window.
     * @namespace View
     *
     * This class provides convenient opportunities to listen to the window events.
    */
    class Window {
    public:
        /**
         * @brief Window observer alias.
         */
        using Observer = View::Observer<sf::Event, View::Window>;

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
         * @param observer New window observer.
         */
        void addObserver(Observer *observer) noexcept;

        /**
         * @brief Method adds new observer.
         * @param observer New window observer.
         */
        void addObserver(const std::shared_ptr<Observer> &observer) noexcept;

        /**
         * @brief Method removes observer.
         * @param observer Existing window observer.
         */
        void removeObserver(Observer *observer) noexcept;

        /**
         * @brief Method removes observer.
         * @param observer Existing window observer.
         */
        void removeObserver(const std::shared_ptr<Observer> &observer) noexcept;

        /**
         * @brief Method sets window FPS, for more info look SFML docs.
         * @param limit Framerate limit.
         */
        void setFramerateLimit(unsigned int limit) noexcept;

        /**
         * @brief Method sets vertical Sync enabled value.
         * @param enabled
         */
        void setVerticalSyncEnabled(bool enabled) noexcept;

        /**
         * @brief Method sets window background color, by default color is black.
         * @param color Back color.
         */
        void setBackColor(const sf::Color &color);

        /**
         * @brief Method sets window icon image.
         * @param image Icon image.
         */
        void setIcon(const sf::Image &image);

        /**
         * @brief Method returns SFML window.
         * @return Window.
         */
        sf::RenderWindow &getWindow() const noexcept;

        /**
         * @brief Method starts window "life" cycle.
         */
        void start();

        /**
         * @brief Method starts window "life" cycle in thread.
         */
        std::thread startAsync() noexcept;

        /**
         * @brief Method notifies all observers with event.
         */
        void notify(const sf::Event &event);

    protected:
        /**
         * @brief Method initializes all window components.
         */
        virtual void initialization() = 0;

        /**
         * @brief Method updates all window components.
         */
        virtual void update() = 0;

    public:
        virtual ~Window() = default;

    protected:
        sf::Color m_back;
        std::list<std::shared_ptr<Observer>> m_observers;
        std::unique_ptr<sf::RenderWindow> m_window;
    };
}

#endif //FLASH_WINDOW_H
