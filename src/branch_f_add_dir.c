#include <stdio.h>
#include <glib.h>
#include <gio/gio.h>
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
