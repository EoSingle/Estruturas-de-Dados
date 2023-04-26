#pragma once

#include "arvore.hpp"
#include "pilhaEncadeada.hpp"
#include <string>
#include <iostream>

class Resolvedor {
    private:
        ArvoreBinaria *arvore;
        int tipoExpressao;

    public:
        Resolvedor();
        ~Resolvedor();
        bool validarExpressao(std::string expressao);
        void lerExpressao(std::string expressao);
        void converteInfixa();
        void convertePosfixa();
        void resolverExpressao();

}; 
