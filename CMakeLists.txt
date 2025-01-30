cmake_minimum_required(VERSION 3.10)
project(vcsk)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -pipe")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(GIO REQUIRED gio-2.0)

include_directories(${GLIB_INCLUDE_DIRS} ${GIO_INCLUDE_DIRS})

add_executable(vcsk 
    main.c
    src/*.c
)

target_link_libraries(vcsk ${GLIB_LIBRARIES} ${GIO_LIBRARIES})
