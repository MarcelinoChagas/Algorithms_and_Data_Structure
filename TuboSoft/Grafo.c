#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

struct grafo{
    int ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};
