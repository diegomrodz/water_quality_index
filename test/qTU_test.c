#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	double q = 0.0;

	for (; q <= 100; q += 10) 
	{
		printf("q = %lf, qTU(q) = %lf\n", q, qTU(q));
	}
		
	return 0;
}
