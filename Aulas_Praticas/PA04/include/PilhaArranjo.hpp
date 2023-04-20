#pragma once

#include "FilaCircular.hpp"
#include <iostream>

class PilhaArranjo
{
 public:
    // criapilha
    PilhaArranjo();
    int GetTamanho() {return tamanho;};
    // pilhavazia
    bool Vazia() {return tamanho == 0;};

    void Empilha(int item);
    int Desempilha();
    // destroipilha
    void Limpa();
    void Imprime();
 private:
    int topo;
    int tamanho;
    static const int MAXTAM = 10;

    FilaArranjo filaprincipal;
    FilaArranjo filasecundaria;
};