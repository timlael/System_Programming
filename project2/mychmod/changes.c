/*tmlz5d Tim M. Lael Project 2 cs2750e01*/
#include "../mychmod.h"

/*add_changes() is called from read_input() and adds individual permissions to a list to be applied
input parameters are:
	set - address of attribs struct to hold permissions
	arg - termial argument passed from read_input()
	modeset - USR, GRP or OTH passed as an argument from read_input()
0 success, 1 error*/

int add_changes(mode_t *set, char *arg, int modeset){
    mode_t modechange = 0;
    int i;

/*Extract each permission attribute*/
    for(i = 0; i < strlen(arg); i++){
/* Add appropriate bit value */
        switch(arg[i]){
           case 'r': modechange = modechange | 0x04; break;
           case 'w': modechange = modechange | 0x02; break;
           case 'x': modechange = modechange | 0x01; break;
           default:
               fprintf(stderr, "Error: Invalid permission option: %c\n", arg[i]);
               return 1;
        }
    }

/*bit shift position for USR, GRP or OTH*/
    switch(modeset){
        case USR: modechange = modechange << 6; break;
        case GRP: modechange = modechange << 3; break;
    }

/* Update existing set of changes */
    *set = *set | modechange;

    return 0;
}

/*change_permissions() is called from main upon successful completion of file list and permissions parsing
it uses a filelist and attributes struct as inputs to apply changes to the files
input parameters: 
	files - file list struct containing files to be changed
	attribs - attribs struct containing attributes to be applied or removed
0 success, 2 file access error, 4 file exist error*/

int change_permissions(filelist *files, attributes *attribs){
    int i, rv = 0;
    mode_t newmode, removemodes;
    struct stat statbuf;

    for(i = 0; i < files->list_size; i++){
/* Get current mode of file */
        if(stat(files->filenames[i], &statbuf) != 0){
            switch(errno){
                case EACCES:
                    rv = 2;
                    fprintf(stderr, "Error: Access to %s denied\n",
                        files->filenames[i]);
                    continue;
                case ENOENT:
                    rv = 4;
                    fprintf(stderr, "Error: %s does not exist\n",
                        files->filenames[i]);
                    continue;
                default:
                    fprintf(stderr, "Error: Unexpected error accessing %s - %s\n",
                        files->filenames[i], strerror(errno));
            }
        }

/*create new mode value using a binary OR, AND and XOR*/
        newmode = statbuf.st_mode;
        newmode = newmode | attribs->add;
        removemodes = newmode & attribs->rem;
        newmode = newmode ^ removemodes;

/*apply changes*/
        if(chmod(files->filenames[i], newmode) != 0){
            switch(errno){
                case EPERM:
                    rv = 2;
                    fprintf(stderr, "Error: Insufficient privileges to change %s\n",
                        files->filenames[i]);
                    continue;
                case ENOENT:
                    rv = 4;
                    fprintf(stderr, "Error: %s does not exist\n",
                        files->filenames[i]);
                    continue;
                default:
                    fprintf(stderr, "Error: Unexpected error while trying to change %s - %s\n",
                        files->filenames[i], strerror(errno));
            }
        }
    }
/*return meaningful return value*/
    return rv;
}
