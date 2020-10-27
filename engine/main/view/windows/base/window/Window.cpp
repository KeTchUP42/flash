//
// Created by roman on 20.08.2020.
//

#include "Window.h"

WindowView::Window::Window(sf::VideoMode mode, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings)
        : m_window(new sf::RenderWindow(mode, title, style, settings)) {
}

WindowView::Window::Window(sf::WindowHandle handle, const sf::ContextSettings &settings)
        : m_window(new sf::RenderWindow(handle, settings)) {
}

void WindowView::Window::start() {
    while (m_window->isOpen()) {
        sf::Event event;
        while (m_window->pollEvent(event)) {
            this->notify(event);
        }
        this->update();
    }
}

std::thread WindowView::Window::startAsync() noexcept {
    return std::thread([this] { this->start(); });
}

void WindowView::Window::notify(const sf::Event &event) {
    for (std::shared_ptr<Window::Observer> &observer : m_observers) {
        observer->update(event, *m_window);
    }
}

void WindowView::Window::addObserver(Window::Observer *observer) noexcept {
    m_observers.push_back(std::shared_ptr<Window::Observer>(observer));
}

void WindowView::Window::addObserver(const std::shared_ptr<Window::Observer> &observer) noexcept {
    m_observers.push_back(observer);
}

void WindowView::Window::removeObserver(Window::Observer *observer) noexcept {
    m_observers.remove_if([observer](const std::shared_ptr<Window::Observer> &obs) -> bool {
        return obs.get() == observer;
    });
}

void WindowView::Window::removeObserver(const std::shared_ptr<Window::Observer> &observer) noexcept {
    m_observers.remove(observer);
}

void WindowView::Window::setFramerateLimit(unsigned int limit) noexcept {
    m_window->setFramerateLimit(limit);
}

void WindowView::Window::setVerticalSyncEnabled(bool enabled) noexcept {
    m_window->setVerticalSyncEnabled(enabled);
}

void WindowView::Window::setIcon(const sf::Image &image) {
    m_window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

sf::RenderWindow &WindowView::Window::getWindow() const noexcept {
    return *m_window;
}
