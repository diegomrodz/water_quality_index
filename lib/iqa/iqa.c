#include <math.h>
#include <string.h>
#include "iqa.h"

// Retorna o IQA da medição
double iqa(IQA_T t) 
{
	double p;

	// Realiza o produtório ponderado dos parâmetros com seus
	// respectivos pesos
	p  = pow(qO2(t.O2),  IQA_O2_WEIGHT);
	p *= pow(qCF(t.CF),  IQA_CF_WEIGHT);
	p *= pow(qPH(t.PH),  IQA_PH_WEIGHT);
	p *= pow(qDBO(t.DBO), IQA_DBO_WEIGHT);
	p *= pow(qDT(t.DT),  IQA_DT_WEIGHT);
	p *= pow(qNT(t.NT),  IQA_NT_WEIGHT);
	p *= pow(qFT(t.FT),  IQA_FT_WEIGHT);
	p *= pow(qTU(t.TU),  IQA_TU_WEIGHT);
	p *= pow(qST(t.ST),  IQA_ST_WEIGHT);

	return p;
}

Parameter str_parameter (char* p) 
{
	if (strcmp(p, "O2")  == 0)  return O2;
	if (strcmp(p, "CF")  == 0)  return CF;
	if (strcmp(p, "PH")  == 0)  return PH;
	if (strcmp(p, "DBO") == 0) return DBO;
	if (strcmp(p, "DT")  == 0)  return DT;
	if (strcmp(p, "NT")  == 0)  return NT;
	if (strcmp(p, "FT")  == 0)  return FT;
	if (strcmp(p, "TU")  == 0)  return TU;
	if (strcmp(p, "ST")  == 0)  return ST;
}

void iqa_set(IQA_T* t, IQAIndex idx, double val) 
{
	if (idx == O2)  t->O2  = val;
	if (idx == CF)  t->CF  = val;
	if (idx == PH)  t->PH  = val;
	if (idx == DBO) t->DBO = val;
	if (idx == DT)  t->DT  = val;
	if (idx == NT)  t->NT  = val;
	if (idx == FT)  t->FT  = val;
	if (idx == TU)  t->TU  = val;
	if (idx == ST)  t->ST  = val;	
}

// Converte o IQAIndex para string
char* iqa_index_string(IQAIndex idx) 
{
	if (idx == Best)  return "Otima";
	if (idx == Good)  return "Boa";
	if (idx == OK)    return "Aceitavel";
	if (idx == Bad)   return "Ruim";
	if (idx == Worst) return "Pessima";	
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
	if (CF > 100000) return 3.0;

	double l10 = log10(CF);

	double B = CF_WEIGHT_B * l10;
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

//	return DBO_WEIGHT_A * exp(DT_WEIGHT_B * DBO);
	return (102.6 * exp(-0.1101 * DBO));
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