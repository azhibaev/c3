#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	double sum = 1.0;
	int factorial = 1;
	int i = 0;

	for (i = 1; i < 6; i++)
	{
		factorial *= i;
		sum += 1.0 / factorial;
		if (i > 2)
		{
			printf("%.5f\n", sum);
		}
	}

	return 0;
}
