//
// Created by roman on 20.08.2020.
//

#include "Window.h"

View::Window::Window(sf::VideoMode mode, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings)
        : m_window(new sf::RenderWindow(mode, title, style, settings)) {
}

View::Window::Window(sf::WindowHandle handle, const sf::ContextSettings &settings)
        : m_window(new sf::RenderWindow(handle, settings)) {
}

void View::Window::start() {
    while (m_window->isOpen()) {
        sf::Event event;
        while (m_window->pollEvent(event)) {
            this->notify(event);
        }
        m_window->clear(m_back);
        this->update();
        m_window->display();
    }
}

std::thread View::Window::startAsync() noexcept {
    return std::thread([this] { this->start(); });
}

void View::Window::notify(const sf::Event &event) {
    for (std::shared_ptr<Window::Observer> &observer : m_observers) {
        observer->update(event, *this);
    }
}

void View::Window::addObserver(Window::Observer *observer) noexcept {
    m_observers.push_back(std::shared_ptr<Window::Observer>(observer));
}

void View::Window::addObserver(const std::shared_ptr<Window::Observer> &observer) noexcept {
    m_observers.push_back(observer);
}

void View::Window::removeObserver(Window::Observer *observer) noexcept {
    m_observers.remove_if([observer](const std::shared_ptr<Window::Observer> &obs) -> bool {
        return obs.get() == observer;
    });
}

void View::Window::removeObserver(const std::shared_ptr<Window::Observer> &observer) noexcept {
    m_observers.remove(observer);
}

void View::Window::setFramerateLimit(unsigned int limit) noexcept {
    m_window->setFramerateLimit(limit);
}

void View::Window::setVerticalSyncEnabled(bool enabled) noexcept {
    m_window->setVerticalSyncEnabled(enabled);
}

void View::Window::setIcon(const sf::Image &image) {
    m_window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

void View::Window::setBackColor(const sf::Color &color) {
    m_back = color;
}

sf::RenderWindow &View::Window::getWindow() const noexcept {
    return *m_window;
}
