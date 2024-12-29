#include <stdio.h>
#include <glib.h>
#include "../include/fun.h"

int INIT_F_INFO()
{
    if (g_mkdir_with_parents(init_c.info, 0775) == 0)
    {
        printf("info...\n");
    }
    else
    {
        perror("Error.\n");
        return 1;
    }
    return 0;
}
