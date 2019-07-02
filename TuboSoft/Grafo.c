#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#define TAM 3
#include <windows.h>

typedef struct grafo{
  int ponderado;             // 1-Ponderado 0-Nao e ponderado
  int nro_vertices;          // Numero de vertices do grafo
  int grau_max;              // Numero MAX de arestas incidentes no Vertice
  int **arestas;             // Matrix de Aresta que Liga os Grafos
  float** pesos;             // Peso do Grafo
  int* grau;                   // Numero de arestas do grafo
  struct cidade *cid ;

}Grafo;


struct cidade{
    char nome[40];
    int populacao;
};


Grafo *cria_Grafo(int nro_vertices, int grau_max, int ponderado){

  Grafo *gr = (Grafo *) malloc(sizeof(struct grafo));
//  Cidade *cid = (Cidade *) malloc(sizeof(struct cidade));

  if(gr != NULL){

    int i;

    // Atribui os valores a struct
    gr -> nro_vertices = nro_vertices;
    gr -> grau_max = grau_max;

    // Verifica se e ponderado ou nao
    gr -> ponderado = (ponderado != 0)? 1:0;

    // Cria um vetor de tamanho dinamico e iniciando com 0 o grau do Grafo
    gr -> grau = (int *) calloc(nro_vertices, sizeof(int));

    // Cria uma matriz de Arestas (Inicio e Fim)
    gr -> arestas = (int **) malloc(nro_vertices*sizeof(int*));

      for( i = 0; i < nro_vertices; i++)
        gr -> arestas[i] = (int*)malloc(grau_max*sizeof(int));

       if(gr-> ponderado){
        gr -> pesos = (float **)malloc(nro_vertices*sizeof(float*));
            for(i = 0; i < nro_vertices; i++)
                gr -> pesos[i] = (float*)malloc(grau_max*sizeof(float));
       }

       gr->cid= (struct cidade *)malloc(sizeof(struct cidade));


 //   struct cidade *cidade = malloc(gr->nro_vertices * sizeof(struct cidade));
    }
    return gr;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i = 0; i<gr -> nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->ponderado){
            for(i = 0; i < gr->nro_vertices; i++){
                free(gr->pesos[i]);
                free(gr->cid[i].nome);
                free(gr->cid[i].populacao);
            }
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
    printf("\n\nGrafo Liberado\n\n");
}

int insereAresta(Grafo* gr, int orig, int dest, float peso){
    int cont;

    // Verifica se o Grafo e Nulo
    if(gr == NULL)
        return 0;

    // Verifica se a origem do Vertice e maior que o nro de arestas
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;

     // Verifica se o destino do Vertice e maior que o nro de arestas
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;

    if(gr-> ponderado){
      gr->pesos[orig][gr->grau[orig]] = peso;
      cont ++;
    }

    gr->grau[orig]++;

    if(cont == 1)
        insereAresta(gr,dest,orig,peso);

    return 1;
}

int insereCidade(Grafo * gr){

    if(gr == NULL)
        return 0;

    for(int i = 0; i < gr->nro_vertices; i++){
        printf("Digite o nome da Cidade: ");
        scanf("%s",&gr->cid[i].nome);

        printf("\nDigite a populacao da Cidade: ",i);
        scanf("%d",&gr->cid[i].populacao);

        system("cls");
    }

    return 1;
}

void imprimir_Grafo(Grafo *gr){

    if(gr == NULL)
        printf("Vazio!!");
        return;

   for(int i = 0; gr->nro_vertices > i; i++){
        printf("Origem %s - %d:", gr->cid[i].nome, i);
        for(int j = 0; gr->grau[i] > j; j++){
            if(gr->ponderado){
                int aux = gr->arestas[i][j];
                printf("\tDestino %s - %d (%.2f) , ",gr->cid[aux].nome, gr->arestas[i][j], gr->pesos[i][j]);
            }
            else
                printf("%d, ",gr->arestas[i][j]);
        }
        printf("\n");
   }
}

