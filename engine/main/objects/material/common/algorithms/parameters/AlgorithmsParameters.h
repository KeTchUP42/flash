//
// Created by roman on 09.12.2020.
//

#ifndef PRIMARYWINDOW_H_ALGORITHMSPARAMETERS_H
#define PRIMARYWINDOW_H_ALGORITHMSPARAMETERS_H

namespace Material {

    /**
     * @brief Struct contains all algorithms numeric parameters.
     */
    struct AlgorithmsParameters {
        AlgorithmsParameters(float analysisStepX, float analysisStepY)
                : analysisStepX(analysisStepX), analysisStepY(analysisStepY) {}

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

#endif //PRIMARYWINDOW_H_ALGORITHMSPARAMETERS_H
