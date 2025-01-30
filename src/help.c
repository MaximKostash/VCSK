#include "../include/fun.h"

int HELP()
{
    printf("HELP\n\n");
    printf("file - The name of your file.\ndir - The name of your directory.\n\n");
    printf("vcsk init - system initialization\n");
    printf("vcsk branch <dir> - creating a branch\n");
    printf("vcsk add <file> - adding to main folder\n");
    printf("vcsk add-dir <dir> <file> - adding a version to a specific folder\n");
    printf("vcsk replace <file> - replace with file from main folder\n");
    printf("vcsk replace-dir <dir> <file> - replace with file from specific version folder\n");
    printf("vcsk del <file> - deleting a file from the main folder\n");
    printf("vcsk del-dir <dir> <file> - delete file from specific version folder\n");
    printf("vcsk notes \"text\" - make a note\n");
    printf("vcsk notes-clear - clears all the notes\n");
    printf("vcsk del-ver <dir> - delete specific version folder\n");
    printf("vcsk history-clear - clears the history of actions\n");
    return 0;
}
