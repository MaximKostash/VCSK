#include <stdio.h>
#include <glib.h>
#include <gio/gio.h>
#include <unistd.h>
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
        g_print("The file does not exist: %s\n", d);
    }
    g_free(d);
    return 0;
}
