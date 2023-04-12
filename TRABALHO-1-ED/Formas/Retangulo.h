#ifndef RET_H
#define RET_H
#include <stdio.h>
#include <stdlib.h>
#include "formas.h"

typedef void* Retangulo;

void killRet(Retangulo R);
//cria void* com objeto retangulo
Retangulo criaRect(int id,double x, double y, double larg, double alt,char* corb,char* corp);
// retorna o id do retangulo
int get_ret_ID(Retangulo R);
// retorna o x do retangulo
double get_ret_x(Retangulo R);
// retorna y do retangulo
double get_ret_y(Retangulo R);
// retorna a largura do retangulo
double get_ret_larg(Retangulo R);
// retorna a altura do retangulo
double get_ret_alt(Retangulo R);
// retorna a cor da borda do retangulo
char* get_ret_corb(Retangulo R);
// retorna a cor do preenchimento do retangulo
char* get_ret_corp(Retangulo R);
// retorna o tipo do retangulo 'R'
char get_ret_type(Retangulo R);
// seta x do retangulo
void set_ret_x(Retangulo R, double x);
// seta y do retangulo
void set_ret_y(Retangulo R, double y);
// seta altura do retangulo
void set_ret_alt(Retangulo R, double alt);
// seta largura do retangulo
void set_ret_larg(Retangulo R, double larg);
// seta cor do preenchimento do retangulo
void set_ret_corp(Retangulo R, char* corp);
// seta cor da borda do retangulo
void set_ret_corb(Retangulo R, char* corb);
// retorna a rotaçao do retangulo
double get_ret_rot(Retangulo T);
// seta rotaçao do retangulo
void set_ret_rot(Retangulo R, double rot);
//seta se tera bordas pontilhadas
void set_ret_dasharray(Retangulo R, double array);
//retorna as bordas pontilhadas
double get_ret_dasharray(Retangulo R);
//seta novo ID
void set_ret_ID(Retangulo R, int ID);

#endif