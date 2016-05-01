#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	int i = 0;
	double q1 = 0.0;

	for (; i <= 100; i += 1) 
	{
		printf("q1 = %lf, qO2(q1) = %lf\n", q1, qO2(q1));
	}

	return 0;
}