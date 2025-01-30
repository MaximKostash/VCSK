#include "../include/fun.h"

int BRANCH_F_REPLACE(const gchar *file)
{
    if (g_file_test(file, G_FILE_TEST_EXISTS))
    {
        gchar *source_path = g_strdup_printf("%s/%s", init_c.main, file);
        if (g_file_test(source_path, G_FILE_TEST_EXISTS))
        {
            GError *error = NULL;
            if (unlink(file) != 0)
            {
                g_print("Error deleting destination file: %s\n", g_strerror(errno));
                g_free(source_path);
                return 1;
            }
            if (!g_file_copy(g_file_new_for_path(source_path), g_file_new_for_path(file), G_FILE_COPY_OVERWRITE, NULL, NULL, NULL, &error))
            {
                g_print("Error copying file: %s\n", error->message);
                g_error_free(error);
                g_free(source_path);
                return 1;
            }
        }
        else
        {
            printf("There is no file.\n");
        }
        g_free(source_path);
    }
    else
    {
        printf("There is no file.\n");
    }
    HISTORY_REPLACE(file);
    return 0;
}

int HISTORY_REPLACE(const gchar *file)
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    gchar *filename = g_strdup_printf("history_replace-%d-%d-%d-%d-%d.txt", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    gchar *d = g_strdup_printf("%s/%s", init_c.history, filename);
    gchar *TIME = g_strdup_printf("%d-%d", timeinfo->tm_hour, timeinfo->tm_min);
    const gchar *content = g_strdup_printf("The '%s' file was replaced from the 'main' folder at '%s'.", file, TIME); 
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
