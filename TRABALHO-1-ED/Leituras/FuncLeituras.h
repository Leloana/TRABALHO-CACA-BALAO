#ifndef FUNC_LEIT_
#define FUNC_LEIT_

#include <stdbool.h>
#include "../Formas/Circulo.h"
#include "../Formas/Retangulo.h"
#include "../Formas/Linha.h"
#include "../Formas/balao2.h"
#include "../Formas/caca.h"
#include "../Formas/formas.h"
//reporta em um .txt a figura inserida
void reporta_figura(FILE* txt,void* guarda_forma);
//verifica quais figuras estao na area da camera 
bool reconhece_area(Balao B, Forma analise);
//procura na lista a figura de ID escolhido, retornando-a 
void* acha_ID(Lista lista, int ID);
//move a figura escolhida e reporta seus atributos no .txt
void LinhaMove(FILE* txt,Lista lista,int ID,double X,double Y);
//rotaciona a figura escolhida e reporta seus atributos no .txt
void LinhaRotaciona(FILE* txt, Lista lista,int ID,double rot);
//tira uma foto com a camera escolhida e reporta as figuras fotografadas no .txt
void LinhaTiraFoto(FILE* txt, Lista Baloes,Lista lista,Lista decoracoes,int ID,int camera);
//Retorna a posicao da ancora y de analise em relacao a Borda da foto
double dy_Forma(Retangulo Borda, Forma analise);
//Retorna a posicao da ancora x de analise em relacao a Borda da foto
double dx_Forma(Retangulo Borda, Forma analise);
//escreve as fotos em um .svg e avalia elas em um .txt
void ReportaFotos(FILE* txt, Lista Baloes,int ID, char* nome, int camera);
//reporta todos os baloes
void Report_Baloes(FILE* txt,Lista Baloes);
//reporta todos os cacas
void Report_Cacas(FILE* txt, Lista Cacas);
//define o foco do balao de id escolhido da lista baloes
void FocoFoto(Lista Baloes, int ID, double raio, double profundidade, double altura);
//verifica quais figuras estao na area do tiro do caça
bool areaDisparo(double cx, double cy, double raio,Forma analisa);
//verifica se linha foi destruida
bool Linha_Destruida(double x1, double y1, double x2, double y2, double raio, double cx, double cy);
//clona as fotos da lista fotos e coloca-as no banco de dados
void clonaFotos(Lista Banco_Dados,Lista fotos, double x, int j,int* aumento);
//Caça escolhido dispara e reporta as figuras escolhidas num .txt
void DisparoCaca(FILE* txt,Lista Baloes,Lista Cacas, Lista lista,Lista decoracoes,int ID,char* capac,double dist,int j,double dx);
//elimina item de ID escolhido da lista indicada
void eliminaLista(int ID,Lista lista);
//Da free personalizado em cada elemento da lista e da Killlst
void Executa_ListaFormas(Lista executada);

#endif