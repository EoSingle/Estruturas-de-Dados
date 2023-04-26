#pragma once

#include <string>
#include "TipoNo.hpp"

class Pilha {
    public:
        Pilha();
        int GetTamanho();
        bool Vazia();

        virtual void Empilha(TipoNo* item) = 0;
        virtual TipoNo* Desempilha() = 0;
        virtual void Limpa() = 0;

        protected:
            int tamanho;
};
