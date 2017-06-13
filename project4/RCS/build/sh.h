#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#define MAX 512

int getcmd (char *s, char *buf);
int runcmd (char *cmd);
void handle_ctd(int sig);
