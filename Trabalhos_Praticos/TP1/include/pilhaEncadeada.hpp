#pragma once

#include "pilha.hpp"
#include "node.hpp"
#include "TipoNo.hpp"
#include <string>


class PilhaEncadeada : public Pilha {
    private:
        node* topo;
    public:
        PilhaEncadeada();
        virtual ~PilhaEncadeada();
        void Empilha(TipoNo *item) override;
        TipoNo* Desempilha() override;
        void Limpa() override;

        TipoNo* GetTopo();
};
