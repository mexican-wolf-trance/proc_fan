#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define MAX 1024

int main (int argc, char *argv[])
{
	pid_t child = 0;
	char **execArg, delimiters[] = " \t\n", executable[MAX];
	int pr_limit = 0, pr_count = 0, total_count = 0;

	if (argc < 2)
	{
		fprintf(stderr, "Not enough arguments for %s\n", argv[0]);
		return 1;
	}
	
	pr_limit = commandLineParse(argc, argv);

	if (pr_limit < 0)
	{
		fprintf(stderr, "Too few iterations (must be greater than 0)");
		return 1;
	}
	
	while(fgets(executable, MAX - 1, stdin) != NULL)
	{
		fprintf(stderr, "executable: %s currently running)\n", executable);
		if (pr_count == pr_limit)
		{
			wait(NULL);
			pr_count--;
		}

		pr_count++;
		total_count++;

		if ((child = fork()) == 0)
		{
			if (argFormat(executable, delimiters, &execArg) == -1)
				perror("Child failed\n");
			else
			{
				execvp(execArg[0], &execArg[0]);
				perror("Child failed to execvp");
			}
			return 1;
		}

		if(child < 0)
                {
                        perror("Failed tp fork");
                        return 1;
                }

	
		if (waitpid(-1, NULL, WNOHANG) > 0)
			pr_count--;
	}
	
	while(1)
	{
		child = wait(NULL);
		
		if ((child == -1) && (errno != EINTR))
		{
			break;
		}
	}

	printf("The total count is: %d\n", total_count);
	return 0;
}
