#pragma once

#include "pilha.hpp"
#include "ponto.hpp"

#include <cmath>

class Graham {
    private:
        Ponto p0;
        Pilha vertices;
        int orientation(Ponto p, Ponto q, Ponto r);
        int distSq(Ponto p1, Ponto p2);
        int compare(const void *vp1, const void *vp2);

        // Métodos de ordenação
        void ordMinY(Ponto pontos[], int n);
        void MergeSort(Ponto pontos[], int left, int right);
        void Merge(Ponto pontos[], int const left, int const mid, int const right);
        
        void InsertionSort(Ponto pontos[], int n);
        
        double Angle(Ponto p);
        void BucketSort(Ponto pontos[], int n);

        void polarSort(Ponto pontos[], int n, int type);
    
    public:
        Graham();
        ~Graham();

        void convexHull(Ponto pontos[], int n, int type);
        void printPilha();
};
