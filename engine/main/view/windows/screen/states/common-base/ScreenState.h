//
// Created by roman on 01.09.2020.
//

#ifndef FLASH_SCREENSTATE_H
#define FLASH_SCREENSTATE_H

#include "../../../../../objects/auxiliary/possibilities/Drawable.h"
#include "../../context-abilities/StateChangeable.h"
#include "../../../../../data/manager/DataManager.h"
#include "../../../base/observer/Observer.h"
#include "../../../base/window/Window.h"

namespace View {

    class StateChangeable;

    /**
     * @brief This class is an interest of the state from the state pattern.
     * @namespace View
     *
     * This class defines base ScreenState interface and fields.
    */
    class ScreenState : public Possibilities::Drawable<sf::RenderWindow>,
                        public View::Observer<sf::Event, View::Window> {
    public:
        /**
         * @brief Constructors may have transit data.
         */
        ScreenState(const std::string &filename) : m_scene_file(filename) {};

        /**
         * @brief Method inits all screen components.
         * @param context StateChangeable context.
         * @param manager Manager for data searching.
         * @param window Render window.
         */
        virtual void load(StateChangeable *context, Managers::DataManager *manager, View::Window &window) = 0;

        /**
         * @brief Method uses for components refresh logic.
         */
        virtual void refresh() = 0;

        virtual ~ScreenState() = default;

    protected:
        /**
         * @brief Scene file name.
         */
        std::string m_scene_file;
    };
}

#endif //FLASH_SCREENSTATE_H
