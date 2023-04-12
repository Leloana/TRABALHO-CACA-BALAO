#include "Circulo.h"
#include <string.h>

typedef struct circ{ 

    char type;
    int ID;
    double cx, cy,raio, rotacao;
    char* cor, *corbord;

}circ;
//CRIA void* CIRCULO
void killCirc(Circulo C){
    circ* aux = (circ*) C;
    free(aux->cor);
    free(aux->corbord);
    free(aux);
}

Circulo criaCirc(int id,double cx, double cy, double r,char* corb,char* corp){
    circ* aux = malloc(sizeof(circ));
    aux->ID = id;
    aux->cx = cx;
    aux->cy = cy;
    aux->raio = r;
    aux->cor = calloc(strlen(corp)+1,sizeof(char));
    strcpy(aux->cor,corp);
    aux->corbord = calloc(strlen(corb)+1,sizeof(char));
    strcpy(aux->corbord,corb);
    aux->type = 'C';
    aux->rotacao = 0.0;

    return (Circulo)aux;
}

int get_circ_ID(Circulo C){
    circ* aux = (circ*) C;
    return aux->ID;
}

double get_circ_cx(Circulo C){
    circ* aux = (circ*) C;
    return aux->cx;
}

double get_circ_cy(Circulo C){
    circ* aux = (circ*) C;
    return aux->cy;
}

double get_circ_r(Circulo C){
    circ* aux = (circ*) C;
    return aux->raio;
}

char* get_circ_corb(Circulo C){
    circ* aux = (circ*) C;
    return aux->corbord;
}

char* get_circ_corp(Circulo C){
    circ* aux = (circ*) C;
    return aux->cor;
}

char get_circ_type(Circulo C){
    circ*aux = (circ*) C;
    return aux->type;
}

void set_circ_cx(Circulo C,double cx){
    circ* aux = (circ*) C;
    aux->cx = cx;
}

void set_circ_cy(Circulo C,double cy){
    circ* aux = (circ*) C;
    aux->cy = cy;
}

void set_circ_raio(Circulo C,double raio){
    circ* aux = (circ*) C;
    aux->raio = raio;
}

void set_circ_corp(Circulo C,char* corp){
    circ* aux = (circ*) C;
    aux->cor = corp;
}

void set_circ_corb(Circulo C,char* corb){
    circ* aux = (circ*) C;
    aux->corbord = corb;
}

void set_circ_rot(Circulo C,double rot){
    circ* aux = (circ*) C;
    aux->rotacao = rot;
}

double get_circ_rot(Circulo C){
    circ* aux = (circ*) C;
    return aux->rotacao;
}

void set_circ_ID(Circulo C,int ID){
    circ* aux = (circ*) C;
    aux->ID = ID;
}