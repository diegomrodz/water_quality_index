#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	double q = 0.0;

	for (; q <= 100; q += 5) 
	{
		printf("q = %lf, qNT(q) = %lf\n", q, qNT(q));
	}
		
	return 0;
}
