# modify from https://github.com/AimRT/AimRT/blob/main/cmake/GetNlohmannJson.cmake
include(FetchContent)
message(STATUS "Getting drogon ...")

set(drogon_DOWNLOAD_URL
    "https://github.com/drogonframework/drogon/archive/refs/tags/v1.9.8.tar.gz"
    CACHE STRING "")

if(drogon_LOCAL_SOURCE)
    FetchContent_Declare(
        drogon
        SOURCE_DIR ${drogon_LOCAL_SOURCE}
        OVERRIDE_FIND_PACKAGE)
else()
    FetchContent_Declare(
        drogon
        URL ${drogon_DOWNLOAD_URL}
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        OVERRIDE_FIND_PACKAGE)
endif()

# Wrap it in a function to restrict the scope of the variables
function(get_drogon)
    FetchContent_GetProperties(drogon)
    if(NOT drogon_POPULATED)
        set(BUILD_CTL OFF)
        set(BUILD_EXAMPLES OFF)
        set(USE_SPDLOG OFF)
        set(LIBPQ_BATCH_MODE OFF)
        set(BUILD_POSTGRESQL OFF)
        set(BUILD_MYSQL OFF)
        set(BUILD_SQLITE OFF)
        set(BUILD_REDIS OFF)
        if(BUILD_SHARED_LIBS)
            set(BUILD_SHARED_LIBS ON)
            set(BUILD_STATIC_LIBS OFF)
        else()
            set(BUILD_SHARED_LIBS OFF)
            set(BUILD_STATIC_LIBS ON)
        endif()
        FetchContent_MakeAvailable(drogon)
        if(TARGET libdrogon-static)
            add_library(libdrogon::libdrogon-static ALIAS libdrogon-static)
        endif()
        if(TARGET libdrogon)
            add_library(libdrogon::libdrogon ALIAS libdrogon)
        endif()
    endif()
endfunction()

get_drogon()