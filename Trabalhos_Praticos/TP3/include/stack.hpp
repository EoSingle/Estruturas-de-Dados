#pragma once

#include "node.hpp"
#include <iostream>

// Classe que implementa uma pilha.
class Stack{
    private:
        Node *top;
        int size;
    public:
        // Construtor
        Stack();
        // Destrutor
        ~Stack();

        // Retorna o nó do topo da pilha.
        Node *getTop();
        // Retorna o tamanho da pilha.
        int getSize();

        // Empilha um nó.
        void push(Node *node);
        // Desempilha um nó.
        Node *pop();

        // Imprime a pilha.
        void print();
        // Limpa a pilha.
        void clear();
        // Retorna se a pilha está vazia.
        bool isEmpty();
};
