cmake_minimum_required(VERSION 3.10)
project(vcsk)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(GIO REQUIRED gio-2.0)

include_directories(${GLIB_INCLUDE_DIRS} ${GIO_INCLUDE_DIRS})

add_executable(vcsk 
    main.c
    src/comm_data.c
    src/info.c
    src/help.c
    src/vcsk.c
    src/branch_f_del_ver.c
    src/branch_f_notes_clear.c
    src/branch_f_notes.c
    src/init_f_notes.c
    src/branch_f_del_dir.c
    src/branch_f_del.c
    src/branch_f_replace_dir.c
    src/branch_f_replace.c
    src/branch_f_add_dir.c
    src/branch_f_add.c
    src/init_data.c
    src/init_f.c
    src/branch_f.c
    src/init_f_init.c
    src/init_f_info.c
    src/init_f_info_file.c
    src/init_f_main.c
    src/init_f_ver_project.c
)

target_link_libraries(vcsk ${GLIB_LIBRARIES} ${GIO_LIBRARIES})
