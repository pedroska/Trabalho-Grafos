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
        vector<Vertice*> grafo_vert  = grafo->cloneVert();
        vector<Vertice*> grafo_vert2;
        vector<Vertice*> grafo_vert3;

       /* grafo->getVertices()[0]->setGrau(0.001);

        imprime(grafo->getVertices());
        imprime(grafo_vert);
        imprime(grafo_vert2);

        grafo_vert[3]->setGrau(0.001);
        cout<<"=============================================="<<endl;
        imprime(grafo->getVertices());
        imprime(grafo_vert);
        imprime(grafo_vert2);

        return grafo_vert2;*/


        //ordernar de acordo com a heuristica passada como parâmetro;
        Heuristica* h = new Heuristica(heuristica);

        //capturar um elemento do vetor;
        //--> Gulosa:
        //A função checaVetor, basicamente analisa se o critério de parada foi satisifeito, ou seja, os graus estão zerados;
        while(!checaVetor(grafo_vert))
        {
            grafo_vert = h->mergeSort(grafo_vert, heuristica);
            //captura um vértice e adiciona no conjunto solução
            solucao.push_back(getVertexRandom(grafo_vert));
        }
        cout<<"============================================="<<endl;
        cout<<"Guloso: "<<endl;
        cout<<"Tamanho: "<<solucao.size()<<" peso: "<<calculaPeso(solucao)<<endl;

        //--> Gulosa Randomizada (10x cada):
        //Esta função captura os vértices com base na constante alfa pertencente ao conjunto {0.1,0.2,0.3,0.5}, e analisa no vetor a porcentagem dos primeiros elementos do vetor de acordo com o alfa.

        cout<<"============================================="<<endl;
        cout<<"Randomizado: "<<endl;
        cout<<endl;
        float alfa[4] = {0.1,0.2,0.3,0.5};
        for(unsigned int w = 0; w < 4 ; w++){
            //for(){ rodar 10x para cada alfa
                grafo_vert2 = grafo->cloneVert();
                maximo_vet = grafo_vert2.size();
                solucao.erase(solucao.begin(), solucao.end());
                while(!checaVetor(grafo_vert2))
                {
                    grafo_vert2 = h->mergeSort(grafo_vert2, heuristica);
                    //captura um vértice e adiciona no conjunto solução
                    solucao.push_back(getVertexRandom(grafo_vert2, alfa[w]));
                }
                //imprime(solucao);
                cout<<"Tamanho: "<<solucao.size()<<" peso: "<<calculaPeso(solucao)<<endl;
        }

        //Randomizado Reativo
        cout<<"============================================="<<endl;
        cout<<"Randomizado Reativo: "<<endl;
        cout<<endl;

        float alfaReactive[9] = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
        //float prob[9] = {1/9,1/9,1/9,1/9,1/9,1/9,1/9,1/9,1/9};
        float solutionSize[9] = {0,0,0,0,0,0,0,0,0};
        float solutionPeso[9] = {0,0,0,0,0,0,0,0,0};
        float iterations[9] = {0,0,0,0,0,0,0,0,0};

        for(unsigned int e = 0; e < 9 ; e++){
            //laço para iterar cada alfa 5 vezes
            for(unsigned int a = 0; a < 5 ; a++){
                grafo_vert3 = grafo->cloneVert();
                maximo_vet = grafo_vert3.size();
                solucao.erase(solucao.begin(), solucao.end());
                while(!checaVetor(grafo_vert3))
                {
                    grafo_vert3 = h->mergeSort(grafo_vert3, heuristica);
                    //captura um vértice e adiciona no conjunto solução
                    solucao.push_back(getVertexRandom(grafo_vert3, alfaReactive[e]));
                }
                solutionSize[e] += solucao.size();
                iterations[e] += 1;
                solutionPeso[e] += calculaPeso(solucao);
            }
            int tamanho = solutionSize[e] / iterations[e];
            int peso = solutionPeso[e] / iterations[e];

            cout<<"Tamanho: "<<tamanho<<" peso: "<<peso<<endl;
        }

        return solucao;
    }

    Vertice* getVertexRandom(vector<Vertice*> &grafo_vert)
    {
        //retirar esse elemento do grafo e inserir no conjunto solução E diminuir os graus da lista adj do mesmo
        Vertice* v = new Vertice();
        v = grafo_vert[0];

        //diminui o Grau de todos os vértices adjacentes ao vértice escolhido

        for(unsigned int i=0; i < v->getAdjacents().size(); i++)
        {
            for(unsigned int q = 0; q < grafo_vert.size(); q++){
                if(v->getAdjacents()[i] == grafo_vert[q]->getId()){

                    grafo_vert[q]->setGrau( grafo_vert[q]->getGrau() - 1);
                    //Caso o grau de algum dos vértices seja zerado, então iremos remover ele do conjunto solução;
                    if(grafo_vert[q]->getGrau() < 1)
                    {
                        grafo_vert[q]->setGrau(0.001);
                    }
                }
            }
        }

        grafo_vert[0]->setGrau(0.001);
        return v;
    }

    Vertice* getVertexRandom(vector<Vertice*> &grafo_vert, float alfa)
    {
       //retirar esse elemento do grafo e inserir no conjunto solução E diminuir os graus da lista adj do mesmo
        Vertice* v = new Vertice();
        //a posição no vetor será dada de acordo com o tamanho do vetor vezes a porcentagem do alfa, então iremos capturar entre esses valores.

        int posicao = xrandomRange(0 , getRange(grafo_vert) * alfa);
        v = grafo_vert[posicao];

        //diminui o Grau de todos os vértices adjacentes ao vértice escolhido

        for(unsigned int i=0; i < v->getAdjacents().size(); i++)
        {
            for(unsigned int q = 0; q < grafo_vert.size(); q++){
                if(v->getAdjacents()[i] == grafo_vert[q]->getId()){

                    if(grafo_vert[q]->getGrau() >= 1){
                        grafo_vert[q]->setGrau( grafo_vert[q]->getGrau() - 1);
                        //Caso o grau de algum dos vértices seja zerado, então iremos remover ele do conjunto solução;
                        if(grafo_vert[q]->getGrau() < 1)
                        {
                            grafo_vert[q]->setGrau(0.001);
                            maximo_vet--;
                        }
                    }
                }
            }
        }

        grafo_vert[posicao]->setGrau(0.001);
        maximo_vet--;
        return v;
    }

    bool checaVetor(vector<Vertice*> &vetor)
    {
        for(unsigned int i=0; i<vetor.size();i++){
            if(vetor[i]->getGrau() >= 1){
                return false;
            }
        }
        return true;
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
            peso += sol[i]->getPeso();
        }
        return peso;
    }

    int getRange(vector<Vertice*> grafo_vert){
        for (unsigned int k = 0; k < grafo_vert.size(); k++){
                //cout<<k<<" grau: "<<grafo_vert[k]->getGrau()<<endl;
            if(grafo_vert[k]->getGrau() < 1.0){
                return k;
            }
        }
        return grafo_vert.size();
    }

    void imprime(vector<Vertice*> vetor){
        for(unsigned int u = 0; u < vetor.size(); u++){
            cout<<"posição vetor: "<<u<<endl;
            cout<<"Peso: "<<vetor[u]->getPeso()<<endl;
            cout<<"Grau: "<<vetor[u]->getGrau()<<endl;
            cout<<"ID: "<<vetor[u]->getId()<<endl;
            cout<<"--------------------------"<<endl;
        }
    }



private:
    int maximo_vet;
    vector<Vertice*> vertexCover;
};

#endif // PLS_H_INCLUDED
