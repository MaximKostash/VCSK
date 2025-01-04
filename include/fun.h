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
    const gchar *notes;
} INIT;

extern INIT init_c;

void INIT_F();
int INIT_F_INIT();
int INIT_F_INFO();
int INIT_F_INFO_FILE();
int INIT_F_MAIN();
int INIT_F_VER_PROJECT();
int INIT_F_NOTES();
int BRANCH_F(const gchar *branch_name);
int BRANCH_F_ADD(const gchar *file_name);
int BRANCH_F_ADD_DIR(const gchar *dir, const gchar *file);
int BRANCH_F_REPLACE(const gchar *file);
int BRANCH_F_REPLACE_DIR(const gchar *dir, const gchar *file);
int BRANCH_F_DEL(const gchar *file);
int BRANCH_F_DEL_DIR(const gchar *dir, const gchar *file);
int BRANCH_F_NOTES(const gchar *notes_file);
int BRANCH_F_NOTES_CLEAR();
int BRANCH_F_DEL_VER(const gchar *dir);

#endif
