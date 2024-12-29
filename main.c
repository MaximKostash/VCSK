#include <stdio.h>
#include <string.h>
#include <glib.h>
#include "include/fun.h"                                                                                     

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("vcsk <command>\n");                        
    }                                                      
    if (strcmp(argv[1], "init") == 0)
    {
        INIT_F();                                          
    }
    else if (strcmp(argv[1], "branch") == 0 && argc == 3)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))                                                             
        {
            BRANCH_F(argv[2]);
        }
        else
        {
            printf("init\n");
        }
    }
    return 0;
}
