#pragma once

#include "pilhaEncadeada.hpp"
#include <string>
#include <iostream>

class Resolvedor {
    private:
        PilhaEncadeada *expressao;

    public:
        Resolvedor();
        ~Resolvedor();
        void lerExpressao(std::string expressao);
        void converteInfixa();
        void convertePosfixa();
        void resolverExpressao();
        void imprimirExpressao();

};