#include <stdio.h>
#include "balao2.h"
#include <math.h>
#include <string.h>

typedef struct car{

    int camera_atual;
    char type;
    int ID;
    Fila camera[10];//balao teram 10 cameras com capacidade de 15 fotos cada
    double raio,profundidade,altura;//sao setados no .qry
    Texto figura;

}_balao;

void killBalao(Balao B){
    _balao* aux = (_balao*) B;
    for(int i=0;i++;i<10)free(get_Camera(aux,i));
    free(aux);
}

Balao set_Balao(Texto figura){
    _balao* aux = malloc(sizeof(_balao));

    for(int i=0;i<10;i++)aux->camera[i] = createQueue();
    aux->type = 'B';
    aux->ID = get_text_ID(figura);
    aux->raio = 0;
    aux->profundidade = 0;
    aux->altura = 0;
    aux->figura = figura;
    aux->camera_atual = 0;

    return (Balao)aux;
}

void set_balao_prof(Balao B, double prof){
    _balao* aux = (_balao*)B;
    aux->profundidade = prof;
}

void set_balao_alt(Balao B, double alt){
    _balao* aux = (_balao*)B;
    aux->altura = alt;
}

void set_balao_raio(Balao B, double raio){
    _balao* aux = (_balao*)B;
    aux->raio = raio;
}

Texto get_balao_forma(Balao B){
    _balao* aux = (_balao*) B;
    return aux->figura;
}

char get_balao_type(Balao B){
    _balao* aux = (_balao*)B;
    return aux->type;
}

double get_balao_prof(Balao B){
    _balao* aux = (_balao*) B;
    return aux->profundidade;
}

double get_balao_alt(Balao B){
    _balao* aux = (_balao*) B;
    return aux->altura;
}

double get_balao_raio(Balao B){
    _balao* aux = (_balao*) B;
    return aux->raio;
}

Fila get_Camera(Balao B, int num){
    if(num>9){
        printf(" ESSE BALAO SO POSSUI 10 CAMERAS\n");
        return NULL;
    }    
    else{
        _balao* aux = (_balao*) B;
        return aux->camera[num];
    }
}

int insert_foto(Balao B,int num, data foto){
    int camera_atual = num;
    if(!isQueueFull(get_Camera(B,camera_atual))){

        insertQueue(get_Camera(B,camera_atual), foto);
    }
    else {
        camera_atual ++;
        insertQueue(get_Camera(B,camera_atual), foto);
    }

    return camera_atual;
}

Lista get_foto(Balao B, int num){
    Fila C = get_Camera(B,num);
    Lista L = (Lista)getDataQueue(C);
    return L;
}

double revela_foto(ArqSvg svg,int camera,Balao B){
    Lista foto = get_foto(B,camera);
    fold(foto,escreveGeralSvg,svg);
    return avalia(foto);
}

int get_camera_atual(Balao B){
    _balao* aux = (_balao*)B;
    return aux->camera_atual;
}

void set_camera_atual(Balao B, int num){
    _balao* aux = (_balao*)B;
    aux->camera_atual = num;
}

int get_balao_ID(Balao B){
    _balao* aux = (_balao*) B;
    return aux->ID;
}

double avalia(Lista foto){
    double Nota = 0;
    Iterador K = createIterator(foto,false);
    while(!isIteratorEmpty(foto,K)){//RODA AS FIGURAS DA FOTO (LISTA) E AVALIA ELA
        Forma figura = getIteratorNext(foto,K);
        if(get_ID(figura) >= 0){
            if(get_type(figura) == 'L'){
                double comp = sqrt(pow((get_lin_x1(figura)-get_lin_x2(figura)),2) + pow((get_lin_y1(figura)-get_lin_y2(figura)),2));
                if(strcmp(get_lin_corp(figura), "#FFFF00") == 0) Nota += 3 * comp;//ENERGIA ALTA POTENCIA
                else if(strcmp(get_lin_corp(figura), "#DDFF55") == 0)Nota += 2 * comp;//ENERGIA BAIXA POTENCIA
                else if(strcmp(get_lin_corp(figura), "#0000FF") == 0)Nota += 4 * comp;//DADOS
                else Nota += comp;
            }
            else if(get_type(figura) == 'C'){
                double MeiaArea = (3.14159265359 * pow(get_circ_r(figura),2))/2;
                if(strcmp(get_circ_corb(figura),"#FFFFFF")==0 && strcmp(get_circ_corp(figura),"#FFFF00")==0)Nota += 8 * MeiaArea;//PLANTA NUCLEAR
                else if(strcmp(get_circ_corb(figura),"#D45500")==0 && strcmp(get_circ_corp(figura),"#FF7F2A")==0)Nota += 2 * MeiaArea;//PREDIO PUBLICO
                else if(strcmp(get_circ_corb(figura),"#AA0000")==0 && strcmp(get_circ_corp(figura),"#DE8787")==0)Nota += 4 * MeiaArea;//HOSPITAL
                else if(strcmp(get_circ_corb(figura),"#FFFFFF")==0 && strcmp(get_circ_corp(figura),"#B3B3B3")==0)Nota += 0 * MeiaArea;//IGNORAR
                else Nota += MeiaArea;
            }
            else if(get_type(figura) == 'R'){
                double QuartoArea = (get_ret_alt(figura) * get_ret_larg(figura))/4;
                Nota += QuartoArea;
                if(strcmp(get_ret_corb(figura),"#80080") == 0)Nota += 10;
                else if(strcmp(get_ret_corb(figura),"#AA0088") == 0)Nota += 15;
                else Nota += QuartoArea;
                if(strcmp(get_ret_corp(figura),"#008033") == 0)Nota += 20;
                else if(strcmp(get_ret_corp(figura),"#FFCC00") == 0)Nota += 30;
            }
            else if(get_type(figura) == 'T'){
                if(strcmp(get_text_texto(figura),"|-T-|") == 0 )Nota += 100;
                else Nota += strlen(get_text_texto(figura));
            }
        }
    }
    return Nota;
}

bool isBaloon(Forma forma){
    if(get_type(forma) == 'T' && strcmp(get_text_texto(forma),"v_O_v") == 0)return true;
    else return false;
}