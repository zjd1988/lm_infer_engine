# modify from https://github.com/AimRT/AimRT/blob/main/cmake/GetNlohmannJson.cmake
# Copyright (c) 2023, AgiBot Inc.
# All rights reserved.
include(FetchContent)
message(STATUS "get spdlog ...")

set(spdlog_DOWNLOAD_URL
    "https://github.com/gabime/spdlog/archive/v1.9.2.tar.gz"
    CACHE STRING "")

if(spdlog_LOCAL_SOURCE)
    FetchContent_Declare(
        spdlog
        SOURCE_DIR ${spdlog_LOCAL_SOURCE}
        OVERRIDE_FIND_PACKAGE)
else()
    FetchContent_Declare(
        spdlog
        URL ${spdlog_DOWNLOAD_URL}
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        OVERRIDE_FIND_PACKAGE)
endif()

# Wrap it in a function to restrict the scope of the variables
function(get_spdlog)
    FetchContent_GetProperties(spdlog)
    if(NOT spdlog_POPULATED)
        FetchContent_MakeAvailable(spdlog)
    endif()
endfunction()

get_spdlog()
