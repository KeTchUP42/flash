//
// Created by roman on 20.10.2020.
//

#ifndef FLASH_KEYMAPBUILDER_H
#define FLASH_KEYMAPBUILDER_H

#include "../../../../material/mobs/players/control/KeyAlias.h"
#include "../../../../../../utils/Ini/analyzer/Analyzer.h"
#include "../../pools/SourcePool.h"

#include <map>
#include <SFML/Window/Keyboard.hpp>

namespace Creation {
    namespace RD {
        /**
         * @brief The class is a simplified implementation of the construction pattern for convenient creation and configuration of keymap.
         * @namespace Creation
         *
         * This class defines KeyMapBuilder realization.
        */
        class KeyMapBuilder {
        public:
            explicit KeyMapBuilder(const std::string &filename, Pools::SourcePool &source);

            /**
             * @brief Method sets keymap field.
             * @param alias Key alias.
             * @param block Key block.
             * @param field Key field name.
             * @return This reference.
             */
            KeyMapBuilder &setKey(Mobs::KeyAlias alias, const std::string &block, const std::string &field);

            /**
             * @brief Method returns configured keymap.
             * @return KeyMap.
             */
            const std::map<Mobs::KeyAlias, sf::Keyboard::Key> &getKeyMap() const noexcept;

            /**
             * @brief Method resets keymap.
             * @return This reference.
             */
            KeyMapBuilder &resetKeyMap() noexcept;

            ~KeyMapBuilder() = default;

        private:
            IniUtil::Analyzer::IniData m_keydata;
            std::map<Mobs::KeyAlias, sf::Keyboard::Key> m_keyMap;
        };
    }
}

#endif //FLASH_KEYMAPBUILDER_H
