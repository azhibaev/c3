/* Calculation of value sin(x)
   with acceptable accuracy.

   Author: Askar Azhibaev.
   Date: Wed 14 Aug 2024 16:29:07 UTC
*/
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_DELTA_ERROR 0.0000005
#define DEFAULT_FORMAT_PRECISION ".6"
#define PI 3.141592653589793

int main(int argc, const char *argv[])
{
	double x = 0;				/* x argument */
	double d_error = 0;			/* delta error argument */
	double x2 = 0;				/* x * x */
	double d_factorial = 0;		/* delta factorial */
	double term = 0;			/* term */
	double sum = 0;				/* summa */
	double i = 1;				/* simple counter */
	int sign = 0;				/* sign */
	long long x1 = 0;			/* temp variable for 2 * PI remainder */

	if (argc < 2)
	{
		printf("Usage: %s x [delta]\nx in radians, default delta is %.7f.\n",
				argv[0],
				DEFAULT_DELTA_ERROR);
		return 1;
	}

	/* Get x argument */
	x = strtod(argv[1], NULL);
	if (x > 2 * PI ||
			x < - 2 * PI)
	{
		/* Calculate 2 * PI remainder */
		if (x > 1e14 ||
				x < -1e14)
		{
			printf("Error: max x is 1e14\n");
			return 2;
		}
		x1 = (long long)(x / (2 * PI));
		x = x - x1 * 2 * PI;
	}

	/* Get delta error argument
	   otherwise assign default value */
	if (argc < 3)
	{
		d_error = DEFAULT_DELTA_ERROR;
	}
	else
	{
		d_error = strtod(argv[2], NULL);
		if (d_error == 0)
		{
			d_error = DEFAULT_DELTA_ERROR;
		}
	}
	if (d_error < 0)
	{
		d_error *= -1;
	}
	if (x < 0)
	{
		d_error *= -1;
	}

	/* Prerequisites */
	x2 = x * x;
	term = x;
	sum = term;

	/* Main cycle */
	while (1)
	{
		/* delta factorial as multiplication
		   of two consecutive counter values */
		d_factorial = ++i;
		d_factorial *= ++i;
		/* Calculate the next term */
		term *= x2 / d_factorial;
		if (sign)
		{
			/* '+' term */
			sum += term;
			sign = 0;
		}
		else
		{
			/* '-' term */
			sum -= term;
			sign = 1;
		}
		if ((term >= 0 &&
					term < d_error) ||
				(term < 0 &&
				 term > d_error))
		{
			/* Quit if acceptable accuracy is achieved */
			break;
		}
	}

	/* Print the result */
	printf("sin(%" DEFAULT_FORMAT_PRECISION "f) = %" DEFAULT_FORMAT_PRECISION "f\n",
			x,
			sum);

	return 0;
}
