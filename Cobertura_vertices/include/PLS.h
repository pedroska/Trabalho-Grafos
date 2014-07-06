#ifndef PLS_H_INCLUDED
#define PLS_H_INCLUDED
#include "Heuristica.h"
#include "Grafo.h"
#include <vector>

using namespace std;

class PLS
{

public:
    vector<Vertice*> algoritmoPLS(Grafo* grafo, unsigned int ts, unsigned int maxselect){
        unsigned int selection = 0;
        unsigned int sa = 0; //random() ?
        unsigned int iterations = 50;



        //Captura um elemento aleatório do grafo
        Vertice* v = getVertexRandom(grafo);
        vertexCover.push_back(v);
        //zeraPenalidades();  --> ajuse dos pesos ou penalidades próprias?
        do{
            do{
                while(true){
                    //v = selectRand();    --> recebe um aleatorio do C0(K)
                    vertexCover.push_back(v);
                    selection = selection + 1;
                    if(vertexCover.size() == ts){     // ou peso vo vertexCover == ts
                          return vertexCover;
                    }
                    //U recebe vazio
                }
                if(true){
                    //v = selectRand();    --> recebe um aleatorio do C1(K) \ U
                    //vertexCover.push_back( xxxx );
                    selection = selection + 1;
                }
            }while(!true);
            iterations = iterations - 1;
            //UpdatePenalties(sa);
            //Perturb(sa);
        }while(selection >= maxselect);

    }
    //Abordagem Gulosa
    Vertice* getVertexRandom(Grafo* grafo){
        Heuristica* h = new Heuristica();
        setHeuristica(1);

        h->mergeSort(grafo->getVertices(), 0, grafo->getVertices().size(), heuristica);
        Vertice* v = grafo->getVertices()[0];
        grafo->getVertices().erase(grafo->getVertices().begin());
        return v;
    }

    //Abordagem Gulosa Randomizada
    Vertice* getVertexRandom(Grafo* grafo, float alfa){
        Heuristica* h = new Heuristica();
        setHeuristica(1);

        h->mergeSort(grafo->getVertices(), 0, grafo->getVertices().size(), heuristica);

        int range = grafo->getVertices().size() * alfa;
        int random = rand(); //range
        Vertice* v = grafo->getVertices()[random];
        grafo->getVertices().erase(grafo->getVertices().begin());
        return v;
    }

    //Abordagem Gulosa Randomizada Reativa

    void setHeuristica(int heuristica){
        heuristica = heuristica;
    }

    int getHeuristica(){
        return heuristica;
    }
private:
    int heuristica;
    vector<Vertice*> vertexCover;

};

#endif // PLS_H_INCLUDED
