#include <stdio.h>
#include <glib.h>
#include "../include/fun.h"

int BRANCH_F_DEL_DIR(const gchar *dir, const gchar *file)
{
    gchar *d = g_strdup_printf("%s/%s/%s", init_c.ver_project, dir, file);
    if (g_file_test(d, G_FILE_TEST_EXISTS))
    {
        if (remove(d) == 0)
        {
            printf("Performing the operation...\n");
        }
        else
        {
            printf("Error.\n");
        }
    }
    return 0;
}
