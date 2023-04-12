#ifndef FORMAS_H
#define FORMAS_H

typedef void* Forma;
//'T' = texto, 'C' = circulo, 'R' = retangulo, 'L' = linha, 'B' = Balao, 'S' = Caca
char get_type(void* point);
// move a forma para (x+dx:y+dy)
void mvForma(Forma forma, double dx, double dy);
// retorna o id da forma generalizada
int get_ID(void* forma);
// retorna a cor do preenchimento da forma generalizada
char* get_corp(Forma forma);
// retorna a cor da borda da forma generalizada
char* get_corb(Forma forma);
// retorna o x da forma generalizada
double get_x(Forma forma);
// retorna o y da forma generalizada
double get_y(Forma forma);
//seta o x da forma generalizada
void set_x(Forma forma, double x);
//seta cor da borda da forma generalizada
void set_corb(Forma forma, char* corb);
//seta cor do preenchimento da forma generalizada
void set_corp(Forma forma, char* corp);
//seta o ID da forma generalizada
void set_ID(Forma forma, int ID);
//seta coordenada y da ancora da forma
void set_y(Forma forma, double y);
//Elimina forma
void killForma(void* forma);

#endif