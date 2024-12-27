# modify from https://github.com/AimRT/AimRT/blob/main/cmake/GetNlohmannJson.cmake
# Copyright (c) 2023, AgiBot Inc.
# All rights reserved.
include(FetchContent)
message(STATUS "get msgpack ...")

set(msgpack_DOWNLOAD_URL
    "https://github.com/msgpack/msgpack-c.git/archive/cpp-7.0.0.tar.gz"
    CACHE STRING "")

if(msgpack_LOCAL_SOURCE)
    FetchContent_Declare(
        msgpack
        SOURCE_DIR ${msgpack_LOCAL_SOURCE}
        OVERRIDE_FIND_PACKAGE)
else()
    FetchContent_Declare(
        msgpack
        URL ${msgpack_DOWNLOAD_URL}
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        OVERRIDE_FIND_PACKAGE)
endif()

# Wrap it in a function to restrict the scope of the variables
function(get_msgpack)
    FetchContent_GetProperties(msgpack)
    if(NOT msgpack_POPULATED)
        set(MSGPACK_BUILD_EXAMPLES OFF)
        set(MSGPACK_BUILD_TESTS OFF)
        set(MSGPACK_BUILD_DOCS OFF)
        set(MSGPACK_USE_BOOST OFF)
        set(MSGPACK_CXX20 ON)
        set(MSGPACK_NO_BOOST ON)
        FetchContent_MakeAvailable(msgpack)
    endif()
endfunction()

get_msgpack()
