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
		.O2  = qO2(120),
		.CF  = qCF(50),
		.PH  = qPH(8),
		.DBO = qDBO(3),
		.DT  = qDT(6),
		.NT  = qNT(90),
		.FT  = qFT(1),
		.TU  = qTU(5),
		.ST  = qST(50)
	};

	double b = iqa(t2);

	printf("IQA 1 = %lf\n", a);

	printf("IQA 2 = %lf\n", b);


	printf("IQA.O2 = %lf\n", t2.O2);
	printf("IQA.CF = %lf\n", t2.CF);
	printf("IQA.PH = %lf\n", t2.PH);
	printf("IQA.DBO = %lf\n", t2.DBO);
	printf("IQA.DT = %lf\n", t2.DT);
	printf("IQA.NT = %lf\n", t2.NT);
	printf("IQA.FT = %lf\n", t2.FT);
	printf("IQA.TU = %lf\n", t2.TU);
	printf("IQA.ST = %lf\n", t2.ST);

}