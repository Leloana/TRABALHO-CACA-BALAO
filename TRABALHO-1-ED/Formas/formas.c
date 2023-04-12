#include "formas.h"
#include "Circulo.h"
#include "Retangulo.h"
#include "Texto.h"
#include "Linha.h"
#include "balao2.h"
#include "caca.h"

char get_type(void* point){

    char circulo = get_circ_type(point);
    char retangulo = get_ret_type(point);
    char linha = get_lin_type(point);
    char texto = get_text_type(point);
    char balao = get_balao_type(point);
    char caca = get_caca_type(point);

    if(circulo == 'C')return circulo;
    else if(retangulo == 'R')return retangulo;
    else if(linha == 'L')return linha;
    else if(texto == 'T')return texto;
    else if(caca == 'S')return caca;
    else if(balao == 'B')return balao;
    else return 'W';//nao é forma conhecida
}

int get_ID(void* forma){
    if(get_type(forma) == 'C')return get_circ_ID(forma);
    else if(get_type(forma) == 'R')return get_ret_ID(forma);
    else if(get_type(forma) == 'L')return get_lin_ID(forma);
    else if(get_type(forma) == 'T')return get_text_ID(forma);
    else if(get_type(forma) == 'B')return get_balao_ID(forma);
    else if(get_type(forma) == 'S')return get_caca_ID(forma);
    else return -999;//ID nao encontrado
 }

void set_ID(Forma forma, int ID){
    if(get_type(forma) == 'C')set_circ_ID(forma,ID);
    else if(get_type(forma) == 'R')set_ret_ID(forma,ID);
    else if(get_type(forma) == 'L')set_lin_ID(forma,ID);
    else if(get_type(forma) == 'T')set_text_ID(forma,ID);
}

void mvForma(Forma forma, double dx, double dy){

    if(get_type(forma) == 'C'){
        set_circ_cx(forma, (get_circ_cx(forma) + dx));
        set_circ_cy(forma, (get_circ_cy(forma) + dy));
    }

    else if(get_type(forma) == 'R'){
        set_ret_x(forma, (get_ret_x(forma) + dx));
        set_ret_y(forma, (get_ret_y(forma) + dy));
    }

    else if(get_type(forma) == 'L'){
        set_lin_x1(forma, (get_lin_x1(forma) + dx));
        set_lin_x2(forma, (get_lin_x2(forma) + dx));
        set_lin_y1(forma, (get_lin_y2(forma) + dy));
        set_lin_y2(forma, (get_lin_y2(forma) + dy));
    }

    else if(get_type(forma) == 'T'){
        set_text_x(forma, (get_text_x(forma) + dx));
        set_text_y(forma, (get_text_y(forma) + dy));
    }
    
}

char* get_corp(Forma forma){
    if(get_type(forma) == 'C')return get_circ_corp(forma);
    else if(get_type(forma) == 'R')return  get_ret_corp(forma);
    else if(get_type(forma) == 'L')return  get_lin_corp(forma);
    else if(get_type(forma) == 'T')return get_text_corp(forma);
    else return "none";//cor nao encontrada
}

void set_corp(Forma forma, char* corp){
    if(get_type(forma) == 'C')set_circ_corp(forma,corp);
    else if(get_type(forma) == 'R')set_ret_corp(forma,corp);
    else if(get_type(forma) == 'L')set_lin_cor(forma,corp);
    else if(get_type(forma) == 'T')set_text_cor(forma,corp);
}

char* get_corb(Forma forma){
    if(get_type(forma) == 'C')return get_circ_corb(forma);
    else if(get_type(forma) == 'R')return  get_ret_corb(forma);
    else if(get_type(forma) == 'L')return  0;
    else if(get_type(forma) == 'T')return get_text_corb(forma);
    else return "none";//cor nao encontrada
}

void set_corb(Forma forma, char* corb){
    if(get_type(forma) == 'C')set_circ_corb(forma,corb);
    else if(get_type(forma) == 'R')set_ret_corb(forma,corb);
    else if(get_type(forma) == 'L')set_lin_cor(forma,corb);
    else if(get_type(forma) == 'T')set_text_cor(forma,corb);
}

double get_x(Forma forma){
    if(get_type(forma) == 'C')return get_circ_cx(forma);
    else if(get_type(forma) == 'R')return  get_ret_x(forma);
    else if(get_type(forma) == 'L')return  get_lin_x1(forma);
    else if(get_type(forma) == 'T')return get_text_x(forma);
    else return -999;//valor nao encontrado
}

void set_x(Forma forma, double x){
     if(get_type(forma) == 'C')set_circ_cx(forma,x);
    else if(get_type(forma) == 'R')set_ret_x(forma,x);
    else if(get_type(forma) == 'T')set_text_x(forma,x);
}

void set_y(Forma forma, double y){
     if(get_type(forma) == 'C')set_circ_cy(forma,y);
    else if(get_type(forma) == 'R')set_ret_y(forma,y);
    else if(get_type(forma) == 'T')set_text_y(forma,y);
}

double get_y(Forma forma){
    if(get_type(forma) == 'C')return get_circ_cy(forma);
    else if(get_type(forma) == 'R')return  get_ret_y(forma);
    else if(get_type(forma) == 'L')return  get_lin_y1(forma);
    else if(get_type(forma) == 'T')return get_text_y(forma);
    else return -999;//valor nao encontrado
}

void killForma(void* forma){
    if(get_type(forma) == 'C')killCirc(forma);
    else if(get_type(forma) == 'R')killRet(forma);
    else if(get_type(forma) == 'L')killLinha(forma);
    else if(get_type(forma) == 'T')killTexto(forma);
    else if(get_type(forma) == 'B')killBalao(forma);
    else if(get_type(forma) == 'S')killCaca(forma);
}
