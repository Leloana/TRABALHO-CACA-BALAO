#include "Linha.h"
#include <string.h>

typedef struct line{

    char type;
    int ID;
    double x1, x2, y1, y2,rotacao;
    char *cor;

}lin;

void killLinha(Linha L){
    lin* aux = (lin*) L;
    free(aux->cor);
    free(aux);
}
//CRIA void* COM O OBJ LINHA
Linha criaLinha(int id,double x1, double y1, double x2, double y2, char* cor){
    lin* aux = malloc(sizeof(lin));
    aux->ID = id;
    aux->x1 = x1;
    aux->x2 = x2;
    aux->y1 = y1;
    aux->y2 = y2;
    aux->cor = calloc(strlen(cor)+1,sizeof(char));
    strcpy(aux->cor,cor);
    aux->type = 'L';
    aux->rotacao = 0;

    return (Linha)aux;
}

int get_lin_ID(Linha L){
    lin* aux = (lin*) L;
    return aux->ID;
}

double get_lin_x1(Linha L){
    lin* aux = (lin*) L;
    return aux->x1;
}

double get_lin_y1(Linha L){
    lin* aux = (lin*) L;
    return aux->y1;
}

double get_lin_x2(Linha L){
    lin* aux = (lin*) L;
    return aux->x2;
}

double get_lin_y2(Linha L){
    lin* aux = (lin*) L;
    return aux->y2;
}

char* get_lin_corp(Linha L){
    lin* aux = (lin*) L;
    return aux->cor;
}

double get_lin_rot(Linha L){
    lin*aux = (lin*) L;
    return aux->rotacao;
}

char get_lin_type(Linha L){
    lin*aux = (lin*) L;
    return aux->type;
}

void set_lin_x1(Linha L, double x1){
    lin* aux = (lin*) L;
    aux->x1 = x1;
}

void set_lin_x2(Linha L, double x2){
    lin* aux = (lin*) L;
    aux->x2 = x2;
}

void set_lin_y1(Linha L, double y1){
    lin* aux = (lin*) L;
    aux->y1 = y1;
}

void set_lin_y2(Linha L, double y2){
    lin* aux = (lin*) L;
    aux->y2 = y2;
}

void set_lin_cor(Linha L, char* cor){
    lin* aux = (lin*) L;
    aux->cor = cor;
}

void set_lin_rot(Linha L, double rot){
    lin* aux = (lin*) L;
    aux->rotacao = rot;
}

void set_lin_ID(Linha L, int ID){
    lin* aux = (lin*) L;
    aux->ID = ID;
}


