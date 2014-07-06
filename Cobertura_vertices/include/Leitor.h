#ifndef LEITOR_H_INCLUDED
#define LEITOR_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "StringUtils.h"

using namespace std;

class Leitor
{

private:
    int numeroArestas;
    int linhaAtual;

protected:

public:

    Leitor()
    {
        linhaAtual = 1;
    }

    void processaLinha(string str, Grafo *grafo)
    {
        if(linhaAtual == 1)
        {
            //vector<string> s = StringUtils::split(str, ' ');
            //int tam = atoi(s[s.size()-2].c_str());
            return;
        }


        vector<string> s = StringUtils::split(str, ' ');

        int no = atoi(s[s.size()-2].c_str());
        int incidente = atoi(s[s.size()-1].c_str());

        grafo->add(no);
        grafo->add_adj(no, &incidente);

        //grafo->add_no(no, &incidente);
        //grafo->add_no(no);


        //grafo->getVertices()[no-1].add_adjacente(&incidente);
        //&Grafo.getVertices()[no-1]).add_adjacente(incidente);
    }


    void lerArquivo(char arquivo[], Grafo *grafo)
    {
        ifstream file(arquivo);
        string str;
        string file_contents;
        linhaAtual = 1;

        while (getline(file, str))
        {
            processaLinha(str,grafo);
            linhaAtual++;
        }
    }
};

#endif // LEITOR_H_INCLUDED
