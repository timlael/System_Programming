/*tmlz5d Tim M. Lael Project 2 cs2750e01*/
#include "../mychmod.h"


/*read_input() parses the input from the terminal and checks to see if the proper arguments were supplied.
input parameters are: 
	argc - argument count from terminal
    argv - terminal arguments
    attribs - list of permissions to be applied
    files - list of files to apply permissions to
0 success, 1 parse error*/

int read_input(int argc, char **argv, attributes *attribs, filelist *files){
/*check minimum needed arguments were passed*/
    if(argc < 4){
        fprintf(stderr, "Error: Insufficient number of arguments\n");
        return 1;
    }
/*parse user, group, other and attribute switches*/
    int index;
    int c;

    while ((c = getopt (argc, argv, "u:g:o:U:G:O:")) != -1){
        switch (c){
            case 'u':
                if(add_changes(&(attribs->add), optarg, USR) != 0) return 1;
                break;
            case 'g':
                if(add_changes(&(attribs->add), optarg, GRP) != 0) return 1;
                break;
            case 'o':
                if(add_changes(&(attribs->add), optarg, OTH) != 0) return 1;
                break;
            case 'U':
                if(add_changes(&(attribs->rem), optarg, USR) != 0) return 1;
                break;
            case 'G':
                if(add_changes(&(attribs->rem), optarg, GRP) != 0) return 1;
                break;
            case 'O':
                if(add_changes(&(attribs->rem), optarg, OTH) != 0) return 1;
                break;
            default:
                fprintf(stderr, "Error: Invalid Argument: %s\n", argv[0]);
                return 1;
        }
    }

/* Treat all other arguments as filenames */
    for (index = optind; index < argc; index++){
        if(add_to_file_list(files, argv[index]) != 0){
            fprintf(stderr, "Error: Unable to add filename to list\n");
            return 1;
        }
    }

/*check a file was supplied*/
    if(files->list_size == 0){
        fprintf(stderr, "Error: No files given\n");
        return 1;
    }
	return 0;
}
