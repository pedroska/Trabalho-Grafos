#include <iostream>
#include "include/Grafo.h"
#include "include/Vertice.h"
#include "include/Leitor.h"
#include <string.h>


int main(char* argv[])
{
    Leitor *leitor = new Leitor();
    Grafo *grafo = new Grafo();

    //leitor->lerArquivo(argv[1],grafo);
    //char *arquivo = "C:\\Users\\Pedro\\Documents\\GitHub\\Trabalho-Grafos\\Cobertura_vertices\\database\\brock200_2.mis";
    leitor->lerArquivo(argv[1],grafo);

    cout<<grafo->getVertices();

    delete grafo;

    cout << "Hello world!" << endl;
    return 0;
}


