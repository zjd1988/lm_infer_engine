/********************************************
// Filename: engine_factory.h
// Created by zjd1988 on 2024/12/27
// Description:

********************************************/
#pragma once

namespace LM_INFER_ENGINE {
    namespace ENGINE {

        /** engine factory */
        class EngineFactory
        {
        public:
            static BaseEngine* create(const BaseEngineConfig* config);
        };

    } // namespace ENGINE
} // namespace LM_INFER_ENGINE