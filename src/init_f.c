#include "../include/fun.h"

void INIT_F()
{
    if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
    {
        printf("%s", comm.c1);
    }
    else
    {
        INIT_F_INIT();
        INIT_F_INFO();
        INIT_F_INFO_FILE();
        INIT_F_MAIN();
        INIT_F_VER_PROJECT();
        INIT_F_NOTES();
        INIT_F_HISTORY();
    }
}
