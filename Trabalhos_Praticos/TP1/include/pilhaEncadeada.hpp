#pragma once

#include "pilha.hpp"
#include "node.hpp"
#include <string>


class PilhaEncadeada : public Pilha {
    private:
        node* topo;
    public:
        PilhaEncadeada();
        virtual ~PilhaEncadeada();
        void Empilha(std::string item);
        std::string Desempilha();
        void Limpa();

        std::string GetTopo();
};