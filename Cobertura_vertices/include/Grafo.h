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

    vector<Vertice*> cloneVert(){
        vector<Vertice*> aux;
        vector<Vertice*> nos = getVertices();
        aux.reserve(nos.size());

        for(unsigned int i = 0; i < nos.size(); i++){

            Vertice* v = new Vertice();
            v->setGrau(nos[i]->getGrau());
            v->setId(nos[i]->getId());
            v->setPeso(nos[i]->getPeso());
            v->setAdjacents(nos[i]->getAdjacents());
            aux.push_back(v);
        }
        return aux;
    }

private:
    vector<Vertice*> vertices;
};

#endif // GRAFO_H
