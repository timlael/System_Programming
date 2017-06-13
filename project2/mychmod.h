/*tmlz5d Tim M. Lael Project 2 cs2750e01*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

enum {OTH, GRP, USR};

/*structure holding attribute changes*/
typedef struct attributes{
    mode_t add;
    mode_t rem;
} attributes;

/*structure for holding list of files*/
typedef struct filelist{
    int list_capacity;
    int list_size;
    char **filenames;
} filelist;

/*function prototypes*/
int add_changes(mode_t *set, char *arg, int modeset);
int change_permissions(filelist *files, attributes *attribs);
int read_input(int argc, char **argv, attributes *attribs, filelist *files);
int add_to_file_list(filelist *list, const char *filename);
