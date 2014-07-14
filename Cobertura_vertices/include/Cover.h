#ifndef PLS_H_INCLUDED
#define PLS_H_INCLUDED
#include "Heuristica.h"
#include "Grafo.h"
#include "util.h"
#include <vector>

using namespace std;

class Cover
{

public:
    vector<Vertice*> coberturaVertice(Grafo* grafo, int heuristica)
    {
        vector<Vertice*> solucao;

        //ordernar de acordo com a heuristica passada como parâmetro;
        Heuristica* h = new Heuristica(heuristica);

        //capturar um elemento do vetor;
        //--> Gulosa:
        //A função checaVetor, basicamente analisa se o critério de parada foi satisifeito, ou seja, os graus estão zerados;
        while(!checaVetor(grafo->getVertices()))
        {
            h->mergeSort(grafo->getVertices(), 0, grafo->getVertices().size(), heuristica);
            //captura um vértice e adiciona no conjunto solução
            solucao.push_back(getVertexRandom(grafo));
        }
        cout<<solucao.size()<<" peso: "<<calculaPeso(solucao)<<endl;

        //--> Gulosa Randomizada (10x cada):
        //Esta função captura os vértices com base na constante alfa pertencente ao conjunto {0.1,0.2,0.3,0.5}, e analisa no vetor a porcentagem dos primeiros elementos do vetor de acordo com o alfa.

        while(!checaVetor(grafo->getVertices()))
        {
            solucao.push_back(getVertexRandom(grafo,0.1));
        }
        cout<<solucao.size()<<" peso: "<<calculaPeso(solucao)<<endl;

        while(!checaVetor(grafo->getVertices()))
        {
            solucao.push_back(getVertexRandom(grafo,0.2));
        }
        cout<<solucao.size()<<" peso: "<<calculaPeso(solucao)<<endl;

        while(!checaVetor(grafo->getVertices()))
        {
            solucao.push_back(getVertexRandom(grafo,0.3));
        }
        cout<<solucao.size()<<" peso: "<<calculaPeso(solucao)<<endl;

        while(!checaVetor(grafo->getVertices()))
        {
            solucao.push_back(getVertexRandom(grafo,0.5));
        }
        cout<<solucao.size()<<" peso: "<<calculaPeso(solucao)<<endl;

        //--> Gulosa Randomizada Reativa
        //Nesta função é testado um vetor de alfa para todas as possibilidades, e conforme o algoritmo é processado são atribuídas probabilidades aos alfas para todos serem utilizados igualmente, além disso, são acumuladas as soluções a fim de analisar os melhores alfas encontrados.
        vector<float> alpha;
        for(float a = 0.1; a < 1.0 ; a = a + 0.1)
        {
            alpha.push_back(a);
        }
        int m = alpha.size();
        vector<float> probabilidade;
        for(int i=0; i<m; i++)
        {
            probabilidade.push_back(1/m);
        }
        vector<int> resultados;
        for(int j=0; j<m; j++)
        {
            resultados.push_back(0);
        }
        vector<int> contador_alpha;
        for(int j=0; j<m; j++)
        {
            contador_alpha.push_back(0);
        }

        while(!checaVetor(grafo->getVertices()))
        {
            int posicao = intRandom(alpha.size());
            float a = alpha[posicao];
            solucao.push_back(getVertexRandom(grafo, a));
            contador_alpha[posicao]++;
            atualiza_probabilidades();
            atualiza_resultados(solucao.size(), posicao, calculaPeso(solucao));
        }

        return solucao;
    }

    Vertice* getVertexRandom(Grafo* grafo)
    {
        //retirar esse elemento do grafo e inserir no conjunto solução E diminuir os graus da lista adj do mesmo
        Vertice* v = new Vertice();
        v = grafo->getVertices()[0];

        //diminui o Grau de todos os vértices adjacentes ao vértice escolhido

        for(unsigned int i=0; i < v->getAdjacents().size(); i++)
        {

            grafo->getVertices()[(v->getAdjacents()[i]-1)]->setGrau(grafo->getVertices()[(v->getAdjacents()[i]-1)]->getGrau()-1);

            //Caso o grau de algum dos vértices seja zerado, então iremos remover ele do conjunto solução;

            if(grafo->getVertices()[(v->getAdjacents()[i]-1)]->getGrau() == 0)
            {
                for ( vector<Vertice*>::iterator it= grafo->getVertices().begin(); it != grafo->getVertices().end();)
                {
                    if(*it == grafo->getVertices()[(v->getAdjacents()[i]-1)])
                    {
                        grafo->getVertices().erase(it);
                    }
                    else
                    {
                        ++it;
                    }
                }
            }
        }

        grafo->getVertices().erase(grafo->getVertices().begin());
        return v;
    }

    Vertice* getVertexRandom(Grafo* grafo, float alfa)
    {
        //retirar esse elemento do grafo e inserir no conjunto solução E diminuir os graus da lista adj do mesmo
        Vertice* v = new Vertice();

        //a posição no vetor será dada de acordo com o tamanho do vetor vezes a porcentagem do alfa, então iremos capturar entre esses valores.

        int posicao = intRandom(grafo->getVertices().size() * alfa);
        v = grafo->getVertices()[posicao];

        //diminui o Grau de todos os vértices adjacentes ao vértice escolhido

        for(unsigned int i=0; i < v->getAdjacents().size(); i++)
        {

            grafo->getVertices()[(v->getAdjacents()[i]-1)]->setGrau(grafo->getVertices()[(v->getAdjacents()[i]-1)]->getGrau()-1);

            //Caso o grau de algum dos vértices seja zerado, então iremos remover ele do conjunto solução;

            if(grafo->getVertices()[(v->getAdjacents()[i]-1)]->getGrau() == 0)
            {
                for ( vector<Vertice*>::iterator it= grafo->getVertices().begin(); it != grafo->getVertices().end();)
                {
                    if(*it == grafo->getVertices()[(v->getAdjacents()[i]-1)])
                    {
                        grafo->getVertices().erase(it);
                    }
                    else
                    {
                        ++it;
                    }
                }
            }
        }

        grafo->getVertices().erase(grafo->getVertices().begin()+posicao);
        return v;
    }

    bool checaVetor(vector<Vertice*> vetor)
    {
        if(vetor.empty())
        {
            return true;
        }
        return false;
    }

    void atualiza_probabilidades()
    {
        //atualiza as probabilidades para os alfas serem escolhidos
        return;
    }

    void atualiza_resultados(int resultado, int posicao, int peso)
    {
        //atualiza a posicao do vetor de resultados com o acrescimo do novo resultado encontrado
        return;
    }

    int calculaPeso(vector<Vertice*> sol){
        int peso = 0;
        for(unsigned int i = 0; i < sol.size() ; i++){
            peso = sol[i]->getPeso();
        }
        return peso;
    }

private:

    vector<Vertice*> vertexCover;
};

#endif // PLS_H_INCLUDED
