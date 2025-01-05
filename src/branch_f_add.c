#include <stdio.h>
#include <glib.h>
#include <gio/gio.h>
#include "../include/fun.h"

int BRANCH_F_ADD(const gchar *file_name) {
    if (g_file_test(file_name, G_FILE_TEST_EXISTS))
    {
        gchar *dir_main = g_strdup_printf("%s/%s", init_c.main, file_name);
        GFile *source = g_file_new_for_path(file_name);
        GFile *destination = g_file_new_for_path(dir_main);
        GError *error = NULL;
        if (g_file_copy(source, destination, G_FILE_COPY_OVERWRITE, NULL, NULL, NULL, &error)) 
        {
            printf("Performing the operation...\n");
        } 
        else 
        {
            printf("Error: %s\n", error->message);
            g_error_free(error);
        }
        g_object_unref(source);
        g_object_unref(destination);
        g_free(dir_main);
    } 
    else 
    {
        printf("File does not exist: %s\n", file_name);
    }

    return 0;
}
