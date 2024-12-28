/********************************************
// Filename: base_engine.cpp
// Created by zjd1988 on 2024/12/27
// Description:

********************************************/
#include "engines/base_engine.h"

namespace LM_INFER_ENGINE {
    namespace ENGINE {

        static std::map<EngineType, const EngineCreator*>& getEngineCreatorMap()
        {
            static std::once_flag gInitFlag;
            static std::map<EngineType, const EngineCreator*>* gEngineCreatorMap;
            std::call_once(gInitFlag, [&]() {
                gEngineCreatorMap = new std::map<EngineType, const EngineCreator*>;
            });
            return *gEngineCreatorMap;
        }

        extern void registerEngineCreator();
        const EngineCreator* getEngineCreator(const EngineType type)
        {
            registerEngineCreator();
            auto& creator_map = getEngineCreatorMap();
            auto iter = creator_map.find(type);
            if (iter == creator_map.end())
            {
                return nullptr;
            }
            if (iter->second)
            {
                return iter->second;
            }
            return nullptr;
        }

        bool insertEngineCreator(const EngineType type, const EngineCreator* creator)
        {
            auto& creator_map = getEngineCreatorMap();
            if (gEngineTypeToStr.end() == gEngineTypeToStr.find(type))
            {
                LM_INFER_LOG(LM_INFER_LOG_LEVEL_ERROR, "invalid engine creator:{}", int(type));
                return false;
            }
            std::string type_str = gEngineTypeToStr[type];
            if (creator_map.find(type) != creator_map.end())
            {
                LM_INFER_LOG(LM_INFER_LOG_LEVEL_ERROR, "insert duplicate {} engine creator", type_str);
                return false;
            }
            creator_map.insert(std::make_pair(type, creator));
            return true;
        }

        void logRegisteredEngineCreator()
        {
            LM_INFER_LOG(LM_INFER_LOG_LEVEL_INFO, "registered engine creator as follows:");
            auto& creator_map = getEngineCreatorMap();
            for (const auto& it : creator_map)
            {
                std::string engine_type = gEngineTypeToString[it.first];
                LM_INFER_LOG(LM_INFER_LOG_LEVEL_INFO, "{}:{} engine creator", int(it.first), engine_type);
            }
            return;
        }

    } // namespace ENGINE
} // namespace LM_INFER_ENGINE