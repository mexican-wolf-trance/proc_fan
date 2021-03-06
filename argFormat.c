#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int argFormat(const char *source, const char *delimiters, char ***newArg)
{
	int i, error, num_tokens;
	char *buff;
	const char *snew;
	
	if ((source == NULL) || (delimiters == NULL) || (newArg == NULL))
	{
		errno = EINVAL;
		perror("Error!");
                printf("Errno is %d\n", errno);
		return -1;
	}

	snew = source + strspn(source, delimiters);

	if ((buff = malloc(strlen(snew) + 1)) == NULL)
	{
		perror("Error!");
                printf("Errno is %d\n", errno);
		return -1;
	}

	strcpy(buff, snew);

	num_tokens = 0;
	if(strtok(buff, delimiters) != NULL)
		for(num_tokens = 1; strtok(NULL, delimiters) != NULL; num_tokens++);

	if ((*newArg = malloc((num_tokens + 1) * sizeof(char *))) == NULL)
	{
		error = errno;
		free(buff);
		errno = error;
		perror("Error!");
		printf("Errno is %d\n", errno);
		return -1;
	}

	if (num_tokens == 0)
		free(buff);

	else
	{
		strcpy(buff, snew);

		**newArg = strtok(buff, delimiters);
		for (i = 1; i < num_tokens; i++)
			*((*newArg) + i) = strtok(NULL, delimiters);
	}

	*((*newArg) + num_tokens) = NULL;

	return num_tokens;
}
	
