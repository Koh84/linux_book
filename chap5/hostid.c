#include <unistd.h>
#include <stdio.h>

void main()
{

	unsigned long hostid = gethostid();
	printf("%ld ", hostid);
	
}
