#include <stdio.h>
#include <glib.h>
#include "../include/fun.h"

int INIT_F_INFO_FILE()
{
    GError *error = NULL;
    if (g_file_set_contents(init_c.info_file, init_c.content_info_file, -1, &error))
    {
        comm.c2;
    }
    else
    {
        printf("Error.\n");
        g_error_free(error);
    }
    return 0;
}
