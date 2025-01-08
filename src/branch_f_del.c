#include <stdio.h>
#include <glib.h>
#include "../include/fun.h"

int BRANCH_F_DEL(const gchar *file)
{
    gchar *d = g_strdup_printf("%s/%s", init_c.main, file);
    if (g_file_test(d, G_FILE_TEST_EXISTS))
    {
        if (remove(d) == 0)
        {
            comm.c2;
        }
        else
        {
            printf("Error.\n");
        }
    }
    return 0;
}
