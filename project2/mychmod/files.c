/*tmlz5d Tim M. Lael Project 2 cs2750e01*/
#include "../mychmod.h"

/*add_to_file_list() is called by read_input() and reads files supplied as an argument from the terminal
and adds them to a list of files to be processed.
input parameters are:
	list - A pre-existing list structure for holding filenames
	filename - The new filename string to be added
0 success/completion, 1 error*/

int add_to_file_list(filelist *list, const char *filename){
/*check and size list to hold entries*/
    if(list != NULL){
        if(list->list_size + 1 > list->list_capacity){
            char **new_filename_list;

            new_filename_list = realloc(list->filenames, sizeof(char *) *(list->list_capacity + 50));
            if(new_filename_list == NULL){
                return 1;
            }
            list->filenames = new_filename_list;
            list->list_capacity = list->list_capacity + 50;
        }

/*add filename to list*/
        list->filenames[list->list_size] = calloc(strlen(filename) + 1, sizeof(char));
        if(list->filenames[list->list_size] == NULL){
            return 1;
        }
        strcpy(list->filenames[list->list_size], filename);
        list->list_size = list->list_size + 1;
    }
	return 0;
}
