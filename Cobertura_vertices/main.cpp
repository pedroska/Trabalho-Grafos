#include <iostream>
#include "include/Grafo.h"
#include "include/Leitor.h"
#include "Cover.h"

using namespace std;

int main()
{
    Leitor *leitor = new Leitor();
    Grafo *grafo = new Grafo();

    char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/teste.mis";

    leitor->lerArquivo(arquivo, grafo);

    Cover *cover = new Cover();
    cover->coberturaVertice(grafo,2);

    return 0;
}
