#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "iqa/iqa.h"

int main(void) 
{
	IQA_T t;
	IQAIndex idx_cetesb, idx_conama;
	double val;

	scanf("O2 = %lf\n", &t.O2);
	scanf("CF = %lf\n", &t.CF);
	scanf("PH = %lf\n", &t.PH);
	scanf("DBO = %lf\n", &t.DBO);
	scanf("DT = %lf\n", &t.DT);
	scanf("NT = %lf\n", &t.NT);
	scanf("FT = %lf\n", &t.FT);
	scanf("TU = %lf\n", &t.TU);
	scanf("ST = %lf\n", &t.ST);

	val = iqa(t);

	printf("Resultado: %lf\n", val);
	
	idx_cetesb = iqa_cetesb_index(val);
	idx_conama = iqa_conama_index(val);

	printf("Qualidade segundo CETESB: %s\n", iqa_index_string(idx_cetesb));
	printf("Qualidade segundo CONAMA: %s\n", iqa_index_string(idx_conama));

}