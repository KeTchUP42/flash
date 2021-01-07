//
// Created by roman on 09.12.2020.
//

#ifndef FLASH_ALGORITHMSPARAMETERS_H
#define FLASH_ALGORITHMSPARAMETERS_H

#include "../../properties/ParamsTypes.h"

namespace Material {

    /**
     * @brief Struct contains all algorithms numeric parameters.
     */
    struct AlgorithmsParameters {
        AlgorithmsParameters(
                float analysisStepX,
                float analysisStepY
        ) : analysisStepX(analysisStepX),
            analysisStepY(analysisStepY) {}

        /**
         * @brief Collision "X" analysis step.
         */
        float analysisStepX;

        /**
         * @brief Collision "Y" analysis step.
         */
        float analysisStepY;
    };
}

#endif //FLASH_ALGORITHMSPARAMETERS_H
