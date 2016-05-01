#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	double q = 5.0;

	for (; q <= 50000; q *= 10) 
	{
		printf("q = %lf, qCF(q) = %lf\n", q, qCF(q));
	}
		
	return 0;
}