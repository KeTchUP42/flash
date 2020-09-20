//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_UNIFIER_H
#define FLASH_UNIFIER_H

#include "../../auxiliary/possibilities/Drawable.h"
#include "../../../view/windows/base/observer/Observer.h"
#include "../../../view/windows/screen/context-abilities/StateChangeable.h"

namespace Obstacles {
    class Obstacle;
}

namespace Mobs {
    class Player;

    class Monster;
}

namespace Components {
    class ISprite;
}

namespace Effects {
    class Effect;
}

namespace Triggers {
    class Trigger;
}

namespace Unite {

    class Unifier : public Possibilities::Drawable<sf::RenderWindow>,
                    public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        /**
         * @brief Method deletes operator= method.
         * @return Unifier&
         */
        Unifier &operator=(const Unifier &) = delete;

        /**
         * @brief Method uses for components refresh logic.
         */
        virtual void refresh() = 0;

        /**
         * @brief Method adds new back sprite.
         * @param sprite New back sprite.
         */
        void addBackSprite(Components::ISprite *sprite) noexcept;

        /**
         * @brief Method adds new back sprite.
         * @param sprite New back sprite.
         */
        void addBackSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept;

        /**
         * @brief Method removes sprite.
         * @param sprite Existing sprite.
         */
        void removeBackSprite(Components::ISprite *sprite) noexcept;

        /**
         * @brief Method removes back sprite.
         * @param sprite Existing sprite.
         */
        void removeBackSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept;

        /**
         * @brief Method returns const reference on sprites collection.
         * @return Const reference on sprites collection.
         */
        const std::list<std::shared_ptr<Components::ISprite>> &getBackSprites() const noexcept;

        //..

        /**
         * @brief Method adds new front sprite.
         * @param sprite New front sprite.
         */
        void addFrontSprite(Components::ISprite *sprite) noexcept;

        /**
         * @brief Method adds new front sprite.
         * @param sprite New front sprite.
         */
        void addFrontSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept;

        /**
         * @brief Method removes sprite.
         * @param sprite Existing sprite.
         */
        void removeFrontSprite(Components::ISprite *sprite) noexcept;

        /**
         * @brief Method removes front sprite.
         * @param sprite Existing sprite.
         */
        void removeFrontSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept;

        /**
         * @brief Method returns const reference on sprites collection.
         * @return Const reference on sprites collection.
         */
        const std::list<std::shared_ptr<Components::ISprite>> &getFrontSprites() const noexcept;

        //..

        /**
         * @brief Method adds new obstacle.
         * @param obstacle New obstacle.
         */
        void addObstacle(Obstacles::Obstacle *obstacle) noexcept;

        /**
         * @brief Method adds new obstacle.
         * @param obstacle New obstacle.
         */
        void addObstacle(const std::shared_ptr<Obstacles::Obstacle> &obstacle) noexcept;

        /**
         * @brief Method removes obstacle.
         * @param obstacle Existing obstacle.
         */
        void removeObstacle(Obstacles::Obstacle *obstacle) noexcept;

        /**
         * @brief Method removes obstacle.
         * @param obstacle Existing obstacle.
         */
        void removeObstacle(const std::shared_ptr<Obstacles::Obstacle> &obstacle) noexcept;

        /**
         * @brief Method returns const reference on obstacles collection.
         * @return Const reference on obstacles collection.
         */
        const std::list<std::shared_ptr<Obstacles::Obstacle>> &getObstacles() const noexcept;

        //..

        /**
         * @brief Method adds new player.
         * @param player New player.
         */
        void addPlayer(Mobs::Player *player) noexcept;

        /**
         * @brief Method adds new player.
         * @param player New player.
         */
        void addPlayer(const std::shared_ptr<Mobs::Player> &player) noexcept;

        /**
         * @brief Method removes player.
         * @param player Existing player.
         */
        void removePlayer(Mobs::Player *player) noexcept;

        /**
         * @brief Method removes player.
         * @param player Existing player.
         */
        void removePlayer(const std::shared_ptr<Mobs::Player> &player) noexcept;

