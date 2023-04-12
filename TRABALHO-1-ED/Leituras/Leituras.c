#include "Leituras.h"


char** LeituraLinha(FILE* arq){

	char palavras[100];
	fgets(palavras, 100, arq);
    int n = 0;
    char** tokens = calloc(30 ,sizeof(char*));
    
    char* token_atual = strtok(palavras, " ");
    while (token_atual != NULL ) {

        char* token_copia = calloc(strlen(token_atual) + 1,sizeof(char));
        strcpy(token_copia, token_atual);
        
        if(token_copia[strlen(token_copia)-1] == '\n')token_copia[strlen(token_copia)-1] = '\0';
        
        tokens[n] = token_copia;
        n++;
        token_atual = strtok(NULL, " ");	
    }
    free(token_atual);
	return tokens;
}

void LerGeo(FILE* geo,Lista geral){
    char family[50] = "sans (sans-serif)";
    char weight[50] = "normal";
    char size[50] = "16px";
    if(geo == NULL)printf(" ERRO AO ABRIR ARQUIVO GEO\n");
    else{
        char ** aux = calloc(8,sizeof(char*));
        while(!feof(geo)){    
            aux = LeituraLinha(geo);
            if(strcmp(aux[0],"l") == 0){
                Linha L = criaLinha(atoi(aux[1]),strtod(aux[2],NULL),strtod(aux[3],NULL),strtod(aux[4],NULL),strtod(aux[5],NULL), aux[6]);
                insertLst(geral,(Linha)L);
                for(int i = 0 ; i < 7;i++)free(aux[i]);
            }
            else if(strcmp(aux[0],"r") == 0){
                Retangulo R = criaRect(atoi(aux[1]),strtod(aux[2],NULL),strtod(aux[3],NULL),strtod(aux[4],NULL),strtod(aux[5],NULL),aux[6],aux[7]);
                insertLst(geral,(Retangulo)R);
                for(int i = 0 ; i < 8;i++)free(aux[i]);
            }
            else if(strcmp(aux[0],"c") == 0){
                Circulo C = criaCirc(atoi(aux[1]),strtod(aux[2],NULL),strtod(aux[3],NULL),strtod(aux[4],NULL),aux[5],aux[6]);
                insertLst(geral,(Circulo)C);
                for(int i = 0 ; i < 7;i++)free(aux[i]);
            }
            else if(strcmp(aux[0],"ts")==0){
                strncpy(family,aux[1],50);
                strncpy(weight,aux[2],50);
                strncpy(size,aux[3],50);
                for(int i = 0 ; i < 4;i++)free(aux[i]);
            }
            else if(strcmp(aux[0],"t") == 0){
                Texto T = criaTexto(atoi(aux[1]),strtod(aux[2],NULL),strtod(aux[3],NULL),aux[4],aux[5],aux[6], aux[7]);
                set_text_Style(T, family,weight,size);
                insertLst(geral, (Texto)T);
                for(int i = 0 ; i < 8;i++)free(aux[i]);
            }
		else break;
        }
        free(aux);
    }
}

void LerQry(FILE* qry,FILE* txt, Lista lista){
    Lista decoracoes = createLst(-1);
    if(qry == NULL)printf(" ERRO AO ABRIR ARQUIVO QRY\n");
    else{
        Lista provisoria_bal = filter(lista,isBaloon);
        Lista provisoria_caca = filter(lista,iscaca);
        Lista Baloes = map(provisoria_bal,set_Balao);
        Lista Cacas = map(provisoria_caca,set_caca);
        char ** aux = NULL;
        while(!feof(qry)){
            aux = LeituraLinha(qry);
            if(strcmp(aux[0], "mv") == 0){
                LinhaMove(txt,lista,atoi(aux[1]),strtod(aux[2],NULL),strtod(aux[3],NULL));
                for(int i = 0;i < 3;i++)free(aux[i]);
            }
            else if(strcmp(aux[0], "g") == 0){
                LinhaRotaciona(txt,lista,atoi(aux[1]),strtod(aux[2],NULL));
                for(int i = 0;i < 3;i++)free(aux[i]);
            }
            else if(strcmp(aux[0], "ff") == 0){
                FocoFoto(Baloes,atoi(aux[1]),strtod(aux[2],NULL),strtod(aux[3],NULL),strtod(aux[4],NULL));
                for(int i = 0;i < 5;i++)free(aux[i]);
            }
            else if(strcmp(aux[0], "tf") == 0){
                LinhaTiraFoto(txt,Baloes,lista,decoracoes,atoi(aux[1]),atoi(aux[2]));
                for(int i = 0;i < 3;i++)free(aux[i]);
            }
            else if(strcmp(aux[0], "df") == 0){
                ReportaFotos(txt,Baloes,atoi(aux[1]),aux[3],atoi(aux[2]));
                for(int i = 0;i < 3;i++)free(aux[i]);
            }
            else if(strcmp(aux[0], "d") == 0){
                DisparoCaca(txt,Baloes,Cacas,lista,decoracoes,atoi(aux[1]),aux[2],strtod(aux[3],NULL),atoi(aux[4]), strtod(aux[5],NULL));
                for(int i = 0;i < 6;i++)free(aux[i]);
            }
            else if(strcmp(aux[0], "b?") == 0){
                Report_Baloes(txt,Baloes);
                free(aux[0]);
            }
            else if(strcmp(aux[0], "c?") == 0){
                Report_Cacas(txt,Cacas);
                free(aux[0]);
            }
    free(aux);
    }
    if(!isEmptyLst(decoracoes)){
        ArqSvg deco = abreEscritaSvg("deco.svg");
        fold(decoracoes,escreveGeralSvg,deco);
        fechaSvg(deco);
        Executa_ListaFormas(decoracoes);
    }
    Executa_ListaFormas(Baloes);
    Executa_ListaFormas(Cacas);
    }
}
