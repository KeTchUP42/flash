//
// Created by roman on 30.09.2020.
//

#ifndef FLASH_SCENETRIGGERGENERATOR_H
#define FLASH_SCENETRIGGERGENERATOR_H

#include "../Generator.h"
#include "../../../../../view/windows/screen/context-abilities/StateChangeable.h"

namespace Generate {

    class SceneTriggerGenerator : public Generator {
    public:
        explicit SceneTriggerGenerator(Pools::SourcePool &pool, View::StateChangeable *context)
                : Generator(pool), m_context(context) {}

    protected:
        /**
         * @brief Do not call "delete" for this ptr.
         */
        View::StateChangeable *m_context;
    };
}

#endif //FLASH_SCENETRIGGERGENERATOR_H