        /**
         * @brief Method returns const reference on players collection.
         * @return Const reference on players collection.
         */
        const std::list<std::shared_ptr<Mobs::Player>> &getPlayers() const noexcept;

        //..

        /**
         * @brief Method adds new monster.
         * @param monster New monster.
         */
        void addMonster(Mobs::Monster *monster) noexcept;

        /**
         * @brief Method adds new monster.
         * @param monster New monster.
         */
        void addMonster(const std::shared_ptr<Mobs::Monster> &monster) noexcept;

        /**
         * @brief Method removes monster.
         * @param monster Existing monster.
         */
        void removeMonster(Mobs::Monster *monster) noexcept;

        /**
         * @brief Method removes monster.
         * @param monster Existing monster.
         */
        void removeMonster(const std::shared_ptr<Mobs::Monster> &monster) noexcept;

        /**
         * @brief Method returns const reference on monsters collection.
         * @return Const reference on monsters collection.
         */
        const std::list<std::shared_ptr<Mobs::Monster>> &getMonsters() const noexcept;

        //..

        /**
         * @brief Method adds new effect.
         * @param effect New effect.
         */
        void addEffect(Effects::Effect *effect) noexcept;

        /**
         * @brief Method adds new effect.
         * @param effect New effect.
         */
        void addEffect(const std::shared_ptr<Effects::Effect> &effect) noexcept;

        /**
         * @brief Method removes effect.
         * @param effect Existing effect.
         */
        void removeEffect(Effects::Effect *effect) noexcept;

        /**
         * @brief Method removes effect.
         * @param effect Existing effect.
         */
        void removeEffect(const std::shared_ptr<Effects::Effect> &effect) noexcept;

        /**
         * @brief Method returns const reference on effects collection.
         * @return Const reference on effects collection.
         */
        const std::list<std::shared_ptr<Effects::Effect>> &getEffects() const noexcept;

        //..

        /**
         * @brief Method adds new trigger.
         * @param trigger New trigger.
         */
        void addTrigger(Triggers::Trigger *trigger) noexcept;

        /**
         * @brief Method adds new trigger.
         * @param trigger New trigger.
         */
        void addTrigger(const std::shared_ptr<Triggers::Trigger> &trigger) noexcept;

        /**
         * @brief Method removes trigger.
         * @param trigger Existing trigger.
         */
        void removeTrigger(Triggers::Trigger *trigger) noexcept;

        /**
         * @brief Method removes trigger.
         * @param trigger Existing trigger.
         */
        void removeTrigger(const std::shared_ptr<Triggers::Trigger> &trigger) noexcept;

        /**
         * @brief Method returns const reference on triggers collection.
         * @return Const reference on triggers collection.
         */
        const std::list<std::shared_ptr<Triggers::Trigger>> &getTriggers() const noexcept;

        virtual ~Unifier() = default;

    protected:
        /**
         * @brief Back sprites.
         */
        std::list<std::shared_ptr<Components::ISprite>> _back;

        /**
         * @brief Front sprites.
        */
        std::list<std::shared_ptr<Components::ISprite>> _front;

        /**
         * @brief Obstacles.
         */
        std::list<std::shared_ptr<Obstacles::Obstacle>> _obstacles;

        /**
         * @brief Players.
         */
        std::list<std::shared_ptr<Mobs::Player>> _players;

        /**
         * @brief Monsters.
            */
        std::list<std::shared_ptr<Mobs::Monster>> _monsters;

        /**
         * @brief Effects.
         */
        std::list<std::shared_ptr<Effects::Effect>> _effects;

        /**
         * @brief Triggers.
         */
        std::list<std::shared_ptr<Triggers::Trigger>> _triggers;
    };
}

#include "../../material/mobs/player/common-base/Player.h"
#include "../../material/mobs/monsters/common-base/Monster.h"
#include "../../material/obstacles/shared/Obstacle.h"
#include "../../static/triggers/Trigger.h"
#include "../../static/effects/Effect.h"

#endif //FLASH_UNIFIER_H
