#ifndef GRAFO_H
#define GRAFO_H
#include "Vertice.h"
#include <vector>
#include <algorithm>

using namespace std;

class Grafo
{
public:
    Grafo(){};

    vector<Vertice*> getVertices()
    {
        return vertices;
    }

    void add(unsigned int pos){
        if(vertices.size() < pos){
            Vertice* v = new Vertice();
            v->setPeso(v->calculaPeso(pos));
            v->setId(pos);
            v->setGrau(0);
            vertices.push_back(v);
        }
    }

    void add_adj(int pos, int* incidente){
        vertices[pos-1]->add_adjacente(incidente);
        vertices[pos-1]->setGrau(vertices[pos-1]->getGrau()+1);
    }

private:
    vector<Vertice*> vertices;
};

#endif // GRAFO_H
