#include <stdio.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	IQA_T t = {
		.O2  = qO2(100),
		.CF  = qCF(2),
		.PH  = qPH(7.5),
		.DBO = qDBO(1),
		.DT  = qDT(15),
		.NT  = qNT(1),
		.FT  = qFT(0),
		.TU  = qTU(1),
		.ST  = qST(60)
	};

	double a = iqa(t);

	printf("IQA 1 = %lf\n", a);


}