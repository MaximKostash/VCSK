#include <stdio.h>
#include <glib.h>
#include <glib/gstdio.h>
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
    return 0;
}
