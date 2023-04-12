#ifndef LEGEO_H
#define LEGEO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncLeituras.h"



// le arquivo .qry, analisa suas especificaçoes e muda formas ou faz açoes
void LerQry(FILE* qry,FILE* txt , Lista lista);
// retorna separadamente a linha do arquivo em formato de strings
char** LeituraLinha(FILE* arq);
// le arquivo .geo,analisa suas especificaçoes,cria forma e as coloca numa lista
void LerGeo(FILE* geo,Lista geral);

#endif