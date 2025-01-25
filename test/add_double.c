#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	double x = 0;
	double sum = 0;
	int n = 0;

	while (1)
	{
		n = scanf("%lf", &x);
		if (n == 0 ||
				n == EOF ||
				x == 0)
		{
			break;
		}

		sum += x;
		printf("%.2f\n", sum);
	}

	return 0;
}
