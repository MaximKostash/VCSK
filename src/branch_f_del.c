#include "../include/fun.h"

int BRANCH_F_DEL(const gchar *file)
{
    gchar *d = g_strdup_printf("%s/%s", init_c.main, file);
    if (g_file_test(d, G_FILE_TEST_EXISTS))
    {
        if (remove(d) == 0)
        {
            printf("%s", comm.c2);
            HISTORY_DEL(file);
        }
        else
        {
            printf("Error.\n");
        }
    }
    return 0;
}

int HISTORY_DEL(const gchar *file)
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    gchar *filename = g_strdup_printf("history_del-%d-%d-%d-%d-%d.txt", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    gchar *d = g_strdup_printf("%s/%s", init_c.history, filename);
    gchar *TIME = g_strdup_printf("%d-%d", timeinfo->tm_hour, timeinfo->tm_min);
    const gchar *content = g_strdup_printf("The file '%s' was deleted from the 'main' folder at '%s'.", file, TIME); 
    GError *error = NULL;
    if (g_file_set_contents(d, content, -1, &error))
    {
        printf("%s", comm.c2);
    }
    else
    {
        printf("Error.\n");
        g_error_free(error);
    }
    return 0;
}
