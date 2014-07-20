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
            //Rodar 10 vezes para cada alfa
            for(int f = 0; f < 10; f++){
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
        }

        //Randomizado Reativo
        cout<<"============================================="<<endl;
        cout<<"Randomizado Reativo: "<<endl;
        cout<<endl;

        float bestPeso = 0;
        //float bestAlfa = 0;

        int tamanho;
        int peso;

        float alfaReactive[9] = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
        int prioritarios[3] = {0,1,2};
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

                float p = calculaPeso(solucao);

                solutionSize[e] += solucao.size();
                iterations[e] += 1;
                solutionPeso[e] += p;

                //if(solucao.size() < bestTamanho) bestTamanho = solucao.size();
                if(p < bestPeso){
                    bestPeso = p;
                    //bestAlfa = alfaReactive[e];
                }
            }
            tamanho = solutionSize[e] / iterations[e];
            peso = solutionPeso[e] / iterations[e];
            cout<<"Tamanho: "<<tamanho<<" peso: "<<peso<<endl;
        }

        int maiorPeso = pegaMaior(solutionPeso[prioritarios[0]], solutionPeso[prioritarios[1]], solutionPeso[prioritarios[2]]);

        for(unsigned int y = 3; y < 9; y++){
            if((solutionPeso[y] / iterations[y]) < (solutionPeso[maiorPeso] / iterations[maiorPeso])){
                    prioritarios[maiorPeso] = y;
                    maiorPeso = pegaMaior(solutionPeso[prioritarios[0]], solutionPeso[prioritarios[1]], solutionPeso[prioritarios[2]]);
            }
        }

        int x1;
        int x2;
        int x3 = pegaMaior(solutionPeso[prioritarios[0]], solutionPeso[prioritarios[1]], solutionPeso[prioritarios[2]]);

        if(prioritarios[0] == x3){
            x1 = prioritarios[1];
            x2 = prioritarios[2];
        }else if(prioritarios[1] == x3){
            x1 = prioritarios[0];
            x2 = prioritarios[2];
        }else{
            x1 = prioritarios[0];
            x2 = prioritarios[1];
        }
        if(solutionPeso[x1] < solutionPeso[x2]){
            prioritarios[0] = x1;
            prioritarios[1] = x2;
        }else{
            prioritarios[0] = x2;
            prioritarios[1] = x1;
        }
        prioritarios[2] = x3;

        for(unsigned int a = 0; a < 3 ; a++){
            int indice = prioritarios[a];
            for(unsigned int itera = 0; itera < (4 - a); itera++){
                grafo_vert3 = grafo->cloneVert();
                maximo_vet = grafo_vert3.size();
                solucao.erase(solucao.begin(), solucao.end());
                while(!checaVetor(grafo_vert3))
                {
                    grafo_vert3 = h->mergeSort(grafo_vert3, heuristica);
                    //captura um vértice e adiciona no conjunto solução
                    solucao.push_back(getVertexRandom(grafo_vert3, alfaReactive[indice]));
                }

                float p = calculaPeso(solucao);

                solutionSize[indice] += solucao.size();
                iterations[indice] += 1;
                solutionPeso[indice] += p;

                //if(solucao.size() < bestTamanho) bestTamanho = solucao.size();
                if(p < bestPeso){
                    bestPeso = p;
                    //bestAlfa = alfaReactive[indice];
                }
            }

            tamanho = solutionSize[indice] / iterations[indice];
            peso = solutionPeso[indice] / iterations[indice];

            cout<<"Tamanho: "<<tamanho<<" peso: "<<peso<<" alfa: "<<alfaReactive[indice]<<endl;
        }
        //cout<<"Melhor alfa: "<<bestAlfa<<" Melhor peso: "<<bestPeso<<endl;
        return solucao;
    }

    int pegaMaior(int peso1, int peso2, int peso3){
        if(peso1 > peso2){
                if(peso1 > peso2){
                    return 0;
                }else{
                    return 2;
                }
            }else if(peso2 > peso3){
                return 1;
            }else{
                return 2;
            }
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
