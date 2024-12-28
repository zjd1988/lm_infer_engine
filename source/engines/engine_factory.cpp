/********************************************
// Filename: engine_factory.cpp
// Created by zjd1988 on 2024/12/27
// Description:

********************************************/
#include "engines/base_engine.h"
#include "engines/engine_factory.h"

namespace LM_INFER_LOG_ENGINE {
    namespace ENGINE {

        BaseEngine* EngineFactory::create(const BaseEngineConfig* config)
        {
            const EngineType type = config->type;
            auto creator = getEngineCreator(type);
            if (nullptr == creator)
            {
                logRegisteredEngineCreator();
                LM_INFER_LOG(LM_INFER_LOG_LEVEL_ERROR, "have no engine creator for type: {}", int(type));
                return nullptr;
            }
            auto engine = creator->onCreate(config);
            if (nullptr == engine)
            {
                LM_INFER_LOG(LM_INFER_LOG_LEVEL_ERROR, "create {} engine failed, creator return nullptr", 
                    gEngineTypeToString[type]);
            }
            return engine;
        }

    } // namespace ENGINE
} // namespace LM_INFER_LOG_ENGINE