#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo *cria_Grafo (int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr=(Grafo *) malloc(sizeof(struct grafo));

    if(gr != NULL){
        int i;
        // Atribui os valores a Struct
        gr -> nro_vertices = nro_vertices;
        gr -> grau_max = grau_max;
        //  Faz verificacao de Verdadeiro ou Falso
        gr -> eh_ponderado = (eh_ponderado != 0) ? 1 : 0;
        //  Criar um vetor de tamanho dinâmico e iniciando com 0
        gr -> grau = (int *) calloc(nro_vertices, sizeof(int));
        gr -> arestas = (int **) malloc(nro_vertices*sizeof(int*));
        for( i = 0; i < nro_vertices; i++)
            gr -> arestas[i] = (int*)malloc(grau_max*sizeof(int));
            if(gr-> eh_ponderado){
                gr -> pesos = (float **)malloc(nro_vertices*sizeof(float*));
                for(i = 0; i < nro_vertices; i++)
                    gr -> pesos[i] = (float*)malloc(grau_max*sizeof(float));
            }
    }
    return gr;
}
