/********************************************
// Filename: base_engine.h
// Created by zjd1988 on 2024/12/27
// Description:

********************************************/
#pragma once
#include "common/non_copyable.h"
using namespace LM_INFER_ENGINE::COMMON;

namespace LM_INFER_ENGINE {
    namespace ENGINE {

        /** protocol class. used to delete assignment operator. */
        class BaseEngine : public NonCopyable
        {
        public:
            BaseEngine() = default;
        };

        /** abstract engine register */
        class EngineCreator
        {
        public:
            virtual ~EngineCreator() = default;
            virtual BaseEngine* onCreate(const EngineBaseConfig* config) const = 0;

        protected:
            EngineCreator() = default;
        };

        const EngineCreator* getEngineCreator(const EngineType type);
        bool insertEngineCreator(const EngineType type, const EngineCreator* creator);
        void printRegisteredEngineCreator();

    } // namespace ENGINE
} // namespace LM_INFER_ENGINE