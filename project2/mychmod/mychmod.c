/*tmlz5d Tim M. Lael Project 2 cs2750e01*/
#include "../mychmod.h"



/* Return values: 	0 success
                	1 parsing/no file supplied error (returned from read_input())
                	2 no permissions/access error (returned from change_permissions() via read_input())
                	4 file not exists error (returned from change_permissions() via read_input())*/


int main(int argc, char **argv){
/* initialize return value variable, attributes structure, flielist structure and zero fill attribs and files structure*/
		int returnval;
    	attributes attribs;
    	filelist files;
    	memset(&attribs, 0, sizeof(struct attributes));
    	memset(&files, 0, sizeof(struct filelist));

/*parse terminal input and store attribute changes to be mad and file list that changes will be applied to*/
    returnval = read_input(argc, argv, &attribs, &files);
/*if input error provide guidance on proper usage*/
    if(returnval != 0){
        fprintf(stderr, "Usage: mychmod [-u rwx] [-g rwx] [-o rwx] [-U rwx] [-G rwx] [-O rwx] <filename> [<filename>...]\n");
        return returnval;
    }

/*apply changes to files*/
    returnval = change_permissions(&files, &attribs);

    return returnval;
}
