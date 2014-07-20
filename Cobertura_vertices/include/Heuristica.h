#ifndef HEURISTICA_H
#define HEURISTICA_H
#include <vector>
#include "Grafo.h"
#include "Vertice.h"

class Heuristica
{
    public:
        Heuristica(int heuristica){
            heuristica = heuristica;
        };

        vector<Vertice*> mergeSort(vector<Vertice*> &v, int h)
        {
          temp = v;
          m_sort(v, 0, v.size() - 1, h);
          return temp;
        }

        void m_sort(vector<Vertice*> &v, int left, int right, int h)
        {
          int mid;

          if (right > left)
          {
            mid = (right + left) / 2;
            m_sort(v, left, mid, h);
            m_sort(v, mid+1, right, h);
            merge(v, left, mid+1, right, h);
          }
        }

        void merge(vector<Vertice*> &v, int left, int mid, int right, int h)
        {
          unsigned int i;
          int left_end, tmp_pos;

          left_end = mid - 1;
          tmp_pos = left;

          while ((left <= left_end) && (mid <= right))
          {
            if (escolhaHeuristica(v[left],h) <= escolhaHeuristica(v[mid],h))
            {
              temp[tmp_pos] = v[left];
              tmp_pos = tmp_pos + 1;
              left = left +1;
            }
            else
            {
              temp[tmp_pos] = v[mid];
              tmp_pos = tmp_pos + 1;
              mid = mid + 1;
            }
          }

          while (left <= left_end)
          {
            temp[tmp_pos] = v[left];
            left = left + 1;
            tmp_pos = tmp_pos + 1;

          }
          while (mid <= right)
          {
            temp[tmp_pos] = v[mid];
            mid = mid + 1;
            tmp_pos = tmp_pos + 1;

          }
          for (i=0; i < temp.size(); i++)
          {
            v[i] = temp[i];
          }
        }

        float escolhaHeuristica(Vertice *v, int escolha)
        {
            float x = 0;

            if(escolha == 1) x = 1 / v->getGrau();
            if(escolha == 2) x = v->getPeso() / v->getGrau();

            return x;
        }

        void setHeuristica(int heuristica){
        heuristica = heuristica;
    }

    int getHeuristica(){
        return heuristica;
    }

    protected:
    private:
        int heuristica;
        vector<Vertice*> temp;
};

#endif // HEURISTICA_H
