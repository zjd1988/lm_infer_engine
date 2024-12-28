/********************************************
// Filename: engine_common.cpp
// Created by zjd1988 on 2024/12/27
// Description:

********************************************/
#include "engines/engine_common.h"

namespace LM_INFER_ENGINE {
    namespace ENGINE {

        // string to engine type map
        std::map<std::string, EngineType> gStringToEngineType = {
            {"LLAMA_CPP",                    LLAMA_CPP_ENGINE_TYPE},
        };

        // engine type to string map
        std::map<EngineType, std::string> gEngineTypeToString = {
            {LLAMA_CPP_ENGINE_TYPE,          "LLAMA_CPP"},
        };

    } // namespace ENGINE
} // namespace LM_INFER_ENGINE