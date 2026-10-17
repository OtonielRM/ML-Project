cmake_minimum_required(VERSION 3.25)
project(linalg_kernels VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(LINALG_SANITIZE "Build everything with AddressSanitizer + UndefinedBehaviorSanitizer" OFF)

# Applied globally (before any target, including GoogleTest) so all code is instrumented consistently.
if(LINALG_SANITIZE)
  if(MSVC)
    message(FATAL_ERROR "LINALG_SANITIZE targets GCC/Clang (use WSL2 or Linux).")
  endif()
  set(SANITIZER_FLAGS -fsanitize=address,undefined -fno-sanitize-recover=all -fno-omit-frame-pointer)
  add_compile_options(${SANITIZER_FLAGS})
  add_link_options(${SANITIZER_FLAGS})
endif()

# ---- library ---------------------------------------------------------------
add_library(linalg src/version.cpp)
target_include_directories(linalg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(linalg PRIVATE
  LINALG_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
  LINALG_VERSION_MINOR=${PROJECT_VERSION_MINOR}
  LINALG_VERSION_PATCH=${PROJECT_VERSION_PATCH})

if(MSVC)
  target_compile_options(linalg PRIVATE /W4 /permissive-)
else()
  target_compile_options(linalg PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
endif()

# ---- tests -----------------------------------------------------------------
include(CTest)
if(BUILD_TESTING)
  include(FetchContent)
  FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  add_executable(linalg_tests tests/test_smoke.cpp)
  target_link_libraries(linalg_tests PRIVATE linalg GTest::gtest_main)

  include(GoogleTest)
  gtest_discover_tests(linalg_tests)
endif()
