#pragma once

#include <string>
#include <iostream>
#include "node.hpp"

class Pilha {
    private:
        Node* topo;
        int tamanho;
    public:
        Pilha();
        ~Pilha();
        int GetTamanho();
        Ponto GetTopo();
        Ponto NextToTop();
        bool Vazia();

        void Empilha(Ponto item) ;
        Ponto Desempilha();
        void Limpa();

        void Imprime();
};
