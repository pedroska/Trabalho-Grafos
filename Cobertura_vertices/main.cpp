#include <iostream>
#include "include/Grafo.h"
//#include "include/Vertice.h"
#include "include/Leitor.h"

using namespace std;

//int main(char* argv[])
int main()
{
    Leitor *leitor = new Leitor();
    Grafo *grafo = new Grafo();

    //char arquivo[] = "/ice/Downloads/Trabalho-Grafos-master/Cobertura_vertices/database/brock200_2.mis";
    char arquivo[] = "C:\\Users\\Pedro\\Documents\\GitHub\\Trabalho-Grafos\\Cobertura_vertices\\database\\brock200_2.mis";



    leitor->lerArquivo(arquivo, grafo);

    //delete grafo;


    return 0;
}
