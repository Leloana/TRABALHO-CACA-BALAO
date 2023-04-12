#include "Texto.h"
#include <string.h>

typedef struct text{
    
    char type;
    int ID;
    double x,y, rotacao;
    char* tex, *cor, *corbord,*ancora;
    char fFamily[50], fWeight[50], fSize[50];

}text;

void killTexto(Texto T){
    text* aux = (text*) T;
    free(aux->tex);
    free(aux->cor);
    free(aux->corbord);
    free(aux->ancora);
    free(aux);
}
//CRIA void* TEXTO
Texto criaTexto(int id,double x, double y, char* corb,char* corp,char* ancora, char* tex){
    text* aux = malloc(sizeof(text));
    aux->ID = id;
    aux->x = x;
    aux->y = y;
    aux->cor = calloc(strlen(corp)+1,sizeof(char));
    strcpy(aux->cor,corp);
    aux->corbord = calloc(strlen(corb)+1,sizeof(char));
    strcpy(aux->corbord,corb);
    aux->tex = calloc(strlen(tex)+1,sizeof(char));
    strcpy(aux->tex,tex);
    aux->type = 'T';
    aux->rotacao = 0;
    set_text_ancora(aux,ancora);
    strncpy(aux->fFamily,"sans (sans-serif)",50);
    strncpy(aux->fWeight,"normal",50);
    strncpy(aux->fSize,"16px",50);

    return (Texto)aux;
}

int get_text_ID(Texto T){
    text* aux = (text*) T;
    return aux->ID;
}

double get_text_x(Texto T){
    text* aux = (text*) T;
    return aux->x;
}

double get_text_y(Texto T){
    text* aux = (text*) T;
    return aux->y;
}

char* get_text_corb(Texto T){
    text* aux = (text*) T;
    return aux->corbord;
}

char* get_text_corp(Texto T){
    text* aux = (text*) T;
    return aux->cor;
}

char* get_text_texto(Texto T){
    text* aux = (text*) T;
    return aux->tex;
}

double get_text_rot(Texto T){
    text* aux = (text*) T;
    return aux->rotacao;
}

char* get_text_ancora(Texto T){
    text* aux = (text*) T;
    return aux->ancora;
}

char* get_text_charAnc(Texto T){
    text* aux = (text*) T;
    if(strcmp(aux->ancora,"middle")==0)return "m";
    else if(strcmp(aux->ancora,"end")==0)return "f";
    else if(strcmp(aux->ancora,"start")==0)return "i";
    else return NULL;
}

char get_text_type(Texto T){
    text*aux = (text*) T;
    return aux->type;
}

void set_text_x(Texto T, double x){
    text* aux = (text*) T;
    aux->x = x;
}

void set_text_y(Texto T, double y){
    text* aux = (text*) T;
    aux->y = y;
}

void set_text_corb(Texto T, char* corb){
    text* aux = (text*) T;
    aux->corbord = corb;
}

void set_text_cor(Texto T, char* cor){
    text* aux = (text*) T;
    aux->cor = cor;
}

void set_text_rot(Texto T, double rot){
    text* aux = (text*) T;
    aux->rotacao = rot;
}

void set_text_ancora(Texto T, char* ancora){
    text* aux = (text*) T;

    if(strcmp(ancora,"m")==0){
        aux->ancora = calloc(7,sizeof(char));
        strcpy(aux->ancora,"middle");
    }
    if(strcmp(ancora,"f")==0){
        aux->ancora = calloc(4,sizeof(char));
        strcpy(aux->ancora,"end");
    }
    if(strcmp(ancora,"i")==0){
        aux->ancora = calloc(6,sizeof(char));
        strcpy(aux->ancora,"start");
    }
    else return;
}

void set_text_ID(Texto T, int ID){
    text* aux = (text*) T;
    aux->ID = ID;
}

void set_text_Style(Texto T, char* familia, char* espessura,char* tam){
    text* aux = (text*) T;
    strncpy(aux->fFamily,familia,50);
    strncpy(aux->fWeight,espessura,50);
    strncpy(aux->fSize,tam,50);
}

char* get_text_Family(Texto T){
    text* aux = (text*) T;
    return aux->fFamily;
}

char* get_text_Weight(Texto T){
    text* aux = (text*) T;
    return aux->fWeight;
}

char* get_text_Size(Texto T){
    text* aux = (text*) T;
    return aux->fSize;
}