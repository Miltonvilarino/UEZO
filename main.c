#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "mapa.h"
#include <string.h>


void main()
{
setlocale(LC_ALL,"");


FILE *arq;
char *result;
int *pibuscaPalavra;
int indice, xMenu, c, c2, c3, minIntervalo, maxIntervalo, indPalavra, qntMin, totalMin = 0;
char text[500], q[20], *palavra, nomeArq[100];
char *pcbuscaPalavra;
Mapa *mapa = (Mapa*) malloc(sizeof(Mapa));

    inicia_mapa(mapa);

    while(1){
        xMenu = menu();
           if (xMenu == 1){
            free(mapa);
            mapa = (Mapa*) malloc(sizeof(Mapa));
            inicia_mapa(mapa);
            printf("Qual nome do arquivo que deseja carregar?\n");
            scanf("%s", nomeArq);
            arq = fopen(nomeArq, "rt");

            if (arq == NULL)    {
                printf("Não foi possível abrir o arquivo desejado\n");
                return;
            }

            while (!feof(arq))    {

                fscanf(arq, "%s", q);
                insere_termo(mapa, q);
            }
        ranquear_mapa(mapa);
            printf("Total de Palavras:%i\n", mapa->total);
            printf("Palavra:         Qntd:\n");
                for(indice = 0; indice < mapa->total; indice++){
                    printf("%i %s  ", indice+1, mapa->lista[indice]->termo);
                    printf("-        %ix\n", mapa->lista[indice]->conta);
                }
        } else if (xMenu == 2) {
            ranquear_mapa(mapa);
            printf("Total de Palavras:%i\n", mapa->total);
            printf("Palavra:         Qntd:\n");
                for(indice = 0; indice < mapa->total; indice++){
                    printf("%i %s  ", indice+1, mapa->lista[indice]->termo);
                    printf("-        %ix\n", mapa->lista[indice]->conta);
                }

        } else if (xMenu == 3) {
            printf("Digite qtd max:\n");
            scanf("%i", &maxIntervalo);
            printf("Digite qtd min:\n");
            scanf("%i", &minIntervalo);
                for(indice = 0; indice < mapa->total; indice++){
                        if(mapa->lista[indice]->conta >= minIntervalo && mapa->lista[indice]->conta <= maxIntervalo){
                        printf("%i %s  ", indice+1, mapa->lista[indice]->termo);
                        printf("-        %ix\n", mapa->lista[indice]->conta);
                        }
                }

        } else if (xMenu == 4) {
            printf("Qual palavra deseja buscar?\n");
            scanf("%s", &text);
            palavra = &text;
                for(c2 = 0; c2 < mapa->total; c2++){
                    if((strcmp(palavra, mapa->lista[c2]->termo)) == 0){
                    printf("Quantidade:%i\n", mapa->lista[c2]->conta);
                    }
                }

        } else if (xMenu == 5) {
            printf("Digite minimo de caracteres a considerar:\n");
            scanf("%i", &qntMin);
            totalMin = 0;
            for(c3 = 0; c3 < mapa->total; c3++){
                    if(strlen(mapa->lista[c3]->termo) < qntMin){
                    totalMin++;
                    }
            }
            printf("Total de Palavras: %i", totalMin);


            }
          else if (xMenu == 6){
                return;
          }
        fclose(arq);
        }


    }




