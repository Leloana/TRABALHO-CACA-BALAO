#ifndef CACA_H
#define CACA_H

#include <stdio.h>
#include <stdlib.h>
#include "Texto.h"
#include "../Estruturas/fila.h"
#include "../Estruturas/list.h"
#include "../Leituras/arqsvg.h"

typedef void* Caca;

void killCaca(Caca S);
//seta o ID e o texto do caça
Caca set_caca(Texto texto);
//retorna o numero de disparos dados pelo caça
int get_caca_Disparos(Caca S);
//seta o numero de disparos dado pelo caça
void set_caca_Disparos(Caca S, int Dis);
//retorna o tipo do caça 'S'
char get_caca_type(Caca S);
//retorna o texto que constitui o caça
Texto get_caca_Forma(Caca S);
//reorna o ID do caça
int get_caca_ID(Caca S);
//adiciona a uma lista as formas que o caça destruiu
void addIDs(Caca S, Forma figura);
//verifica se forma é caça
bool iscaca(Forma forma);
//retorna o ID do caca S
Lista ReturnID(Caca S);

#endif