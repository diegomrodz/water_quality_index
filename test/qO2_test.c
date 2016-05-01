#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	double q = 0.0;

	for (; q <= 140.0; q += 10) 
	{
		printf("q = %lf, qO2(q) = %lf\n", q, qO2(q));
	}

		
	return 0;
}