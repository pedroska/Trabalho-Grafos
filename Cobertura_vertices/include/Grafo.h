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

    void add_adj(int pos, int* incidente){
        vertices[pos-1]->add_adjacente(incidente);
        vertices[pos-1]->setGrau(vertices[pos-1]->getGrau()+1);
    }

    void inicializaVertice(int tamanho){
        for(int i = 0; i < tamanho; i++){
            Vertice* v = new Vertice();
            v->setPeso(v->calculaPeso(i+1));
            v->setId(i+1);
            v->setGrau(0);
            vertices.push_back(v);
        }
    }

private:
    vector<Vertice*> vertices;
};

#endif // GRAFO_H
