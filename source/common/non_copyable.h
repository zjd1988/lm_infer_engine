/********************************************
// Filename: non_copyable.h
// Created by zjd1988 on 2024/12/27
// Description:

********************************************/
#pragma once

namespace LM_INFER_ENGINE {
    namespace COMMON {

        /** protocol class. used to delete assignment operator. */
        class NonCopyable
        {
        public:
            NonCopyable() = default;
            NonCopyable(const NonCopyable&) = delete;
            NonCopyable(const NonCopyable&&) = delete;
            NonCopyable& operator=(const NonCopyable&) = delete;
            NonCopyable& operator=(const NonCopyable&&) = delete;
        };

    } // namespace COMMON
} // namespace LM_INFER_ENGINE