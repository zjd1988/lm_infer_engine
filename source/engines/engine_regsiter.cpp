/********************************************
 * Filename: engine_register.cpp
 * Created by zhaojiadi on 2024/12/27
 * Description:
 ********************************************/
#include <mutex>
#include "engines/base_engine.h"

namespace LM_INFER_ENGINE {
    namespace ENGINE {

        static std::once_flag s_flag;
        void registerEngineCreator()
        {
            std::call_once(s_flag, [&]() {
                logRegisteredEngineCreator();
            });
        }

    } // namespace ENGINE
} // namespace LM_INFER_ENGINE