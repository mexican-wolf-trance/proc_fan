#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define MAX 100

int main (int argc, char *argv[])
{
	pid_t child;
	char **execArg, delimiters[] = "\t\n", executable[MAX];
	int pr_limit = 0, pr_count = 0, total_count = 0;

	if (argc != 2)
	
