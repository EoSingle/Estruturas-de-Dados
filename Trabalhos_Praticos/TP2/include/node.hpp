#pragma once

#include "ponto.hpp"

class Node {
    private:
        Ponto item;
        Node* proximo;
    public:
        Node();
        ~Node();

    friend class Pilha;
};
