#ifndef CIRC_H
#define CIRC_H
#include <stdio.h>
#include <stdlib.h>
#include "formas.h"

typedef void* Circulo;

void killCirc(Circulo C);
//cria void* com objeto circulo
Circulo criaCirc(int id,double cx, double cy, double r,char* corb,char* corp);
//retorna ID do circulo
int get_circ_ID(Circulo C);
// retorna coordenada cx do circulo
double get_circ_cx(Circulo C);
// retorna coordenada cy do circulo
double get_circ_cy(Circulo C);
// retorna raio do circulo
double get_circ_r(Circulo C);
// retorna cor da borda do circulo
char* get_circ_corb(Circulo C);
// retorna cor de preenchimento do circulo
char* get_circ_corp(Circulo C);
// retorna tipo circulo 'C'
char get_circ_type(Circulo C);
// seta cx do circulo
void set_circ_cx(Circulo C,double cx);
// seta cy do circulo
void set_circ_cy(Circulo C,double cy);
// seta raio do circulo
void set_circ_raio(Circulo C,double raio);
// seta cor do preenchimento do circulo
void set_circ_corp(Circulo C,char* corp);
// seta cor da borda do circulo
void set_circ_corb(Circulo C,char* corb);
//seta rotacao do circulo
void set_circ_rot(Circulo C,double rot);
//retorna rotaçao do circulo
double get_circ_rot(Circulo C);
//seta ID do circulo
void set_circ_ID(Circulo C,int ID);

#endif