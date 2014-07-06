#ifndef HEURISTICA_H
#define HEURISTICA_H
#include <vector>
#include "Grafo.h"
#include "Vertice.h"

class Heuristica
{
    public:
        Heuristica(){};

        void mergeSort(vector<Vertice*> v, int inicio, int fim, int escolhaHeur)
        {
            if (inicio < fim-1)
            {
                int meio = (inicio+fim)/2;
                mergeSort(v, inicio, meio, escolhaHeur);
                mergeSort(v, meio, fim, escolhaHeur);
                merge(v, inicio, meio, fim, escolhaHeur);
            }
        }

        void merge(vector<Vertice*> v, int inicio, int meio, int fim, int escolhaHeur)
        {
           int i, j, k;
           vector<Vertice*> aux;
           aux.resize(fim-inicio);

           for (i = 0, k = inicio; k < meio; ++i, ++k) aux[i] = v[k];
           for (j = fim-inicio-1, k = meio; k < fim; --j, ++k) aux[j] = v[k];
           i = 0; j = fim-inicio-1;
           for (k = inicio; k < fim; ++k){
              if( escolhaHeuristica(aux[i], escolhaHeur) <= escolhaHeuristica(aux[j], escolhaHeur)) v[k] = aux[i++];
              else v[k] = aux[j--];
           }
           delete(&aux);
        }

        float escolhaHeuristica(Vertice *v, int escolha)
        {
            float x = 0;

            if(escolha == 1) x = v->getGrau();
            if(escolha == 2) x = v->getPeso() / v->getGrau();

            return x;
        }

    protected:
    private:
};

#endif // HEURISTICA_H
