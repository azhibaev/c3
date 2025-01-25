#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char a[] = "aaa";
	char *b = "bbb";

	a[0] = 'A';
	//b[0] = 'B';

	printf("%ld %ld\n", sizeof(a), sizeof(b));

	return 0;
}
