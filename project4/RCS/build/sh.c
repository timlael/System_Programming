#include "sh.h"
#define MAX 512
#define SIGCTD 30

void handle_ctd(int sig){
	if (sig==SIGCTD){
		printf("\nCtrl+D encountered... Exiting\n");
	}
	exit(1);
}

int getcmd (char *s, char *buf){
	int c, count;
	signal(SIGCTD, handle_ctd);
	
	printf ("%s ", s); 						/* print prompt*/
	for (count=0; ( c = getchar() ) != EOF; ++count){
		buf [count] = c;
		if (count >= MAX){ 					/* line too long */
			printf ("\n---Input line too long! Please start again.\n");
			count = -1;     				/* clear command line buffer */
			continue;       				/* go to start of for loop */
		}                 					/* end if input line too long */ 
		if ( c == '\n' ){  					/* end of input line */
			buf [count] = NULL;  				/* terminate input string */
			return (count);       				/* return command line */
		}
			                       				/* end if command line done */
	} 								/* end for loop, exiting here means EOF was entered */
	if (c == EOF){
		raise (SIGCTD);
	}
	printf ("\n");
	return (0); 
}									/* end getcmd */

int runcmd (char *cmd){ 
	char *p; 							/* storage for part of command line */
	char *argv[MAX+1] = {NULL}; 					/* arguments of command line (up to 513) */
	int pid; 							/* pid of forked process to execute command line */
	int rc;                                     			/* return code */
	int status; 							/* status of exited child process */
	int argc; 							/* the number of arguments */
	int type = 1; 							/* 1 = foreground, 0 = background */

	if (strcasecmp(cmd, "exit") == 0) {				/* case insensitive search for exit command */
		printf("Exit encountered... Exiting\n");
		exit(EXIT_SUCCESS);
	}
	else {
		for (; *cmd == ' ' || *cmd == '\t'; ++cmd); 			/* ignore leading spaces */
		for (p=cmd; *p; ++p)
  			if (*p == '&'){
    			type = 0;  						/* this is a background process */
    			break; 							/* exit for loop */
			}  							/* end if and for loops, searching for a & */

/* parse the command line into tokens */
		for (argc = 0; *cmd; ++cmd, ++argc){
			p = argv [argc] = (char *) malloc (MAX);		/* create space for argument */
  			while (*cmd != ' ' && *cmd != '\t'){ 			/* get next token */
				if (*cmd == NULL){
					--cmd;
					break; 					/* leave while loop */
				}						/* end if end of line */
			*p = *cmd; 						/* move character from command line to argument */
			++p;    						/* next character in argument */
			++cmd;  						/* next character in command line */
			}							/* end of while statement */
    		*p = NULL; 							/* finish off argument string with NULL */
		} 								/* end for loop, parsed tokens to arguments */

/* ready to run the command */
		pid = fork();  							/* create a child process to run the command */
	
		if (pid < 0){
			printf ("fork failed.\n");
			exit (1);  						/* Failure condition */
		} 								/* end if fork failed */
		
		if (pid == 0){							/* in child process */
			execvp (*argv, argv);
			exit (0);
		} 								/* end if in child process */

/* in parent process */
		if (!type){ 							/* test to see if in background */
			printf ("Child process ID: [%d]\n", pid); 		/* report child process ID */
			return 0;
		} 								/* end if in background */

/* if foreground, wait for child to return */
		while ( ( rc = wait (&status) ) != pid )
		if ( rc == -1) break; 						/* child process crashed */
		return ( rc = -1 ? -1 : status );
	}
}	 
/* end runcmd */ 

