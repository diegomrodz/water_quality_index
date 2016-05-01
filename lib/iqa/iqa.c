#include <math.h>
#include "iqa.h"

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

	double e = FT_WEIGHT_B * FT_WEIGHT_C * pow(FT, FT_WEIGHT_C);

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
