//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_UNIFIER_H
#define FLASH_UNIFIER_H

#include "../../auxiliary/possibilities/Drawable.h"
#include "../../../view/windows/base/observer/Observer.h"
#include "../../../view/windows/base/window/Window.h"
#include "../../../data/manager/DataManager.h"

#include <list>
#include <functional>

namespace Particles {
    class Particle;

    class Bullet;
}

namespace Obstacles {
    class Obstacle;

    class Block;
}

namespace Mobs {
    class Player;

    class Mob;
}

namespace Components {
    class ISprite;

    class Text;
}

namespace Effects {
    class Effect;
}

namespace Triggers {
    class Trigger;
}

namespace Unite {

    class Unifier : public Possibilities::Drawable<sf::RenderWindow>,
                    public View::Observer<sf::Event, View::Window> {
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
         * @brief Method removes back sprite.
         * @param sprite Existing back sprite.
         */
        void removeBackSprite(Components::ISprite *sprite) noexcept;

        /**
         * @brief Method removes back sprite.
         * @param sprite Existing back sprite.
         */
        void removeBackSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept;

        /**
         * @brief Method returns const reference on back sprites collection.
         * @return Const reference on back sprites collection.
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
         * @param sprite Existing front sprite.
         */
        void removeFrontSprite(Components::ISprite *sprite) noexcept;

        /**
         * @brief Method removes front sprite.
         * @param sprite Existing front sprite.
         */
        void removeFrontSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept;

        /**
         * @brief Method returns const reference on front sprites collection.
         * @return Const reference on front sprites collection.
         */
        const std::list<std::shared_ptr<Components::ISprite>> &getFrontSprites() const noexcept;

        //..

        /**
         * @brief Method adds new text area.
         * @param text New text area.
        */
        void addText(Components::Text *text) noexcept;

        /**
         * @brief Method adds new text area.
         * @param text New text area.
         */
        void addText(const std::shared_ptr<Components::Text> &text) noexcept;

        /**
         * @brief Method removes text area.
         * @param text Existing text area.
         */
        void removeText(Components::Text *text) noexcept;

        /**
         * @brief Method removes text.
         * @param text Existing text area.
         */
        void removeText(const std::shared_ptr<Components::Text> &text) noexcept;

        /**
         * @brief Method returns const reference on text collection.
         * @return Const reference on text areas collection.
         */
        const std::list<std::shared_ptr<Components::Text>> &getTextAreas() const noexcept;

        //..

        /**
         * @brief Method adds new particle.
         * @param particle New particle.
         */
        void addParticle(Particles::Particle *particle) noexcept;

        /**
         * @brief Method adds new particle.
         * @param particle New particle.
         */
        void addParticle(const std::shared_ptr<Particles::Particle> &particle) noexcept;

        /**
         * @brief Method removes particle.
         * @param particle Existing particle.
         */
        void removeParticle(Particles::Particle *particle) noexcept;

        /**
         * @brief Method removes particle.
         * @param particle Existing particle.
         */
        void removeParticle(const std::shared_ptr<Particles::Particle> &particle) noexcept;

        /**
         * @brief Method returns const reference on particles collection.
         * @return Const reference on particles collection.
         */
        const std::list<std::shared_ptr<Particles::Particle>> &getParticles() const noexcept;

        //..

        /**
         * @brief Method adds new bullet.
         * @param bullet New bullet.
         */
        void addBullet(Particles::Bullet *bullet) noexcept;

        /**
         * @brief Method adds new bullet.
         * @param bullet New bullet.
         */
        void addBullet(const std::shared_ptr<Particles::Bullet> &bullet) noexcept;

        /**
         * @brief Method adds new bullet.
         * @param bullet New bullet.
         */
        void addBullet(const std::shared_ptr<Particles::Particle> &bullet) noexcept;

        /**
         * @brief Method removes bullet.
         * @param bullet Existing bullet.
         */
        void removeBullet(Particles::Bullet *bullet) noexcept;

        /**
         * @brief Method removes bullet.
         * @param bullet Existing bullet.
         */
        void removeBullet(const std::shared_ptr<Particles::Bullet> &bullet) noexcept;

        /**
         * @brief Method searches bullet in particles collection.
         * @param block Needed bullet's pointer.
         * @return Bullet pointer.
         */
        const std::shared_ptr<Particles::Particle> &getBullet(Particles::Bullet *bullet) const;

        /**
         * @brief Method returns const reference on bullets collection.
         * @return Const reference on bullets collection.
         */
        const std::list<Particles::Bullet *> &getBullets() const noexcept;

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
         * @brief Method adds new block.
         * @param block New block.
         */
        void addBlock(Obstacles::Block *block) noexcept;

        /**
         * @brief Method adds new block.
         * @param block New block.
         */
        void addBlock(const std::shared_ptr<Obstacles::Block> &block) noexcept;

        /**
         * @brief Method adds new block.
         * @param block New block.
         */
        void addBlock(const std::shared_ptr<Obstacles::Obstacle> &block);

        /**
         * @brief Method removes block.
         * @param block Existing block.
         */
        void removeBlock(Obstacles::Block *blck) noexcept;

        /**
         * @brief Method removes block.
         * @param block Existing block.
         */
        void removeBlock(const std::shared_ptr<Obstacles::Block> &block) noexcept;

        /**
         * @brief Method searches block in obstacle collection.
         * @param block Needed block's pointer.
         * @return Block pointer.
         */
        const std::shared_ptr<Obstacles::Obstacle> &getBlock(Obstacles::Block *block) const;

        /**
         * @brief Method returns const reference on blocks collection.
         * @return Const reference on blocks collection.
         */
        const std::list<Obstacles::Block *> &getBlocks() const noexcept;

        //..

        /**
         * @brief Method adds new mob.
         * @param mob New mob.
         */
        void addMob(Mobs::Mob *mob) noexcept;

        /**
         * @brief Method adds new mob.
         * @param mob New mob.
         */
        void addMob(const std::shared_ptr<Mobs::Mob> &mob) noexcept;

        /**
         * @brief Method removes mob.
         * @param mob Existing mob.
         */
        void removeMob(Mobs::Mob *mb) noexcept;

        /**
         * @brief Method removes mob.
         * @param mob Existing mob.
         */
        void removeMob(const std::shared_ptr<Mobs::Mob> &mob) noexcept;

        /**
         * @brief Method returns const reference on mobs collection.
         * @return Const reference on mobs collection.
         */
        const std::list<std::shared_ptr<Mobs::Mob>> &getMobs() const noexcept;

        //..

        /**
         * @brief Method adds new stand-alone mob.
         * @param mob New stand-alone mob.
         */
        void addStandAloneMob(Mobs::Mob *mob) noexcept;

        /**
         * @brief Method adds new stand-alone mob.
         * @param mob New stand-alone mob.
         */
        void addStandAloneMob(const std::shared_ptr<Mobs::Mob> &mob) noexcept;

        /**
         * @brief Method removes stand-alone mob.
         * @param mob Existing stand-alone mob.
         */
        void removeStandAloneMob(Mobs::Mob *mob) noexcept;

        /**
         * @brief Method removes stand-alone mob.
         * @param mob Existing stand-alone mob.
         */
        void removeStandAloneMob(const std::shared_ptr<Mobs::Mob> &mob) noexcept;

        /**
         * @brief Method returns const reference on stand-alone mobs collection.
         * @return Const reference on stand-alone mobs collection.
         */
        const std::list<Mobs::Mob *> &getStandAloneMobs() const noexcept;

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
         * @brief Method adds new player.
         * @param player New player.
         */
        void addPlayer(const std::shared_ptr<Mobs::Mob> &player);

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
         * @brief Method searches player in mob collection.
         * @param player Needed player's pointer.
         * @return Player pointer.
         */
        const std::shared_ptr<Mobs::Mob> &getPlayer(Mobs::Player *player) const;

        /**
         * @brief Method returns const reference on players collection.
         * @return Const reference on players collection.
         */
        const std::list<Mobs::Player *> &getPlayers() const noexcept;

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

        //..

        /**
         * @brief Method adds new frame action. All frame events take place at the end of object interaction.
         * @param action New frame action.
         */
        void addFrameAction(const std::function<void(Unite::Unifier *)> &action) noexcept;

        virtual ~Unifier() = default;

    protected:
        /**
         * @brief Back sprites.
         */
        std::list<std::shared_ptr<Components::ISprite>> m_back_sprites;

        /**
         * @brief Front sprites.
        */
        std::list<std::shared_ptr<Components::ISprite>> m_front_sprites;

        /**
         * @brief Screen text.
         */
        std::list<std::shared_ptr<Components::Text>> m_screen_text;

        /**
         * @brief All particles;
         */
        std::list<std::shared_ptr<Particles::Particle>> m_particles;

        /**
         * @brief Bullets.
         */
        std::list<Particles::Bullet *> m_bullets;

        /**
         * @brief All obstacles.
         */
        std::list<std::shared_ptr<Obstacles::Obstacle>> m_obstacles;

        /**
         * @brief Blocks.
         */
        std::list<Obstacles::Block *> m_blocks;

        /**
         * @brief All mobs.
         */
        std::list<std::shared_ptr<Mobs::Mob>> m_mobs;

        /**
         * @brief Stand-alone  mobs.
         */
        std::list<Mobs::Mob *> m_stand_alone_mobs;

        /**
        * @brief Players.
         */
        std::list<Mobs::Player *> m_players;

        /**
         * @brief Effects.
         */
        std::list<std::shared_ptr<Effects::Effect>> m_effects;

        /**
         * @brief Triggers.
         */
        std::list<std::shared_ptr<Triggers::Trigger>> m_triggers;

        /**
         * @brief Frame actions.
         */
        std::list<std::function<void(Unite::Unifier *)>> m_frame_actions;
    };
}

#include "../../material/particles/common/Particle.h"
#include "../../material/particles/bullets/common/base/Bullet.h"
#include "../../material/mobs/common/base/Mob.h"
#include "../../material/mobs/players/common/base/Player.h"
#include "../../material/obstacles/common/Obstacle.h"
#include "../../material/obstacles/blocks/common/Block.h"
#include "../../auxiliary/components/text/Text.h"
#include "../../static/triggers/common/Trigger.h"
#include "../../static/effects/Effect.h"

#endif //FLASH_UNIFIER_H
