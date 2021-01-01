//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_PARTICLE_H
#define FLASH_PARTICLE_H

#include "../../../auxiliary/possibilities/Peculiar.h"
#include "properties/ParticleProperties.h"
#include "../../common/MaterialObject.h"

namespace Particles {

    /**
     * @brief The base class of the Particle class hierarchy. It contains all usefull interfaces.
     * @namespace Obstacles
     *
     * This class defines base Particle interface and realization.
    */
    class Particle : public Material::MaterialObject, public Possibilities::Peculiar<Particles::ParticleProperties> {
    public:
        Particle(const Material::MaterialProperties &material_properties, const ParticleProperties &properties, const Components::Coordinates &coordinates);

        Particle(const Material::MaterialProperties &material_properties, const ParticleProperties &properties);

        const ParticleProperties &getProperties() const noexcept override;

        virtual ~Particle() = default;

    protected:
        ParticleProperties m_properties;
    };
}

#include "../../../unifier/common/Unifier.h"

#endif //FLASH_PARTICLE_H
