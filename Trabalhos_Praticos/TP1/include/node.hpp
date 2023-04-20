#pragma once

#include <string>

class node {
    private:
        std::string item;
        node* proximo;
    public:
        node();
        ~node();

    friend class PilhaEncadeada;
};