#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	double q = 0.0;

	for (; q <= 14.0; q += 1.0) 
	{
		printf("q = %lf, qPH(q) = %lf\n", q, qPH(q));
	}
		
	return 0;
}