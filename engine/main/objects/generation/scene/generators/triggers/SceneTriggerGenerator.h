//
// Created by roman on 30.09.2020.
//

#ifndef FLASH_SCENETRIGGERGENERATOR_H
#define FLASH_SCENETRIGGERGENERATOR_H

#include "../Generator.h"
#include "../../../../../view/windows/screen/context-abilities/StateChangeable.h"

namespace Generating {

    class SceneTriggerGenerator : public Generator {
    public:
        explicit SceneTriggerGenerator(SourcePool &pool, Screen::StateChangeable *context)
                : Generator(pool), m_context(context) {}

    protected:
        /**
         * @brief Do not call "delete" for this ptr.
         */
        Screen::StateChangeable *m_context;
    };
}

#endif //FLASH_SCENETRIGGERGENERATOR_H
