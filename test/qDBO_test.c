#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	double q = 0.0;

	for (; q <= 40; q += 5) 
	{
		printf("q = %lf, qDBO(q) = %lf\n", q, qDBO(q));
	}
		
	return 0;
}
