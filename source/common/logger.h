/********************************************
// Filename: logger.h
// Created by zjd1988 on 2024/12/27
// Description:

********************************************/
#pragma once
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <iostream>
#include <memory>
#include "spdlog/spdlog.h"
#include "common/non_copyable.h"

#define LM_INFER_LOG_LEVEL_TRACE    SPDLOG_LEVEL_TRACE
#define LM_INFER_LOG_LEVEL_DEBUG    SPDLOG_LEVEL_DEBUG
#define LM_INFER_LOG_LEVEL_INFO     SPDLOG_LEVEL_INFO
#define LM_INFER_LOG_LEVEL_WARN     SPDLOG_LEVEL_WARN
#define LM_INFER_LOG_LEVEL_ERROR    SPDLOG_LEVEL_ERROR
#define LM_INFER_LOG_LEVEL_FATAL    SPDLOG_LEVEL_CRITICAL
#define LM_INFER_LOG_LEVEL_OFF      SPDLOG_LEVEL_OFF

#define LM_INFER_LOG_TRACE(...)       SPDLOG_TRACE(__VA_ARGS__)
#define LM_INFER_LOG_DEBUG(...)       SPDLOG_DEBUG(__VA_ARGS__)
#define LM_INFER_LOG_INFO(...)        SPDLOG_INFO(__VA_ARGS__)
#define LM_INFER_LOG_WARN(...)        SPDLOG_WARN(__VA_ARGS__)
#define LM_INFER_LOG_ERROR(...)       SPDLOG_ERROR(__VA_ARGS__)
#define LM_INFER_LOG_CRITICAL(...)    SPDLOG_CRITICAL(__VA_ARGS__)

#define LM_INFER_LOG_IMPL(level, ...)                                                         \
do {                                                                                          \
    spdlog::logger* logger = LM_INFER_ENGINE::COMMON::Instance().getLogger();                 \
    if (nullptr == logger)                                                                    \
        logger = spdlog::default_logger_raw();                                                \
    switch(level)                                                                             \
    {                                                                                         \
        case LM_INFER_LOG_LEVEL_TRACE:                                                        \
            SPDLOG_LOGGER_TRACE(logger, __VA_ARGS__);                                         \
            break;                                                                            \
        case LM_INFER_LOG_LEVEL_DEBUG:                                                        \
            SPDLOG_LOGGER_DEBUG(logger, __VA_ARGS__);                                         \
            break;                                                                            \
        case LM_INFER_LOG_LEVEL_INFO:                                                         \
            SPDLOG_LOGGER_INFO(logger, __VA_ARGS__);                                          \
            break;                                                                            \
        case LM_INFER_LOG_LEVEL_WARN:                                                         \
            SPDLOG_LOGGER_WARN(logger, __VA_ARGS__);                                          \
            break;                                                                            \
        case LM_INFER_LOG_LEVEL_ERROR:                                                        \
            SPDLOG_LOGGER_ERROR(logger, __VA_ARGS__);                                         \
            break;                                                                            \
        case LM_INFER_LOG_LEVEL_FATAL:                                                        \
            SPDLOG_LOGGER_CRITICAL(logger, __VA_ARGS__);                                      \
            assert(0);                                                                        \
            break;                                                                            \
        case LM_INFER_LOG_LEVEL_OFF:                                                          \
            break;                                                                            \
        default:                                                                              \
            SPDLOG_LOGGER_CRITICAL(logger, __VA_ARGS__);                                      \
    }                                                                                         \
} while(0)


#define LM_INFER_LOG(level, ...)  LM_INFER_LOG_IMPL(level, ##__VA_ARGS__)

#define CHECK(express, err_str)                                                               \
do {                                                                                          \
    if (!(express))                                                                           \
    {                                                                                         \
        LM_INFER_LOG(LM_INFER_LOG_LEVEL_FATAL, "check {} fail, {}",                           \
            #express, err_str);                                                               \
    }                                                                                         \
} while(0)

#define CHECK_EQ(expa, expb, err_str)                                                         \
do {                                                                                          \
    if ((expa) != (expb))                                                                     \
    {                                                                                         \
        LM_INFER_LOG(LM_INFER_LOG_LEVEL_FATAL, "check {} == {} fail, {}",                     \
            #expa, #expb, err_str);                                                           \
    }                                                                                         \
} while(0)

#define CHECK_GT(expa, expb, err_str)                                                         \
do {                                                                                          \
    if ((expa) <= (expb))                                                                     \
    {                                                                                         \
        LM_INFER_LOG(LM_INFER_LOG_LEVEL_FATAL, "check {} >= {} fail, {}",                     \
            #expa, #expb, err_str);                                                           \
    }                                                                                         \
} while(0)

namespace LM_INFER_ENGINE {
    namespace COMMON {

        class LmInferLogger : public NonCopyable
        {
        public:
            static LmInferLogger& Instance();
            void initLogger(std::string file_name, int log_level = spdlog::level::info);
            void stopLogger();
            void setLevel(int level = spdlog::level::info);
            spdlog::logger* getLogger()
            {
                return m_logger.get();
            }

        private:
            LmInferLogger();
            ~LmInferLogger();

        private:
            std::shared_ptr<spdlog::logger>            m_logger;
            std::string                                m_logger_name;
            int                                        m_logger_level;
            std::string                                m_logger_file_name;
            int                                        m_logger_file_size;
            int                                        m_logger_file_num;
        };

    } // namespace COMMON
} // namespace LM_INFER_ENGINE