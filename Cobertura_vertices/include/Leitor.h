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
            return;
        }

        vector<string> s = StringUtils::split(str, ' ');

        int no = atoi(s[s.size()-2].c_str());
        int incidente = atoi(s[s.size()-1].c_str());

        grafo->add_no(no, &incidente);
        //&Grafo.getVertices()[no-1]).add_adjacente(incidente);


        /*if (linhaAtual > 1 && linhaAtual < 1 + numeroArestas){

            vector<string> s = StringUtils::split(str, ' ');

            int incidente = atoi(s[s.size()-1].c_str());
            int no = atoi(s[s.size()-2].c_str());

            if( &grafo->getVertices()[no] == NULL)
            {
                Vertice *vertice = new Vertice();
                grafo->add_no(no , vertice);
            }

            grafo->getVertices()[no].add_adjacente(&incidente);

            grafo->getVertices()[no].setGrau(grafo->getVertices()[no].getGrau() + 1);
            grafo->getVertices()[no].setPeso(grafo->getVertices()[no].calculaPeso());
        }*/
    }


    void lerArquivo(char arquivo[], Grafo *grafo)
    {
        cout<<arquivo;

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
