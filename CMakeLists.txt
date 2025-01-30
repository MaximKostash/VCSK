cmake_minimum_required(VERSION 3.10)
project(vcsk)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -pipe")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(GIO REQUIRED gio-2.0)

include_directories(${GLIB_INCLUDE_DIRS} ${GIO_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.c")

add_executable(vcsk 
    main.c
    ${SOURCES}
)

target_link_libraries(vcsk ${GLIB_LIBRARIES} ${GIO_LIBRARIES})
