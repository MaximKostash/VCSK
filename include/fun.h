#ifndef FUN_H
#define FUN_H

#include <glib.h>

typedef struct {
    const gchar *init;
    const gchar *info;
    const gchar *info_file;
    const gchar *content_info_file;
    const gchar *main;
    const gchar *ver_project;
} INIT;

extern INIT init_c;

void INIT_F();
int INIT_F_INIT();
int INIT_F_INFO();
int INIT_F_INFO_FILE();
int INIT_F_MAIN();
int INIT_F_VER_PROJECT();
int BRANCH_F(const gchar *branch_name);
int BRANCH_F_ADD(const gchar *file_name);

#endif
