#include <stdio.h>
#include <stdlib.h>

//int debug;
//char msg[20];

int main()
{
	#ifdef DEBUG
	printf("Compiled: " __DATE__ " at " __TIME__ "\n");
	printf("This is line %d of file %s\n", __LINE__, __FILE__);
	#endif
	printf("hello world\n");

	/*if(debug)
	{
		sprintf(msg, "Compiled: " __DATE__ " at " __TIME__ "\n");
		write_debug(msg);
	}*/
	exit(0);
}

