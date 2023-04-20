#pragma once

#include <string>

class Pilha {
    public:
        Pilha();
        int GetTamanho();
        bool Vazia();

        virtual void Empilha(std::string item) = 0;
        virtual std::string Desempilha() = 0;
        virtual void Limpa() = 0;

        protected:
            int tamanho;
};