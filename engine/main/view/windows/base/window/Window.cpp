//
// Created by roman on 20.08.2020.
//

#include "Window.h"

Windows::Window::Window(sf::VideoMode mode, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings)
        : _window(mode, title, style, settings) {
}

Windows::Window::Window(sf::WindowHandle handle, const sf::ContextSettings &settings)
        : _window(handle, settings) {
}

void Windows::Window::start() noexcept {
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            this->notify(event);
        }
        this->update();
    }
}

std::thread Windows::Window::startAsync() noexcept {
    return std::thread([this] { this->start(); });
}

void Windows::Window::notify(const sf::Event &event) noexcept {
    for (std::shared_ptr<Window::Observer> observer : _observers) {
        observer->update(event, _window);
    }
}

void Windows::Window::addObserver(Window::Observer *observer) noexcept {
    _observers.push_back(std::shared_ptr<Window::Observer>(observer));
}

void Windows::Window::addObserver(const std::shared_ptr<Window::Observer> &observer) noexcept {
    _observers.push_back(observer);
}

void Windows::Window::removeObserver(const std::shared_ptr<Window::Observer> &observer) noexcept {
    _observers.remove(observer);
}
