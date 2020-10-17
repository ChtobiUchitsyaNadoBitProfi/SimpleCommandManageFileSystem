#include <stdio.h>
#include "SMFS.h"
#include <string.h> //для работы со строками

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: ./SMFS [KEY]...\nr use key --help\n");
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
    } else if (!strcmp(argv[1], "--size")) {
        if (argc < 3)
        {
            fprintf(stderr, "missing arguments to 'size'\n");
            return 0;
        }
        size(argv[2]);
    } else if (!strcmp(argv[1], "--help")) {
        help();
    }

    return 0;
}
