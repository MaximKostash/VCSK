#include "../include/fun.h"

int BRANCH_F_ADD(const gchar *file_name) 
{
    if (g_file_test(file_name, G_FILE_TEST_EXISTS))
    {
        gchar *dir_main = g_strdup_printf("%s/%s", init_c.main, file_name);
        GFile *source = g_file_new_for_path(file_name);
        GFile *destination = g_file_new_for_path(dir_main);
        GError *error = NULL;
        if (g_file_copy(source, destination, G_FILE_COPY_OVERWRITE, NULL, NULL, NULL, &error)) 
        {
            printf("%s", comm.c2);
        } 
        else 
        {
            printf("Error: %s\n", error->message);
            g_error_free(error);
        }
        g_object_unref(source);
        g_object_unref(destination);
        g_free(dir_main);
        HISTORY_ADD(file_name);
    } 
    else 
    {
        printf("File does not exist: %s\n", file_name);
    }
    return 0;
}

int HISTORY_ADD(const gchar *file_name)
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    gchar *filename = g_strdup_printf("history_add-%d-%d-%d-%d-%d.txt", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    gchar *d = g_strdup_printf("%s/%s", init_c.history, filename);
    gchar *TIME = g_strdup_printf("%d-%d", timeinfo->tm_hour, timeinfo->tm_min);
    const gchar *content = g_strdup_printf("The file '%s' was added to the 'main' folder at '%s'.\n", file_name, TIME); 
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
