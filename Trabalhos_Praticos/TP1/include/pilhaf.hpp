#pragma once

class PilhaF {
    public:
        PilhaF();
        int GetTamanho();
        bool Vazia();

        virtual void Empilha(float item) = 0;
        virtual float Desempilha() = 0;
        virtual void Limpa() = 0;

        protected:
            int tamanho;

};
