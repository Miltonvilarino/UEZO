#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "mapa.h"
#include <string.h>



void inicia_mapa(Mapa *mp){ //inicia um mapa vazio

    mp->total = 0;
    mp->blocos++;
    mp->lista = (Item **) malloc((mp->blocos * 10) * sizeof(Item*));

        if (mp->lista == NULL)
        {
            printf("Não foi possível alocar os Itens\n");
            return;
        }
}


void insere_termo (Mapa *mp, char *s){ // insere um item com termo s e conta=1
int c;

    if(mp->total >= (mp->blocos * 10)){
        mp->blocos++;
        mp->lista = (Item **) realloc(mp->lista, (mp->blocos * 10) * sizeof(Item*));

    }

    mp->lista[mp->total] = (Item*) malloc(sizeof(Item));
    mp->lista[mp->total]->termo = (char*) malloc(strlen(s) * sizeof(char));
    strlwr(s);
    if(incrementa(mp, s) == 1){
        return;
    } else{

    for(c = 0; c <= strlen(s); c++){
        mp->lista[mp->total]->termo[c] = s[c];



    }
    mp->lista[mp->total]->conta = 1;
    mp->total++;
        }
    ranquear_mapa(mp);

}

int incrementa (Mapa *mp, char *s){ // incrementa contador do termo s, retorna 1
int c;

     for(c = 0; c < mp->total; c++){
            if (s[strlen(s)-1] == '.')
            s[strlen(s)-1] = '\0';
            if((strcmp(s, mp->lista[c]->termo)) == 0){
                mp->lista[c]->conta++;
                return 1;
            }else  if (s[strlen(s)-1] == ',')
            s[strlen(s)-1] = '\0';
            if((strcmp(s, mp->lista[c]->termo)) == 0){
                mp->lista[c]->conta++;
                return 1;
            }else  if (s[strlen(s)-1] == '!')
            s[strlen(s)-1] = '\0';
            if((strcmp(s, mp->lista[c]->termo)) == 0){
                mp->lista[c]->conta++;
                return 1;
            }else  if (s[strlen(s)-1] == '?')
            s[strlen(s)-1] = '\0';
            if((strcmp(s, mp->lista[c]->termo)) == 0){
                mp->lista[c]->conta++;
                return 1;
            }else  if (s[strlen(s)-1] == '"')
            s[strlen(s)-1] = '\0';
            if((strcmp(s, mp->lista[c]->termo)) == 0){
                mp->lista[c]->conta++;
                return 1;
            }

    }
    return 0;
}

// se não encontrou o termo
int escreve_cont (Mapa *mp, char *s, int c){ // escreve  ́c` no contador do termo s,
        for(c = 0; c < mp->total; c++){
            if((strcmp(s, mp->lista[c]->termo)) == 0){
                mp->lista[c]->conta = c;
                return 1;
            }
        }
    return 0;
}

int le_contador (Mapa *mp, char *s){  // retorna contador do termo s
int c;
    for(c = 0; c < mp->total; c++){
        if((strcmp(s, mp->lista[c]->termo)) == 0){
                return mp->lista[c]->conta;
        }
    }


}

void remove_termo (Mapa *mp, char *s){ // remove o item com termo s
int c, j;
        for(c = 0; c < mp->total; c++){
            if((strcmp(s, mp->lista[c]->termo)) == 0){
                for(j = c; j < mp->total; j++){
                    mp->lista[j]=mp->lista[j+1];
                }
             mp->total--;
            }
        }


}

void ranquear_mapa (Mapa *mp){
int i, j;
Item *apoio;
    for (i = 0; i < mp->total; i++){
        for(j = 0; j < mp->total; j++){
            if ((mp->lista[i]->conta) > (mp->lista[j]->conta)){
                apoio = mp->lista[i];
                mp->lista[i] = mp->lista[j];
                mp->lista[j] = apoio;
            }
        }
    }

}

void libera_mapa (Mapa * mp){  // libera o espaço ocupado pelo mapa
    free(mp);
}

int tamanho_mapa (Mapa * mp){ // retorna número de itens no mapa
    printf("\nExistem %i palavras nesse texto\n", mp->total);

}

void le_termo (Mapa * mp, int i, char *t, int *c){ //retorna em ‘t’ o termo no índice  ́i ́
    t = mp->lista[i-1]->termo;
    printf("Palavra: %s \nQuantidade:%ix\n", t, mp->lista[i-1]->conta);

}

int menu(){
    int i;
    printf("\n-Bem vindo ao Ranking de Palavras-\n");
    printf("MENU:\n 1 - Ler arquivo txt\n 2 - Exibir Ranking completo\n 3 - Exibir intervalo de Ranking\n 4 - Buscar palavra\n 5 - Opcoes\n 6 - Sair\n");
    printf("Qual opcao?\n");
    scanf("%i", &i);
    return i;

}




