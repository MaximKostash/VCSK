#include <stdio.h>
#include <string.h>
#include <glib.h>

void INIT_F();
int INIT_F_INIT();
int INIT_F_INFO();
int INIT_F_INFO_FILE();
int INIT_F_MAIN();
int INIT_F_VER_PROJECT();

int BRANCH_F();

typedef struct {
    const gchar *init;
    const gchar *info;
    const gchar *info_file;
    const gchar *content_info_file;
    const gchar *main;
    const gchar *ver_project;
} INIT;

typedef struct {
    const gchar *branch;
} BRANCH;

INIT init_c = {
    ".VCSK",
    ".VCSK/info",
    ".VCSK/info/info.txt",
    "Hello, world!\n",
    ".VCSK/main",
    ".VCSK/ver_project"
};

BRANCH branch_c = {
    ".VCSK/%s"
};

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("vcsk <command>\n");
    }
    if (strcmp(argv[1], "init") == 0)
    {
        INIT_F();
    }
    else if ((strcmp(argv[1], "branch") == 0) && (strcmp(argv[2], branch_c.branch) == 0))
    {
        BRANCH_F();
    }
    return 0;
}

void INIT_F()
{
    if (g_file_test(init_c.init, G_FILE_TEST_IS_DIR))
    {
        printf("init\n");
    }
    else
    {
        INIT_F_INIT();
        INIT_F_INFO();
        INIT_F_INFO_FILE();
        INIT_F_MAIN();
        INIT_F_VER_PROJECT();
    }
}

int INIT_F_INIT()
{
    if (g_mkdir_with_parents(init_c.init, 0775) == 0)
    {
        printf("init...\n");
    }
    else
    {
        perror("Error.\n");
        return 1;
    }
    return 0;
}

int INIT_F_INFO()
{
    if (g_mkdir_with_parents(init_c.info, 0775) == 0)
    {
        printf("info...\n");
    }
    else
    {
        perror("Error.\n");
        return 1;
    }
    return 0;
}

int INIT_F_INFO_FILE()
{
    GError *error = NULL;
    if (g_file_set_contents(init_c.info_file, init_c.content_info_file, -1, &error))
    {
        printf("file...\n");
    }
    else
    {
        printf("Error.\n");
        g_error_free(error);
    }
    return 0;
}

int INIT_F_MAIN()
{
    if (g_mkdir_with_parents(init_c.main, 0775) == 0)
    {
        printf("main...\n");
    }
    else
    {
        perror("Error.\n");
        return 1;
    }
    return 0;
}

int INIT_F_VER_PROJECT()
{
    if (g_mkdir_with_parents(init_c.ver_project, 0775) == 0)
    {
        printf("ver_project...\n");
    }
    else
    {
        perror("Error.\n");
        return 1;
    }
    return 0;
}

int BRANCH_F()
{
    if (g_mkdir_with_parents(branch_c.branch, 0775) == 0)
    {
        printf("branch...\n");
    }
    else
    {
        perror("Error.\n");
        return 1;
    }
    return 0;
}
