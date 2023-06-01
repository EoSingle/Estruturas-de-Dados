#pragma once

#include "ponto.hpp"
#include "pilha.hpp"

class Jarvis {
    private:
        Pilha vertices;

    public:
    Jarvis();
    ~Jarvis();

    int orientation(Ponto p, Ponto q, Ponto r);
    void convexHull(Ponto pontos[], int n);
    void printPilha();
};
