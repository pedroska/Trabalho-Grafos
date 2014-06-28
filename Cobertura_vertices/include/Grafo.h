#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include "Vertice.h"

using namespace std;

class Grafo
{
    public:
        Grafo(int n)
        {
            vertices.resize(n);
        }
        virtual ~Grafo();


    protected:
    private:
        vector<Vertice*> vertices;
};

#endif // GRAFO_H
