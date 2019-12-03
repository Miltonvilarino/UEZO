#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

static int qntMin = 0;

typedef struct _item
{
int conta; //contador
char *termo; //palavra
} Item;

typedef struct _mapa
{
int total; // número de itens no mapa
int blocos; // número de blocos de itens alocados
Item **lista; // vetor de ponteiros para itens
} Mapa;

void inicia_mapa (); //inicia um mapa vazio
void insere_termo (Mapa *mp, char *s); // insere um item com termo s e conta=1
int incrementa (Mapa *mp, char *s); // incrementa contador do termo s, retorna 1

// se não encontrou o termo
int escreve_cont (Mapa *mp, char *s, int c); // escreve  ́'c` no contador do termo s,
// retorna 1 se não encontrou o termo
int le_contador (Mapa *mp, char *s); // retorna contador do termo s
void remove_termo (Mapa *mp, char *s); // remove o item com termo s
void libera_mapa (Mapa * mp); // libera o espaço ocupado pelo mapa
int tamanho_mapa (Mapa * mp); // retorna número de itens no mapa
void le_termo (Mapa * mp, int i, char *t, int *c); //retorna em ‘t’ o termo no índice  ́i ́
void ranquear_mapa (Mapa *mp);
char ler_arquivo(char p);
int menu();



