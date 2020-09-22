#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int commandLineParse(int argc, char *argv[])
{
	int* proc_limit = malloc(sizeof(int));

	if (argc < 2)
	{
		perror("Need to enter command line arguments");
		return 1;
	}

	int option;
	while ((option = getopt(argc, argv, "n:")) != -1)
	switch (option)
	{
		case 'n':
			*proc_limit = atoi(optarg);
			break;
		default:
			perror("Requires -n argument: max number of concurrent children\n");
			return 1;
	}

	return proc_limit;
}
