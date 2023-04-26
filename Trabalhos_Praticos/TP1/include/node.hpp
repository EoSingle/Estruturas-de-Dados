#pragma once

#include "TipoNo.hpp"

class node {
    private:
        TipoNo* item;
        node* proximo;
    public:
        node();
        ~node();

    friend class PilhaEncadeada;
};
