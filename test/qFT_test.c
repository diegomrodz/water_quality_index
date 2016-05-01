#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	double q = 0.0;

	for (; q <= 10; q += 0.5) 
	{
		printf("q = %lf, qFT(q) = %lf\n", q, qFT(q));
	}
		
	return 0;
}
