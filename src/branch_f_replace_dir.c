#include "../include/fun.h"

int BRANCH_F_REPLACE_DIR(const gchar *dir, const gchar *file) 
{
    gchar *d = g_strdup_printf("%s/%s/%s", init_c.ver_project, dir, file);
    gchar *D = g_strdup_printf("%s/%s", init_c.ver_project, dir);
    if (g_file_test(d, G_FILE_TEST_EXISTS)) 
    {
        if (g_file_test(D, G_FILE_TEST_IS_DIR)) 
        {
            GError *error = NULL;
            if (unlink(file) != 0) 
            {
                g_print("Error deleting destination file: %s\n", g_strerror(errno));
                g_free(d);
                return 1;
            }
            if (!g_file_copy(g_file_new_for_path(d), g_file_new_for_path(file), G_FILE_COPY_OVERWRITE, NULL, NULL, NULL, &error)) 
            {
                g_print("Error copying file: %s\n", error->message);
                g_error_free(error);
                g_free(d);
                return 1;
            }
        } 
        else 
        {
            g_print("The specified directory does not exist: %s\n", dir);
        }
    } 
    else 
    {
        g_print("There is no file: %s\n", d);
    }
    g_free(d);
    HISTORY_REPLACE_DIR(dir, file);
    return 0;
}

int HISTORY_REPLACE_DIR(const gchar *dir, const gchar *file)
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    gchar *filename = g_strdup_printf("history_replace-dir-%d-%d-%d-%d-%d.txt", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    gchar *d = g_strdup_printf("%s/%s", init_c.history, filename);
    gchar *TIME = g_strdup_printf("%d-%d", timeinfo->tm_hour, timeinfo->tm_min);
    const gchar *content = g_strdup_printf("The '%s' file was replaced from the '%s' folder at '%s'.", file, dir, TIME); 
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
