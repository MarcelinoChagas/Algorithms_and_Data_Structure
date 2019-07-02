#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main()
{
    Grafo *gr;

    gr = cria_Grafo(3,2,1);

    insereCidade(gr);

    insereAresta(gr,0,2,10);
    insereAresta(gr,1,2,20);
    insereAresta(gr,2,1,40);

    imprimir_Grafo(gr);

    libera_Grafo(gr);

    imprimir_Grafo(gr);

    return 0;
}
