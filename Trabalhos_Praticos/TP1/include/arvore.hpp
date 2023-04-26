#pragma once

#include <iostream>
#include <string>
#include "TipoNo.hpp"
#include "pilhaEncadeada.hpp"

class ArvoreBinaria {
    private:
        TipoNo *raiz;

        void ApagaRecursivo(TipoNo* p);
        void PreOrdem(TipoNo* p);
        void InOrdem(TipoNo* p);
        void PosOrdem(TipoNo* p);

    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        void InsereInfixa(std::string item);
        void InserePosfixa(std::string item);
        void Caminha(int tipo);
        void Limpa();

    friend class Resolvedor;
};
