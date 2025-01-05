#include <stdio.h>
#include <glib.h>
#include "../include/fun.h"

int INIT_F_NOTES()
{
    if (g_mkdir_with_parents(init_c.notes, 0775) == 0)
    {
        printf("Performing the operation...\n");
    }
    else
    {
        perror("Error.\n");
        return 1;
    }
    return 0;
}
