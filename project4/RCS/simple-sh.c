#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

pid_t pid;

void sig_handler(int sig)
{
  printf("\n\nPARENT caught signal [%d]\n\n", sig);
  if (sig == SIGINT) {
    signal(SIGINT, sig_handler);
  }
}

void hello()
{
  printf("processing hello command\n");
  sleep(2);
}

void goodbye()
{
  printf("processing goodbye command\n");
  sleep(2);
}

main(int argc, char **argv, char **envp)
{
  int   i;
  char  *arg[4];
  char  cmd[10];
  char  command[10];

  signal(SIGINT, sig_handler);

  arg[0] = (char *) malloc(10); 
  strcpy(arg[0], "child");
  arg[1] = (char*) 0;

  while (1) {
    printf("2750 shell >>> ");
    gets(cmd);
    if (strcmp(cmd, "hello") == 0) {
      hello();
      continue;
    }
    else
    if (strcmp(cmd, "goodbye") == 0) {
      goodbye();
      continue;
    }
    else
    if (strcmp(cmd, "fg") == 0) {
      waitpid(pid, NULL, 0); 
    }
    else {
      if (strcmp(cmd, "sleep") == 0) {
	strcpy(command, "sleep");
      }
      else {
        printf("command not found\n");
        continue;
      }
      pid = fork();
      if (pid == 0) {                 /* child */
        execve(command, arg, envp);
      }
      else {                          /* parent */
        waitpid(pid, NULL, WNOHANG); 
      }
    }
  }
}

