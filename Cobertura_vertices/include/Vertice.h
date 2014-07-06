#ifndef VERTICE_H
#define VERTICE_H
#include <vector>
#include <stdio.h>

using namespace std;

class Vertice
{
public:
    Vertice(){};

    int getPeso()
    {
        return peso;
    }

    int getGrau()
    {
        return grau;
    }

    int getId()
    {
        return id;
    }

    vector<int*> getAdjacentes()
    {
        return adjacentes;
    }

    void setPeso(int value)
    {
        peso = value;
    }
    void setGrau(int value)
    {
        grau = value;
    }
    void setId(int value)
    {
        id = value;
    }

    void add_adjacente(int* value)
    {
        adjacentes.push_back(value);
    }

    float calculaPeso(int value)
    {
        return (value%200)+1;
    }

protected:
private:
    int grau;
    int peso;
    int id;
    vector<int*> adjacentes;
};

#endif // VERTICE_H
