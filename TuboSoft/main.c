#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main()
{
    Grafo *gr;

    gr = cria_Grafo(3,2,1);

    menu_principal();

    /*insereCidade(gr);

    insereAresta(gr,0,1,10);
    insereAresta(gr,1,2,20);
    insereAresta(gr,2,0,40);

   // imprimir_Cidade(gr);

    imprimir_Grafo(gr);

    //removeAresta(gr,0,1);
    libera_Grafo(gr);

    imprimir_Grafo(gr);
*/
    return 0;
}
