#include <stdio.h>
#include <string.h>
#include <glib.h>

typedef struct {
    const gchar *init;
} COMM;

int main(int argc, char *argv[])
{
    COMM comm = {
        ".VCSK"
    };
    if (argc < 2)
    {
        printf("vcsk <command>\n");
    }
    if (strcmp(argv[1], "init") == 0)
    {
        if (g_mkdir_with_parents(comm.init, 0775) == 0)
        {
            printf("init...\n");
        }
        else
        {
            perror("Error.\n");
            return 1;
        }
    }
    return 0;
}
