#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	double q = 0.0;

	for (; q <= 500; q += 50) 
	{
		printf("q = %lf, qST(q) = %lf\n", q, qST(q));
	}
		
	return 0;
}
