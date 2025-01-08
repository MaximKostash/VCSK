#include <stdio.h>
#include <glib.h>
#include "../include/fun.h"

int BRANCH_F(const gchar *branch_name)
{
    gchar *branch_path = g_strdup_printf("%s/%s", init_c.ver_project, branch_name);
    if (g_mkdir_with_parents(branch_path, 0775) == 0)
    {
        printf("%s", comm.c2);
    }
    else
    {
        perror("Error.\n");
        g_free(branch_path);
        return 1;
    }
    g_free(branch_path);
    return 0;
}
