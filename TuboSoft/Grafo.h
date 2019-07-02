#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct grafo Grafo;

Grafo *cria_Grafo (int nro_vertices, int grau_max, int ponderado);

void libera_Grafo(Grafo* gr);

int insereCidade(Grafo * gr);

int insereAresta(Grafo* gr, int orig, int dest, float peso);

void imprimir_Grafo(Grafo *gr);

#endif // GRAFO_H_INCLUDED
