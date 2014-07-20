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

    float getGrau()
    {
        return grau;
    }

    int getId()
    {
        return id;
    }

    void setPeso(int value)
    {
        peso = value;
    }
    void setGrau(float value)
    {
        grau = value;
    }
    void setId(int value)
    {
        id = value;
    }

    vector<int> getAdjacents(){
        return adjacents;
    }

    void setAdjacents(vector<int> adj){
         adjacents = adj;
    }

    void add_adjacente(int* value)
    {
        adjacents.push_back(*value);
    }

    float calculaPeso(int value)
    {
        return (value%200)+1;
    }

protected:
private:
    float grau;
    int peso;
    int id;
    vector<int> adjacents;
};

#endif // VERTICE_H
