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

int procuraMenorDistancia(float *dist, int *visitado, int NV){
    int i, menor = -1, primeiro = 1;
    for(i = 0; i < NV; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;
    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    // Para não duplicar caminho de Arestas
    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;
    while(i < gr-> grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr ->grau[orig])
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];

    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr, dest, orig, 1);
    return 1;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i = 0; i<gr -> nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i = 0; i < gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado){
    int i, vert, NV, cont = 1, *fila, IF = 0, FF = 0;   //IF-Inicio Fila FF-Final Fila

    for(i = 0; i < gr->nro_vertices; i++)   // Marca vértices como
        visitado[i] = 0;                    // Não Visitados.

    NV = gr-> nro_vertices;                 // Numero de Vertices.
    fila = (int*) malloc(NV * sizeof(int)); // Cria fila. Visita
    FF++;                                   // e insere "ini" na fila.
    fila[FF] = ini;                         //
    visitado [ini] = cont;                  // Marca como Visitado

    while (IF != FF){          // Enquanto a fila
        IF = (IF + 1) % NV;    // não estiver vazia.
        vert = fila[IF];       // Pega o valor
        cont++;                // primeiro da fila.

        for(i = 0; i < gr->grau[vert]; i++){        // Visita os vizinhos
            if(!visitado[gr->arestas[vert][i]]){    // ainda nao visitados
                FF = (FF + 1) % NV;                 // e coloca na fila
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
}

void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist){
    int i, cont, NV, ind, *visitado, u;

    cont = NV = gr->nro_vertices;

    //Cria vetor auxiliar. Inicializa distancias e anteriores
    visitado = (int*) malloc(NV * sizeof(int));
    for(i = 0; i < NV; i++){
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }

    dist[ini] = 0;

    //Procura vertice com menor distancia e marca como visitado
    while(cont > 0){
        u = procuraMenorDistancia(dist,visitado,NV);
        if(u == -1)
            break;
        visitado[u] = 1;
        cont--;
    }
    free(visitado);

    for(i = 0; i < gr->grau[u]; i++){
        ind = gr->arestas[u][i];
        if(dist[ind] < 0){
            dist[ind] = dist[u] + 1;
            ant[ind] = u;
        }else{
            if(dist[ind] > dist[u] + 1){
                dist[ind] = dist[u] + 1;
                ant[ind] = u;
            }
        }
    }
}

void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado){
    int i, cont = 1;
    for(i = 0; i < gr->nro_vertices; i++)
        visitado[i] = 0;
    buscaProfundidade(gr, ini, visitado, cont);
}

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont){
    int i;
    visitado[ini] = cont;

    for(i = 0; i < gr-> grau[ini]; i++){
        if(!visitado[gr->arestas[ini][i]])
            buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont+1);
    }
}

void imprimir_Grafo(Grafo ** gr){

    if(gr == NULL){
        printf("Grafo esta Vazio!");
    }else{
        for(int i = 0; gr->nro_vertices > i;i++){
            for(int j = 0; gr->nro_vertices > j; j++){
                printf("\t%i ",gr[i][j]);
            }
        }
    }
}
