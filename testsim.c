#include <stdio.h>

int main(nt argc, char *argv[])
{
	int n, sec;
	if (argc <= 2)
		{
			fprintf(stderr, "Usage: %s sleep_time repear_factor\n", argv[0]);
			exit(1);
		}
	sscanf(argv[1], "%d", &sec);
	sscanf(argv[2], "%d", &n);
	printf("Command: %s %d %d\n\n", argv[0], sec, n);
	while (n > 0)
	{
		sleep(sec);
		printf("Process %d [%d] is sleeping %d seconds\n", getpid(), n, sec);
		n--;
	}
	printf("\nProcess %d end!\n\n", getpid());
	return sec;
}
