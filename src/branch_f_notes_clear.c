#include "../include/fun.h"

int BRANCH_F_NOTES_CLEAR() 
{
    const gchar *dir_path = init_c.notes;
    GDir *dir = g_dir_open(dir_path, 0, NULL);  
    if (!dir) 
    {
        g_printerr("Could not open directory: %s\n", dir_path);
        return -1;
    }
    const gchar *filename;
    while ((filename = g_dir_read_name(dir)) != NULL) 
    {
        if (g_strcmp0(filename, ".") != 0 && g_strcmp0(filename, "..") != 0) 
        {
            gchar *full_path = g_build_filename(dir_path, filename, NULL);
            GStatBuf statbuf;
            if (g_stat(full_path, &statbuf) == 0) 
            {
                if (S_ISDIR(statbuf.st_mode)) 
                {
                    g_rmdir(full_path);
                } 
                else 
                {
                    g_unlink(full_path);
                }
            }
            g_free(full_path);
        }
    }  
    g_dir_close(dir);
    HISTORY_NOTES_CLEAR();
    return 0;
}

int HISTORY_NOTES_CLEAR()
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    gchar *filename = g_strdup_printf("history_notes-clear-%d-%d-%d-%d-%d.txt", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    gchar *d = g_strdup_printf("%s/%s", init_c.history, filename);
    gchar *TIME = g_strdup_printf("%d-%d", timeinfo->tm_hour, timeinfo->tm_min);
    const gchar *content = g_strdup_printf("The notes were cleared at '%s'.", TIME); 
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
