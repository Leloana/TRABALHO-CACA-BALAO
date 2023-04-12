#ifndef BALAO_H
#define BALAO_H

typedef void* Balao;
#include "Texto.h"
#include "../Estruturas/fila.h"
#include "../Estruturas/list.h"
#include "../Leituras/arqsvg.h"

void killBalao(Balao B);
// seta o raio,profundidade e altura da camera
Balao set_Balao(Texto figura);
//seta a profundidade da camera do balao
void set_balao_prof(Balao B, double prof);
//seta a altura da camera do balao
void set_balao_alt(Balao B, double alt);
//seta o raio da camera do balao
void set_balao_raio(Balao B, double raio);
// retorna a profundidade da camera do balao
double get_balao_prof(Balao B);
// retorna a altura da camera do balao
double get_balao_alt(Balao B);
// retorna o raio da camera do balao
double get_balao_raio(Balao B);
// retorna a camera numero "num"(0-9) do balao
Fila get_Camera(Balao B, int num);
//insere foto retornando a camera em que ela foi inserida
int insert_foto(Balao B,int num, data foto);
//retorna a primeira foto da camera num
Lista get_foto(Balao B, int num);
//retorna o tipo do balao 'B'
char get_balao_type(Balao B);
//retorna o texto que compoe o balao
Texto get_balao_forma(Balao B);
// REVELA A FOTO RETORNANDO SUA PONTUAÇAO
double revela_foto(ArqSvg svg,int camera,Balao B);
//retorna a camera atual do balao
int get_camera_atual(Balao B);
//escolhe a camera atual do balao
void set_camera_atual(Balao B, int num);
//retorna o ID do balao
int get_balao_ID(Balao B);
//avalia a foto do balao
double avalia(Lista foto);
//retorna verdadeiro se a forma inserida for um balao
bool isBaloon(Forma forma);

#endif