#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct grafo Grafo;

Grafo *cria_Grafo (int nro_vertices, int grau_max, int ponderado);

void libera_Grafo(Grafo* gr);

int insereCidade(Grafo * gr);

int insereAresta(Grafo* gr, int orig, int dest, float peso);

int removeAresta(Grafo *gr, int orig, int dest);

void imprimir_Cidade(Grafo *gr);

void imprimir_Grafo(Grafo *gr);

void menu_principal();

void limpaTela();



#endif // GRAFO_H_INCLUDED
