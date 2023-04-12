#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Leituras/arqsvg.h"
#include "../Leituras/Leituras.h"
#include "../Estruturas/list.h"
#include "../Estruturas/fila.h"

int main(){
    // char* Path_Entrada, *Path_Saida, *nomeGeo, *nomeQry;

    //  for (int i = 0; i < argc; i++){
    //     if (strcmp(argv[i], "-e") == 0){
    //     if(argv[strlen(argv)-1] != '/')argv[strlen(argv)-1] = '/';
    //      Path_Entrada = argv[i + 1];
        
    //     }
    //     else if (strcmp(argv[i], "-o") == 0){
    //      if(argv[strlen(argv)-1] != '/')argv[strlen(argv)-1] = '/';
    //      Path_Saida = argv[i + 1];
    //      Path_Entrada = argv[i + 1];
    //    }
    //     else if (strcmp(argv[i], "-f") == 0)nomeGeo = argv[i + 1];
    //     else if (strcmp(argv[i], "-q") == 0)nomeQry = argv[i + 1];
    // }

    ArqSvg Arq = abreEscritaSvg("testes.svg");
    FILE* geo = fopen("texto.geo","r");
    FILE* qry = fopen("texto.qry", "r");
    FILE* txt = fopen("relatorio.txt","w");
    Lista total = createLst(-1);
    
    LerGeo(geo,total);
    LerQry(qry,txt,total);
    fclose(geo);
    fclose(qry);
    fclose(txt);
    fold(total,escreveGeralSvg,Arq);
    Executa_ListaFormas(total);

    fechaSvg(Arq);

    return 0;
}

