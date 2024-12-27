/********************************************
// Filename: engine_factory.cpp
// Created by zjd1988 on 2024/12/27
// Description:

********************************************/
#include "engines/base_engine.h"
#include "engines/engine_factory.h"

namespace LM_INFER_ENGINE {
    namespace ENGINE {

        BaseEngine* EngineFactory::create(const EngineBaseConfig* config)
        {
            const EngineType type = config->type;
            auto creator = getEngineCreator(type);
            if (nullptr == creator)
            {
                PIPELINE_LOG(PIPELINE_LOG_LEVEL_ERROR, "get node creator failed, no creator for type: {}", 
                    int(type));
                return nullptr;
            }
            auto node = creator->onCreate(config);
            if (nullptr == node)
            {
                PIPELINE_LOG(PIPELINE_LOG_LEVEL_ERROR, "create {} node failed, creator return nullptr", 
                    gEngineTypeToStr[type]);
            }
            return node;
        }

    } // namespace ENGINE
} // namespace LM_INFER_ENGINE