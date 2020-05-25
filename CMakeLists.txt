cmake_minimum_required(VERSION 3.12)

project(frenamer-r2plugin C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

set(RADARE2_INSTALL_PLUGDIR "share/radare2/plugins" CACHE PATH "Directory to install radare2 plugin into")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Radare2 REQUIRED)

set(SOURCES core_plugin.cpp nameGenerator.cpp)

add_library(core_frename SHARED ${SOURCES})

target_link_libraries(core_frename Radare2::libr)

target_include_directories(core_frename PUBLIC ${PROJECT_SOURCE_DIR}/include/)

set_target_properties(core_frename PROPERTIES
    OUTPUT_NAME core_frename
    PREFIX ""
)

install(TARGETS core_frename DESTINATION "${RADARE2_INSTALL_PLUGDIR}")