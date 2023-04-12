#ifndef TEX_H
#define TEX_H
#include <stdio.h>
#include <stdlib.h>
#include "formas.h"

typedef void* Texto;

void killTexto(Texto T);
//cria void* com objeto texto
Texto criaTexto(int id,double x, double y, char* corb,char* corp,char* ancora, char* tex);
// retorna id do texto
int get_text_ID(Texto T);
// retorna x do texto
double get_text_x(Texto T);
// retorna y do texto
double get_text_y(Texto T);
// retorna cor da borda do texto
char* get_text_corb(Texto T);
// retorna cor do preenchimento do texto
char* get_text_corp(Texto T);
// retorna o texto que sera impresso pela forma
char* get_text_texto(Texto T);
// retorna a ancora do texto
char* get_text_ancora(Texto T);
// retorna o tipo do texto 'R'
char get_text_type(Texto T);
// seta o x do texto
void set_text_x(Texto T, double x);
// seta o y do texto
void set_text_y(Texto T, double y);
// set a acor da borda do texto
void set_text_corb(Texto T, char* corb);
// set a cor do preenchimento do texto
void set_text_cor(Texto T, char* cor);
// seta a rotaçao do texto
void set_text_rot(Texto T, double rot);
// retorna a rotaçao do texto
double get_text_rot(Texto T);
// seta ancora do texto
void set_text_ancora(Texto T, char* ancora);
//seta ID do texto
void set_text_ID(Texto T, int ID);
//seta fonte, espessura e tamanho do texto
void set_text_Style(Texto T, char* familia, char* espessura,char* tam);
//retorna a fonte do texto
char* get_text_Family(Texto T);
//retorna o tipo do texto
char* get_text_Weight(Texto T);
//retorna o tamanho do texto
char* get_text_Size(Texto T);
//retorna o char da ancora para ser usado em clones
char* get_text_charAnc(Texto T);

#endif