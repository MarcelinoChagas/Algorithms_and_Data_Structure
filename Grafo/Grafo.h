#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct grafo Grafo;

Grafo *cria_Grafo (int nro_vertices, int grau_max, int eh_ponderado);

void libera_Grafo(Grafo* gr);

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);

void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado);

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado);

void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist);

void imprimir_Grafo(Grafo *gr);

#endif // GRAFO_H_INCLUDED
