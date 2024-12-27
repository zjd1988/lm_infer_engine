# modify from https://github.com/AimRT/AimRT/blob/main/cmake/GetNlohmannJson.cmake
# Copyright (c) 2023, AgiBot Inc.
# All rights reserved.
include(FetchContent)
message(STATUS "get argparse ...")

set(argparse_DOWNLOAD_URL
    "https://github.com/p-ranav/argparse/archive/refs/tags/v3.1.tar.gz"
    CACHE STRING "")

if(argparse_LOCAL_SOURCE)
    FetchContent_Declare(
        argparse
        SOURCE_DIR ${argparse_LOCAL_SOURCE}
        OVERRIDE_FIND_PACKAGE)
else()
    FetchContent_Declare(
        argparse
        URL ${argparse_DOWNLOAD_URL}
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        OVERRIDE_FIND_PACKAGE)
endif()

# Wrap it in a function to restrict the scope of the variables
function(get_argparse)
    FetchContent_GetProperties(argparse)
    if(NOT argparse_POPULATED)
        FetchContent_MakeAvailable(argparse)
    endif()
endfunction()

get_argparse()
