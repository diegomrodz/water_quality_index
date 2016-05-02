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

	IQA_T t2 = {
		.O2  = qO2(40),
		.CF  = qCF(5),
		.PH  = qPH(8),
		.DBO = qDBO(3),
		.DT  = qDT(0),
		.NT  = qNT(90),
		.FT  = qFT(1),
		.TU  = qTU(5),
		.ST  = qST(50)
	};

	double b = iqa(t);

	printf("IQA 1 = %lf\n", a);
	printf("IQA 2 = %lf\n", b);

}