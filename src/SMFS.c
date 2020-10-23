#include <stdio.h>
#include <string.h> //для работы со строками
#include <dirent.h> //для работы с директориеями
#include <sys/stat.h> //для получения информации о файлах
#include "SMFS.h"

#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define WHITE "\x1b[37m"

int move(char *oldname, char *newname)
{
    if (rename(oldname, newname) == -1)
    {
        printf("File move error!\n");
        return 0;
    }
    
    return 0;
}

int	del(char *filename)
{
    if (remove(filename) == -1)
    {
        printf("File delete error!\n");
        return 0;
    }
    
    return 0;
}

int is_dir(char *path)
{
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
    {
        return 0;
    }
    
    return S_ISDIR(statbuf.st_mode);   
}

int ls(char *dir)
{
    DIR *thisdir = opendir(dir);
    if (!thisdir) 
    {
        perror(dir);
        return 0;
    }

    struct dirent *ep;
    printf(BLUE "%s :\n" WHITE, dir);

    while (ep = readdir(thisdir))
    {
        if (strncmp(ep->d_name, ".", 1))
        {
            if (is_dir(ep->d_name))
            {
                printf("\t%s/\n", ep->d_name);
            } else {
                printf(GREEN "\t%s\n" WHITE, ep->d_name);
            }
        }
    }
    closedir(thisdir);
    
    return 0;
}

int size(char *path)
{
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
    {
        return 0;
    }

    int amount = 0;
    if (is_dir(path))
    {
        amount += statbuf.st_size;
        dir_size(path, &amount);
    } else {
        amount = statbuf.st_size;
    }
    printf("%s %d bytes\n", path, amount);

    return 0;
}

void dir_size(const char *name, int *amount)
{
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
    {
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        char path[1024];
        if (entry->d_type == DT_DIR)
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            dir_size(path, amount);
        } else {
            struct stat statbuf;
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            stat(path, &statbuf);
            *amount += statbuf.st_size;
        }
    }

    closedir(dir);
}

int help()
{
    printf("Использование: ./SMFS [КЛЮЧ]...\n\n"
           "Доступные ключи:\n"
           "--move перемещение файла\n"
           "       (Пример: ./SMFS --move ./text.txt ./bin/text.txt)\n"
           "--del  удаление файла\n"
           "       (Пример: ./SMFS --del text.txt)\n"
           "--ls   отображение всех файлов в указанной директории,\n"
           "       если директория не указала показываются файлы из\n"
           "       директории запуска программы\n"
           "       (Пример: ./SMFS --ls ; ./SMFS --ls ./bin)\n"
           "--size отображает размер файла в байта\n"
           "       (Пример: ./SMFS --size tex.txt)\n\n"
           "Авторы: Мельников Иван, Беседин Яков\n"
          );
    
    return 0;
}

int copy(char *src, char *dest) 
{
    FILE *srcF = fopen(src, "r");
    if (!srcF) 
    {
        printf("File not find!\n");
        return 1;
    }
    
    FILE *destF = fopen(dest, "w+");
    if (!destF) 
    {
        printf("Init file error!\n");
        return 1;
    }

    char c;
    while ((c = fgetc(srcF)) != EOF) 
    {
        fputc(c, destF);
    }
    
    fclose(srcF);
    fclose(destF);

    return 0;
}
