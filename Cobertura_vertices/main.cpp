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

    //Bases de dados ---->

    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/teste.mis";

    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb30-15-1.mis";
    char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb30-15-2.mis";
    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb30-15-3.mis";

    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb35-17-1.mis";
    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb35-17-2.mis";
    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb35-17-3.mis";

    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb40-19-1.mis";
    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb40-19-2.mis";

    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb45-21-1.mis";

    //char arquivo[] = "/home/pedro/Documentos/Faculdade/Trabalho-Grafos/Cobertura_vertices/database/frb50-23-1.mis";

    leitor->lerArquivo(arquivo, grafo);

    Cover *cover = new Cover();

    cout<<"Heuristica 1: "<<endl;
    cout<<"================"<<endl;
    cover->coberturaVertice(grafo,1);

    cout<<"Heuristica 2: "<<endl;
    cout<<"================"<<endl;
    cover->coberturaVertice(grafo,2);

    return 0;
}
