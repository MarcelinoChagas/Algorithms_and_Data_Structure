#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main()
{
    Grafo *gr;
    gr = cria_Grafo(10, 7, 0);
    insereAresta(gr, 0, 1, 0, 0);
    insereAresta(gr, 1, 3, 0, 0);
    removeAresta(gr, 0, 1, 0);

    libera_Grafo(gr);
    imprimir_Grafo(gr);

    system("pause");
    return 0;
}
