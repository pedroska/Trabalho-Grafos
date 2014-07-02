#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include "Vertice.h"

using namespace std;

class Grafo
{
    public:

        Grafo()
        {

        }
        virtual ~Grafo();

        Vertice* getVertices()
        {
            return vertices;
        }

        void iniciaVertices(int n)
        {
            vertices = new Vertice[n];
        }

        void add_no(int pos, Vertice* v)
        {
            vertices[pos] = *v;
        }

    protected:
    private:
        Vertice* vertices;
};

#endif // GRAFO_H
