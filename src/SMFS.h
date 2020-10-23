#ifndef SMFS_H
#define SMFS_H

int move(char *oldname, char *newname);
int del(char *filename);
int is_dir(char *path);
int ls(char *dir);
int size(char *path);
void dir_size(const char *name, int *amount);
int help();
int copy(char *src, char *dest);

#endif
