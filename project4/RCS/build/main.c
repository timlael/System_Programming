#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 512

/* Signal Handler for SIGINT */
void sigintHandler(int sig_num)
{
    	/* Reset handler to catch SIGINT next time. */
	signal(SIGINT, sigintHandler);
	printf("\n Cannot be terminated using Ctrl+C \n>>> ");
	fflush(stdout);
}

int main (){
	char command[MAX+1]; 					/* buffer to hold command */
	char const *prompt;					/* prompt to be passed */
	char const *ps1 = getenv("PS1");			/* temporary holder for PS1 */


signal(SIGINT, sigintHandler);

	/* print system prompt use PS1 if exists */
	if (ps1 != NULL){
		prompt = ps1;
	}
	else {
		prompt = ">>> ";
	}

	/* main shell loop until exited */
	while (1){
		getcmd(prompt, command);
		runcmd (command);
	}
return 0;
} 								/* end main */
