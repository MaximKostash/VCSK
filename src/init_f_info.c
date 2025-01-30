#include "../include/fun.h"

int INIT_F_INFO()
{
    if (g_mkdir_with_parents(init_c.info, 0775) == 0)
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
