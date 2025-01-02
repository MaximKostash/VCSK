#include <stdio.h>
#include <glib.h>
#include <gio/gio.h>
#include <unistd.h>
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
            printf("false\n");
        }
        
        g_free(source_path);
    }
    else
    {
        printf("false.\n");
    }
    return 0;
}
