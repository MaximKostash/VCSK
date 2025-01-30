#include "../include/fun.h"

void delete_directory(const gchar *dir) 
{
    GDir *d;
    const gchar *filename;
    d = g_dir_open(dir, 0, NULL);
    if (d == NULL) 
    {
        perror("g_dir_open failed");
        return;
    }
    while ((filename = g_dir_read_name(d)) != NULL)
    {
        if (g_strcmp0(filename, ".") != 0 && g_strcmp0(filename, "..") != 0) 
        {
            gchar *full_path = g_strdup_printf("%s/%s", dir, filename);
            GFile *file = g_file_new_for_path(full_path);
            GFileInfo *info = g_file_query_info(file, "*", G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS, NULL, NULL);
            if (info) 
            {
                GFileType type = g_file_info_get_file_type(info);
                if (type == G_FILE_TYPE_DIRECTORY) 
                {
                    delete_directory(full_path);
                } 
                else 
                {
                    GError *error = NULL;
                    if (!g_file_delete(file, NULL, &error)) 
                    {
                        g_print("Failed to delete file %s: %s\n", full_path, error->message);
                        g_error_free(error);
                    }
                }
                g_object_unref(info);
            }
            g_object_unref(file);
            g_free(full_path);
        }
    }
    g_dir_close(d);
    GError *error = NULL;
    GFile *dir_file = g_file_new_for_path(dir);
    if (!g_file_delete(dir_file, NULL, &error)) 
    {
        g_print("Failed to delete directory %s: %s\n", dir, error->message);
        g_error_free(error);
    }
    g_object_unref(dir_file);
}

int BRANCH_F_DEL_VER(const gchar *dir) 
{
    gchar *d = g_strdup_printf("%s/%s", init_c.ver_project, dir);
    if (g_file_test(d, G_FILE_TEST_IS_DIR)) 
    {
        delete_directory(d);
        printf("Directory deleted: %s\n", d);
    } 
    else 
    {
        printf("The directory does not exist.\n");
    }
    g_free(d);
    HISTORY_DEL_VER(dir);
    return 0;
}

int HISTORY_DEL_VER(const gchar *dir)
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    gchar *filename = g_strdup_printf("history_add-%d-%d-%d-%d-%d.txt", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    gchar *d = g_strdup_printf("%s/%s", init_c.history, filename);
    gchar *TIME = g_strdup_printf("%d-%d", timeinfo->tm_hour, timeinfo->tm_min);
    const gchar *content = g_strdup_printf("The '%s' folder was deleted at '%s'.", dir, TIME); 
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
