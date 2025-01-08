#include <stdio.h>
#include <glib.h>
#include "../include/fun.h"

int INIT_F_INIT()
{
    if (g_mkdir_with_parents(init_c.init, 0775) == 0)
    {
        printf("%s", comm.c2);
    }
    else
    {
        perror("Error.\n");
        return 1;
    }
    return 0;
}
