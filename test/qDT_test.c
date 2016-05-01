#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	double q = -5.0;

	for (; q <= 20; q += 5) 
	{
		printf("q = %lf, qDT(q) = %lf\n", q, qDT(q));
	}
		
	return 0;
}
