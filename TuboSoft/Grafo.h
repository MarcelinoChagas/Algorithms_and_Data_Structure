#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct grafo Grafo;
typedef struct moradores Moradores;

Grafo *cria_Grafo (int nro_vertices, int grau_max, int ponderado, Moradores m);

#endif // GRAFO_H_INCLUDED
