#ifndef GRAFO_H
#define GRAFO_H
#include "Vertice.h"

using namespace std;

class Grafo
{
public:
    Grafo(){};

    Vertice* getVertices()
    {
        return vertices;
    }

    void iniciaVertices(int n)
    {
        vertices = new Vertice();//[n];
    }

    void add_no(int pos, int* value)
    {
        if(&vertices[pos-1] == NULL)
        {
                Vertice* v = new Vertice();
                v->setPeso(v->calculaPeso());
                v->setId(pos);
                v->setGrau(0);

                //vertices[pos-1] = *v;
                cout<<v<<endl;
        }


        //vertices[pos-1].add_adjacente(value);
        /*
         for(size_t i=0; i<vertices.size(); i++)
         {
            if(vertices[i]->id == pos){
                vertices[i]->add_adjacente(adjacente);
                return;
            }
         }*/
    }

private:
    Vertice* vertices;
};

#endif // GRAFO_H
