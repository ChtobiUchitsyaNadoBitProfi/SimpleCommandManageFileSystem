#include <stdio.h>
#include <dirent.h> //для работы с директориеями
#include <string.h> //для работы со строками

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
