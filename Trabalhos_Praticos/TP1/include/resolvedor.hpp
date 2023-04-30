#pragma once

#include "arvore.hpp"
#include "pilhaEncadeada.hpp"
#include "pilhafloat.hpp"
#include <string>
#include <iostream>

class Resolvedor {
    private:
        ArvoreBinaria *arvore;
        PilhaFloat *resultado;

    public:
        Resolvedor();
        ~Resolvedor();
        bool validarExpressao(std::string expressao, int tipoExpressao);
        void lerExpressao(std::string expressao, int tipoExpressao);
        void converteInfixa();
        void convertePosfixa();
        void resolverExpressao();
        void resolveRecursivo(TipoNo* p);

}; 
