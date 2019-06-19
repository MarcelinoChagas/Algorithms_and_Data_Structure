#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
  int ponderado;        // 1-Ponderado 0-Nao e ponderado
  int nro_vertices;     // Numero de vertices do grafo
  int grau_max;         // Numero MAX de arestas incidentes no Vertice
  int **arestas;        // Matrix de Aresta que Liga os Grafos
  float** pesos;        // Peso do Grafo
  int* grau;              // Numero de arestas do grafo
  struct pessoa *ps;  // Referencia Struct de pessoas
}Grafo;

typedef struct pessoa{
  char nome_cidade[40];
  int populacao;
}Pessoa;

Grafo *cria_grafo(int nro_vertices, int grau_max, int ponderado){

  Grafo *gr = (Grafo *) malloc(sizeof(struct grafo));

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
    }
    return gr;
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){

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

    if(gr-> ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;

    gr->grau[orig]++;

    // Para nao duplicar caminho de Arestas
    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i = 0; i<gr -> nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->ponderado){
            for(i = 0; i < gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

void imprimir_Grafo(Grafo *gr){
   for(int i = 0; gr->nro_vertices > i; i++){
        printf("\n");
        for(int j = 0; gr->nro_vertices > j; j++){
            printf("\t%.2f",gr->pesos[i][j]);
        }
   }
}


int main(void) {
    Grafo *gr;

    gr = cria_grafo(5,2,1);
    insereAresta(gr,1,2,1,10);
    insereAresta(gr,2,3,0,20);
    insereAresta(gr,4,1,0,30);

    imprimir_Grafo(gr);


    return 0;
}
