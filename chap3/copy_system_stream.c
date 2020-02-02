#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	FILE *in, *out;

	in = fopen("draft.txt","r");
	out = fopen("out_stream.txt","w");

	while( (c=fgetc(in)) != EOF)
	{
		fputc(c,out);
	}
	
	exit(0);
}
