# modify from https://github.com/AimRT/AimRT/blob/main/CMakeLists.txt
cmake_minimum_required(VERSION 3.24)
project(lm_infer_engine LANGUAGES C CXX)

# Prevent variables from being reset by option
# This setting allows predefined variables to take precedence for FetchContent_MakeAvailable()
# See: https://cmake.org/cmake/help/latest/policy/CMP0077.html
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

# Set cmake path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Some necessary settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set default build type as Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Update c cxx flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  add_compile_options(/utf-8 /wd4819)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")
endif()

if(WIN32)
  add_compile_definitions(NOMINMAX)
endif()

# Include common dependcies
include(GetArgparse)
include(GetJsonCpp)
include(GetNlohmannJson)
include(GetYamlCpp)
include(GetMsgpack)
include(GetSpdlog)
include(GetZeromq)
include(GetDrogon)

