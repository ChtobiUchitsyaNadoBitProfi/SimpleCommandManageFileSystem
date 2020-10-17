#include <stdio.h>
#include "SMFS.h"
#include <string.h> //для работы со строками

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("missing arguments\n");
        return 0;
    }

    if (!strcmp(argv[1], "--move"))
    {
        if (argc < 4)
        {
            fprintf(stderr, "missing arguments to 'move'\n");
            return 0;
        }
        move(argv[2], argv[3]);
    } else if (!strcmp(argv[1], "--ls")) {
        if (argc < 3)
        {
            argv[2] = "./";
        }
        ls(argv[2]);
    } else if (!strcmp(argv[1], "--del")) {
        if (argc < 3)
        {
            fprintf(stderr, "missing arguments to 'del'\n");
            return 0;
        }
        del(argv[2]);
    }

    return 0;
}
