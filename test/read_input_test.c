#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	IQA_T t;
	char param[3];
	double val;

	while (scanf("-%s=%lf", param, &val) == 1) 
	{
		IQAIndex idx = str_parameter(param);

		iqa_set(&t, idx, val);

		printf("%s=%lf\n", param, val);
	}

	printf("IQA.O2 = %lf\n", t.O2);
	printf("IQA.CF = %lf\n", t.CF);
	printf("IQA.PH = %lf\n", t.PH);
	printf("IQA.DBO = %lf\n", t.DBO);
	printf("IQA.DT = %lf\n", t.DT);
	printf("IQA.NT = %lf\n", t.NT);
	printf("IQA.FT = %lf\n", t.FT);
	printf("IQA.TU = %lf\n", t.TU);
	printf("IQA.ST = %lf\n", t.ST);
}