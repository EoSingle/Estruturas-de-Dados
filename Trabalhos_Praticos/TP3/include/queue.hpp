#pragma once

#include "node.hpp"
#include <iostream>

// Classe que implementa uma fila de prioridade mínima
class Queue{
    private:
        Node *head;
        int size;

    public:
        // Construtor
        Queue();
        // Destrutor
        ~Queue();

        // Retorna o nó cabeça da fila.
        Node *getHead();
        // Retorna o tamanho da fila.
        int getSize();

        // Define o nó cabeça da fila.
        void setHead(Node *head);

        // Insere um nó na fila.
        void push(Node *node);
        // Remove um nó da fila.
        Node *pop();

        // Imprime a fila.
        void print();

        // Retorna se a fila está vazia.
        bool isEmpty();
        // Limpa a fila.
        void clear();
};