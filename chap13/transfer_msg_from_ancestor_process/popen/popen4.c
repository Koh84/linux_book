#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	FILE *read_fp;
	char buffer[BUFSIZ + 1];
	int chars_read;
	int index = 0;

	memset(buffer, '\0', sizeof(buffer));

	read_fp = popen("cat popen*.c | wc -l", "r");
	if (read_fp != NULL) 
	{
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		while (chars_read > 0) 
		{
			index = chars_read-1;
			buffer[index] = '\0';
			printf("Reading:-\n %s\n", buffer);
			chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

