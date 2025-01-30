#include "../include/fun.h"

int BRANCH_F_ADD_DIR(const gchar *dir, const gchar *file)
{
    GFile *source = g_file_new_for_path(file);
    GFile *destination = g_file_new_for_path(g_strdup_printf("%s/%s/%s", init_c.ver_project, dir, file));
    GError *error = NULL;

    if (g_file_test(g_strdup_printf("%s/%s", init_c.ver_project, dir), G_FILE_TEST_IS_DIR))
    {
        if (g_file_test(g_file_get_path(source), G_FILE_TEST_EXISTS))
        {
            if (g_file_copy(source, destination, G_FILE_COPY_OVERWRITE, NULL, NULL, NULL, &error))
            {
                printf("%s", comm.c2);
                HISTORY_ADD_DIR(dir, file);
            }
            else
            {
                printf("Error: %s\n", error->message);
                g_error_free(error);
            }
        }
        else
        {
            printf("Error: File does not exist.\n");
        }
    }
    g_object_unref(source);
    g_object_unref(destination);
    return 0;
}

int HISTORY_ADD_DIR(const gchar *dir, const gchar *file)
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    gchar *filename = g_strdup_printf("history_add-dir-%d-%d-%d-%d-%d.txt", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    gchar *d = g_strdup_printf("%s/%s", init_c.history, filename);
    gchar *TIME = g_strdup_printf("%d-%d", timeinfo->tm_hour, timeinfo->tm_min);
    const gchar *content = g_strdup_printf("The file '%s' was added to the '%s' folder at '%s'.\n", file, dir, TIME); 
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
