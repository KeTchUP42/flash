//
// Created by roman on 15.09.2020.
//

#ifndef FLASH_ELASTIC_H
#define FLASH_ELASTIC_H

namespace Possibilities {

    /**
     * @brief The base class of the Elastic class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base Elastic interface.
    */
    class Elastic {
    public:
        Elastic() = default;

        /**
         * @brief Method returns object's elastic coefficient.
         * @return Elastic coefficient.
         */
        virtual float getElasticCoefficient() const noexcept = 0;

        virtual ~Elastic() = default;
    };
}

#endif //FLASH_ELASTIC_H
