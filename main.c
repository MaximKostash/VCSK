#include "include/fun.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return VCSK();
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
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "add") == 0 && argc == 3)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
        {
            BRANCH_F_ADD(argv[2]);
        }
        else
        {
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "add-dir") == 0 && argc == 4)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
        {
            BRANCH_F_ADD_DIR(argv[2], argv[3]);
        }
        else
        {
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "replace") == 0 && argc == 3)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
        {
            BRANCH_F_REPLACE(argv[2]);
        }
        else
        {
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "replace-dir") == 0 && argc == 4)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
        {
            BRANCH_F_REPLACE_DIR(argv[2], argv[3]);
        }
        else
        {
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "del") == 0 && argc == 3)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
        {
            BRANCH_F_DEL(argv[2]);
        }
        else
        {
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "del-dir") == 0 && argc == 4)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
        {
            BRANCH_F_DEL_DIR(argv[2], argv[3]);
        }
        else
        {
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "notes") == 0 && argc == 3)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
        {
            for (int i = 0; i < argc; i++) 
            {
                BRANCH_F_NOTES(argv[2]);
            }
        }
        else
        {
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "notes-clear") == 0)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
        {
            BRANCH_F_NOTES_CLEAR();
        }
        else
        {
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "del-ver") == 0 && argc == 3)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
        {
            BRANCH_F_DEL_VER(argv[2]);
        }
        else
        {
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "history-clear") == 0)
    {
        if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
        {
            HISTORY_CLEAR();
        }
        else
        {
            printf("%s", comm.c1);
        }
    }
    else if (strcmp(argv[1], "help") == 0)
    {
        HELP();
    }
    else if (strcmp(argv[1], "info") == 0)
    {
        INFO();
    }
    else
    {
        printf("Command not recognized.\nList of available commands - vcsk help\n");
    }
    return 0;
}
