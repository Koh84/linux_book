#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	int data_processed;
	int file_pipes[2];
	const char some_data[] = "123";
	char buffer[BUFSIZ + 1];

	pid_t fork_result;
	memset(buffer, '\0', sizeof(buffer));

	if (pipe(file_pipes) == 0) 
	{
		fork_result = fork();
		if (fork_result == -1) 
		{
			fprintf(stderr, "Fork failure");
			exit(EXIT_FAILURE);
		}

		if (fork_result == 0) 
		{
			//swap pipe read descriptor with stdin descriptor page 538 of book.
			//close stdin - e.g. file descriptor 0 
			close(0);
			dup(file_pipes[0]); //duplicate file descriptor file_pipe which is at fd 3, and this will be druplicated at fd 0
			close(file_pipes[0]); //close pipe read file descriptor
			close(file_pipes[1]); //close pipe write file descriptor
			//sprintf(buffer, "%d", file_pipes[0]);
			(void)execlp("od", "od", "-c", (char *)0);
			exit(EXIT_FAILURE);

		}

		else 
		{
			close(file_pipes[0]);
			data_processed = write(file_pipes[1], some_data, strlen(some_data));
			printf("%d - wrote %d bytes\n", getpid(), data_processed);
		}
	}
	exit(EXIT_SUCCESS);
}

