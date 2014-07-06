#include <iostream>
#include "include/Grafo.h"
//#include "include/Vertice.h"
#include "include/Leitor.h"
#include "PLS.h"

using namespace std;

//int main(char* argv[])
int main()
{
    Leitor *leitor = new Leitor();
    Grafo *grafo = new Grafo();

    char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/brock800_2.mis";

    leitor->lerArquivo(arquivo, grafo);

    for (unsigned int i=0; i<grafo->getVertices().size(); i++){
        //tam = tam + grafo->getVertices()[i]->getAdjacentes().size();
        cout<<grafo->getVertices()[i]->getAdjacentes().size()<<endl;
    }

    //delete grafo;


    return 0;
}
