#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
  int ponderado;    // 1-Ponderado 0-Nao e ponderado
  int nro_vertices; // Numero de vertices do grafo
  int grau_max;     // Numero MAX de arestas incidentes no Vertice
  int **arestas;    // Matrix de Aresta que Liga os Grafos
  float** pesos;    // Peso do Grafo
  int* grau;        // Numero de arestas do grafo
  struct pessoa *ps; // Referencia Struct de pessoas
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

Pessoa *cidade(char nome, int populacao){

}
int main(void) {
  int qtd_grafo[10][10];

  printf("Hello World\n");
  return 0;
}
