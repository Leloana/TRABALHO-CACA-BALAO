#ifndef LIN_H
#define LIN_H
#include <stdio.h>
#include <stdlib.h>
#include "formas.h"

typedef void* Linha;

void killLinha(Linha L);
//cria void* com objeto linha
Linha criaLinha(int id,double x1, double y1, double x2, double y2, char* cor);
// retorna o ID da linha
int get_lin_ID(Linha L);
// retorna o x1 da linha
double get_lin_x1(Linha L);
// retorna o y1 da linha
double get_lin_y1(Linha L);
// retorna o x2 da linha
double get_lin_x2(Linha L);
// retorna o y2 da linha
double get_lin_y2(Linha L);
// retorna a cor do preenchimento da linha
char* get_lin_corp(Linha L);
// retorna o tipo da linha 'L'
char get_lin_type(Linha L);
// seta o x1 da linha
void set_lin_x1(Linha L, double x1);
// seta o x2 da linha
void set_lin_x2(Linha L, double x2);
// seta o y1 da linha
void set_lin_y1(Linha L, double y1);
// seta o y2 da linha
void set_lin_y2(Linha L, double y2);
// seta a cor do preenchimento da linha
void set_lin_cor(Linha L, char* cor);
// seta rotacao da linha
void set_lin_rot(Linha L, double rot);
// retorna rotaçao da linha
double get_lin_rot(Linha L);
//seta novo ID
void set_lin_ID(Linha L, int ID);

#endif