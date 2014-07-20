#include <iostream>
#include "include/Grafo.h"
#include "include/Leitor.h"
#include "Cover.h"
#include "util.h"

using namespace std;

int main()
{
    Leitor *leitor = new Leitor();
    Grafo *grafo = new Grafo();

    char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/teste.mis";
    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/brock800_2.mis";
    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb30-15-1.mis";
    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb35-17-2.mis";

    leitor->lerArquivo(arquivo, grafo);

    Cover *cover = new Cover();
    //Heuristica *h = new Heuristica(3);
/*
    while(!cover->checaVetor(myvector)){
        myvector = h->mergeSort(myvector,2);
        myvector[0]->setGrau(0.001);
        cover->imprime(myvector);
    }*/

    cover->coberturaVertice(grafo,1);
    cover->coberturaVertice(grafo,2);

    return 0;
}
