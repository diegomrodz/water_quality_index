#include <math.h>
#include "iqa.h"

// Retorna o IQA da medição
double iqa(IQA_T t) 
{
	double p;

	// Realiza o produtório ponderado dos parâmetros com seus
	// respectivos pesos
	p  = (t.O2  * IQA_O2_WEIGHT);
	p *= (t.CF  * IQA_CF_WEIGHT);
	p *= (t.PH  * IQA_PH_WEIGHT);
	p *= (t.DBO * IQA_DBO_WEIGHT);
	p *= (t.DT  * IQA_DT_WEIGHT);
	p *= (t.NT  * IQA_NT_WEIGHT);
	p *= (t.FT  * IQA_FT_WEIGHT);
	p *= (t.TU  * IQA_TU_WEIGHT);
	p *= (t.ST  * IQA_ST_WEIGHT);

	return p;
}

// Retorna o range em que a medição se encontra
IQAIndex iqa_index(double iqa)
{
	// Checa por valores que ultrapassem os limites
	if (iqa <= IQA_WORST_L) return Worst;
	if (iqa >= IQA_BEST_U) return Best;

	if (iqa > IQA_WORST_L && iqa < IQA_WORST_U) return Worst;
	if (iqa > IQA_BAD_L   && iqa < IQA_BAD_U) return Bad;
	if (iqa > IQA_OK_L    && iqa < IQA_OK_U) return OK;
	if (iqa > IQA_GOOD_L  && iqa < IQA_GOOD_U) return Good;
	if (iqa > IQA_BEST_L  && iqa < IQA_BEST_U) return Best;
}

// Equação ajustada à curva do parâmetro O2
double qO2 (double O2)
{
	if (O2 == 140) return 47;

	double p = pow(O2 + O2_WEIGHT_B, 2);

	return O2_WEIGHT_A * exp(p / O2_WEIGHT_C);
}

// Equação ajustada à curva do parâmetro CF
double qCF (double CF)
{
	double l10 = log10(CF);

	double B = CF_WEIGHT_B * log(CF);
	double C = CF_WEIGHT_C * pow(l10, 2);
	double D = CF_WEIGHT_D * pow(l10, 3);

	return CF_WEIGHT_A + B + C + D;
}

// Equação ajustada à curva do parâmetro PH
double qPH (double PH)
{
	if (PH > 12) return 3.0;
	if (PH < 2) return 2.0;

	double e = PH_WEIGHT_B * PH + PH_WEIGHT_C * pow(PH, 2);

	return PH_WEIGHT_A * pow(PH, e) + 5.213;
}

// Equação ajustada à curva do parâmetro DBO
double qDBO (double DBO)
{
	if (DBO > 30) return 2.0;

	return DBO_WEIGHT_A * exp(DBO_WEIGHT_B * DBO);
}

// Equação ajustada à curva do parâmetro FT
double qFT (double FT)
{
	if (FT > 10) return 1.0;

	double e = FT_WEIGHT_B * pow(FT, FT_WEIGHT_C);

	return FT_WEIGHT_A * exp(e);
}

// Equação ajustada à curva do parâmetro NT
double qNT (double NT)
{
	if (NT > 100) return 1.0;

	return NT_WEIGHT_A * pow(NT, NT_WEIGHT_B + NT_WEIGHT_C * NT);
}

// Equação ajustada à curva do parâmetro TU
double qTU (double TU)
{
	if (TU > 100) return 5.0;

	double e = TU_WEIGHT_B * TU + TU_WEIGHT_C * sqrt(TU);

	return TU_WEIGHT_A * exp(e);
}

// Equação ajustada à curva do parâmetro DT
double qDT (double DT)
{
	if (DT <= 5) return 0;
	if (DT > 15) return 9;

	return 1 / (DT_WEIGHT_A * pow(DT + DT_WEIGHT_B, 2) + DT_WEIGHT_C);
}

// Equação ajustada à curva do parâmetro ST
double qST (double ST)
{
	if (ST > 500) return 32;

	double e = ST_WEIGHT_B * ST + ST_WEIGHT_C * sqrt(ST);

	return ST_WEIGHT_A * exp(e) + ST_WEIGHT_D * ST;
}