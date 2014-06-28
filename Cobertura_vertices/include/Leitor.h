#ifndef LEITOR_H_INCLUDED
#define LEITOR_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "../utils/StringUtils.h"

using namespace std;

class Leitor
{

private:
    int numeroNos;
    float alfa;
    int linhaAtual;

protected:

public:

    FileManager()
    {
        linhaAtual = 1;
    }

    void processaLinha(string str, Grafo *grafo)
    {

        if (linhaAtual== 1)
        {
            vector<string> s = StringUtils::split(str, ' ');
            numeroNos = atoi(s[s.size()-1].c_str());
            return;
        }

        if (linhaAtual== 2)
        {
            vector<string> s = StringUtils::split(str, ' ');
            alfa = atof(s[s.size()-1].c_str());
            return;
        }

        if (linhaAtual>5 &&  linhaAtual <= (5 + numeroNos))
        {

            vector<string> s = StringUtils::split(str, ' ');
            No *no = new No();
            stringstream ss;
            ss << linhaAtual - 5;
            no->setLabel(ss.str());
            no->setLatitude(atof(s[1].c_str()));
            no->setLongitude(atof(s[s.size()-7].c_str()));
            no->setEnergia(atof(s[s.size()-3].c_str()));

            grafo->adicionaNo(no);

            return;
        }



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

    };

#endif // LEITOR_H_INCLUDED
