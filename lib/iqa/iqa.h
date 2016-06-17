#ifndef FILE_IQA
#define FILE_IQA

// Pesos de cada parâmetro na equação IQA
#define IQA_O2_WEIGHT  0.17
#define IQA_CF_WEIGHT  0.15
#define IQA_PH_WEIGHT  0.12
#define IQA_DBO_WEIGHT 0.10
#define IQA_DT_WEIGHT  0.10
#define IQA_NT_WEIGHT  0.10
#define IQA_FT_WEIGHT  0.10
#define IQA_TU_WEIGHT  0.08
#define IQA_ST_WEIGHT  0.08

// Range Ótimo do índice IQA segundo a CETESB
#define IQA_CETESB_BEST_U 100
#define IQA_CETESB_BEST_L 80

// Range Bom do índice IQA segundo a CETESB
#define IQA_CETESB_GOOD_U 79
#define IQA_CETESB_GOOD_L 51

// Range Aceitável do índice IQA segundo a CETESB
#define IQA_CETESB_OK_U 50
#define IQA_CETESB_OK_L 37

// Range Ruim do índice IQA segundo a CETESB
#define IQA_CETESB_BAD_U 36
#define IQA_CETESB_BAD_L 20

// Range Péssima do índice IQA segundo a CETESB
#define IQA_CETESB_WORST_U 19
#define IQA_CETESB_WORST_L 0

// Range Ótimo do índice IQA segundo o CONAMA
#define IQA_CONAMA_BEST_U 100
#define IQA_CONAMA_BEST_L 91

// Range Bom do índice IQA segundo o CONAMA
#define IQA_CONAMA_GOOD_U 90
#define IQA_CONAMA_GOOD_L 71

// Range Aceitável do índice IQA segundo o CONAMA
#define IQA_CONAMA_OK_U 70
#define IQA_CONAMA_OK_L 51

// Range Ruim do índice IQA segundo o CONAMA
#define IQA_CONAMA_BAD_U 50
#define IQA_CONAMA_BAD_L 26

// Range Péssima do índice IQA segundo o CONAMA
#define IQA_CONAMA_WORST_U 25
#define IQA_CONAMA_WORST_L 0

// Pesos para equação do percentual de oxigênio dissolvido
#define O2_WEIGHT_A 100.8
#define O2_WEIGHT_B -106
#define O2_WEIGHT_C -3745

// Pesos para equação dos conliformes fecais
#define CF_WEIGHT_A 98.03
#define CF_WEIGHT_B -36.45
#define CF_WEIGHT_C 3.138
#define CF_WEIGHT_D 0.06776

// Pesos para equação do pH
#define PH_WEIGHT_A 0.05421
#define PH_WEIGHT_B 1.23
#define PH_WEIGHT_C -0.09873
#define PH_WEIGHT_D 5.213

// Pesos para equação do DBO (Demanda Bioquímica de Oxigênio)
#define DBO_WEIGHT_A 102.6
#define DBO_WEIGHT_B -0.1101

// Pesos para equação do fósforo total
#define FT_WEIGHT_A 213.7
#define FT_WEIGHT_B -1.680
#define FT_WEIGHT_C 0.3325

// Pesos para equação do nitrogênio total
#define NT_WEIGHT_A 98.34
#define NT_WEIGHT_B -0.2232
#define NT_WEIGHT_C -0.006457

// Pesos para equação da turbidez
#define TU_WEIGHT_A 97.34
#define TU_WEIGHT_B -0.01139
#define TU_WEIGHT_C -0.04917

// Pesos para equação da variação de temperatura
#define DT_WEIGHT_A 0.0003869
#define DT_WEIGHT_B 0.1815
#define DT_WEIGHT_C 0.01081

// Pesos para equação da sólidos totais
#define ST_WEIGHT_A 80.26
#define ST_WEIGHT_B -0.00107
#define ST_WEIGHT_C 0.03009
#define ST_WEIGHT_D -0.1185

// Estrutura que carrega dados de uma medição
typedef struct 
{
	// Parâmetros na ordem de relevância para o índice
	double O2;
	double CF;
	double PH;
	double DBO;
	double DT;
	double NT;
	double FT;
	double TU;
	double ST;
} IQA_T;

// Estrutura que carrega os pesoas do IQA
typedef struct 
{
	// Parâmetros na ordem de relevância para o índice
	double O2;
	double CF;
	double PH;
	double DBO;
	double DT;
	double NT;
	double FT;
	double TU;
	double ST;    
} IQA_W_T;

// Enumeração da classificação do IQA
typedef enum 
{
	Best,
	Good,
	OK,
	Bad,
	Worst
} IQAIndex;

// Enumeração dos prâmetros
typedef enum 
{
	O2  = 1,
	CF  = 2,
	PH  = 3,
	DBO = 4,
	DT  = 5,
	NT  = 6,
	FT  = 7,
	TU  = 8,
	ST  = 9
} Parameter;

// Definição das funções de cada um dos parâmetros
double qO2  (double);
double qCF  (double);
double qPH  (double);
double qDBO (double);
double qFT  (double);
double qNT  (double);
double qTU  (double);
double qDT  (double);
double qST  (double);

double iqa(IQA_T);
double iqa_c(IQA_T, IQA_W_T);

int validate_t(IQA_T);

IQAIndex iqa_cetesb_index(double);
IQAIndex iqa_conama_index(double);

char* iqa_index_string(IQAIndex);

Parameter str_parameter (char*);

void iqa_set(IQA_T*, IQAIndex, double);

#endif
