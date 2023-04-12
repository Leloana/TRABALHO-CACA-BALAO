#include "Retangulo.h"
#include <string.h>

typedef struct rect{

    char type;
    int ID;
    double x, y, larg, alt, rotacao,dasharray;
    char* cor, *corbord;
    
}ret;

void killRet(Retangulo R){
    ret* aux = (ret*) R;
    free(aux->cor);
    free(aux->corbord);
    free(aux);
}
//CRIA void* RETANGULO
Retangulo criaRect(int id,double x, double y, double larg, double alt,char* corb,char* corp){
    ret* aux = calloc(1,sizeof(ret));
    aux->ID = id;
    aux->x = x;
    aux->y = y;
    aux->larg = larg;
    aux->alt = alt;
    aux->cor = calloc(strlen(corp)+1,sizeof(char));
    strcpy(aux->cor,corp);
    aux->corbord = calloc(strlen(corb)+1,sizeof(char));
    strcpy(aux->corbord,corb);
    aux->type = 'R';
    aux->rotacao = 0;
    aux->dasharray = 0;

    return (Retangulo)aux;
}

int get_ret_ID(Retangulo R){
    ret* aux = (ret*) R;
    return aux->ID;
}

double get_ret_x(Retangulo R){
    ret* aux = (ret*) R;
    return aux->x;
}

double get_ret_y(Retangulo R){
    ret* aux = (ret*) R;
    return aux->y;
}

double get_ret_larg(Retangulo R){
    ret* aux = (ret*) R;
    return aux->larg;
}

double get_ret_alt(Retangulo R){
    ret* aux = (ret*) R;
    return aux->alt;
}

char* get_ret_corb(Retangulo R){
    ret* aux = (ret*) R;
    return aux->corbord;
}

double get_ret_rot(Retangulo T){
    ret* aux = (ret*) T;
    return aux->rotacao;
}

char* get_ret_corp(Retangulo R){
    ret* aux = (ret*) R;
    return aux->cor;
}

char get_ret_type(Retangulo R){
    ret*aux = (ret*) R;
    return aux->type;
}

void set_ret_x(Retangulo R, double x){
    ret* aux = (ret*) R;
    aux->x = x;
}

void set_ret_y(Retangulo R, double y){
    ret* aux = (ret*) R;
    aux->y = y;
}

void set_ret_alt(Retangulo R, double alt){
    ret* aux = (ret*) R;
    aux->alt = alt;
}

void set_ret_larg(Retangulo R, double larg){
    ret* aux = (ret*) R;
    aux->larg = larg;
}

void set_ret_corp(Retangulo R, char* corp){
    ret* aux = (ret*) R;
    aux->cor = corp;
}

void set_ret_corb(Retangulo R, char* corb){
    ret* aux = (ret*) R;
    aux->corbord = corb;
}

void set_ret_rot(Retangulo R, double rot){
    ret* aux = (ret*) R;
    aux->rotacao = rot;
}

void set_ret_dasharray(Retangulo R, double array){
    ret* aux = (ret*) R;
    aux->dasharray = array;
}

double get_ret_dasharray(Retangulo R){
    ret* aux = (ret*) R;
    return aux->dasharray;
}

void set_ret_ID(Retangulo R, int ID){
    ret* aux = (ret*) R;
    aux->ID = ID;
}