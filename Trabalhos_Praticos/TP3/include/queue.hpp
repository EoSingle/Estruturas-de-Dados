#pragma once

#include "node.hpp"
#include <iostream>

// Fila de prioridade mínima
class Queue{
    private:
        Node *head;
        int size;

    public:
        Queue();
        ~Queue();

        Node *getHead();
        int getSize();

        void setHead(Node *head);

        void push(Node *node);
        Node *pop();

        void print();

        bool isEmpty();
        void clear();
};