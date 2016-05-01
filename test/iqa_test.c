#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	IQA_T t = {
		.O2  = 100,
		.CF  = 100,
		.PH  = 100,
		.DBO = 100,
		.DT  = 100,
		.NT  = 100,
		.FT  = 100,
		.TU  = 100,
		.ST  = 100
	};

	double a = iqa(t);

	printf("IQA = %lf\n", a);
}