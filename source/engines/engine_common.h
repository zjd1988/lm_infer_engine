/********************************************
// Filename: engine_common.h
// Created by zjd1988 on 2024/12/27
// Description:

********************************************/
#pragma once
#include <map>
#include <string>
#include "common/non_copyable.h"

namespace LM_INFER_ENGINE {
    namespace ENGINE {

        // engine type enum
        typedef enum EngineType
        {
            INVALID_ENGINE_TYPE                = -1,
            LLAMA_CPP_ENGINE_TYPE              = 0,
            MAX_ENGINE_TYPE,
        } EngineType;

        // string -> engine type / engine type -> string
        extern std::map<std::string, EngineType> gStringToEngineType;
        extern std::map<EngineType, std::string> gEngineTypeToString;

        // base engine config
        typedef struct BaseEngineConfig
        {
            EngineType                         engine_type;
        } BaseEngineConfig;

        // llama.cpp engine config
        class LlamaCppEngineConfig : public BaseEngineConfig
        {

        };

    } // namespace ENGINE
} // namespace LM_INFER_ENGINE