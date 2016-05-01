#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	double q1 = 0.0;

	for (; q1 <= 140.0; q1 += 10) 
	{
		printf("q1 = %lf, qO2(q1) = %lf\n", q1, qO2(q1));
	}

		
	return 0;
}