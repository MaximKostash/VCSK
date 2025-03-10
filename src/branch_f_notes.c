#include "../include/fun.h"

int BRANCH_F_NOTES(const gchar *notes_file)
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    gchar *file_name = g_strdup_printf("Notes-%d-%d-%d-%d-%d.txt", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    gchar *d = g_strdup_printf("%s/%s", init_c.notes, file_name);
    GError *error = NULL;
    if (g_file_set_contents(d, notes_file, -1, &error))
    {
        printf("%s", comm.c2);
        HISTORY_NOTES();
    }
    else
    {
        printf("Error.\n");
        g_error_free(error);
    }
    return 0;
}

int HISTORY_NOTES()
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    gchar *filename = g_strdup_printf("history_notes-%d-%d-%d-%d-%d.txt", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    gchar *d = g_strdup_printf("%s/%s", init_c.history, filename);
    gchar *TIME = g_strdup_printf("%d-%d", timeinfo->tm_hour, timeinfo->tm_min);
    const gchar *content = g_strdup_printf("The note was made at '%s'.", TIME); 
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
