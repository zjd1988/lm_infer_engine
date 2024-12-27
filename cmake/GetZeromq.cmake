# modify from https://github.com/AimRT/AimRT/blob/main/cmake/GetNlohmannJson.cmake
include(FetchContent)
message(STATUS "Getting zeromq ...")

set(zeromq_DOWNLOAD_URL
    "https://github.com/zeromq/libzmq/archive/v4.3.5.tar.gz"
    CACHE STRING "")

if(zeromq_LOCAL_SOURCE)
    FetchContent_Declare(
        zeromq
        SOURCE_DIR ${zeromq_LOCAL_SOURCE}
        OVERRIDE_FIND_PACKAGE)
else()
    FetchContent_Declare(
        zeromq
        URL ${zeromq_DOWNLOAD_URL}
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        OVERRIDE_FIND_PACKAGE)
endif()

# Wrap it in a function to restrict the scope of the variables
function(get_zeromq)
    FetchContent_GetProperties(zeromq)
    if(NOT zeromq_POPULATED)
        set(ZMQ_BUILD_TESTS OFF CACHE INTERNAL "")
        FetchContent_MakeAvailable(zeromq)
        if(TARGET libzmq-static)
            add_library(libzmq::libzmq-static ALIAS libzmq-static)
        endif()
        if(TARGET libzmq)
            add_library(libzmq::libzmq ALIAS libzmq)
        endif()
    endif()
endfunction()

get_zeromq()