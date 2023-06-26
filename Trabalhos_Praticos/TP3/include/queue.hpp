#pragma once

#include "nodeQ.hpp"

// Fila de prioridade mínima
class Queue{
    private:
        NodeQ *head;
        NodeQ *tail;

        int size;

    public:
        Queue();
        ~Queue();

        NodeQ *getHead();
        NodeQ *getTail();
        NodeQ *getNode(char character);
        int getSize();

        void setHead(NodeQ *head);
        void setTail(NodeQ *tail);

        void push(char character);
        void push(Node *node);
        NodeQ *pop();

        bool isEmpty();
        void clear();
};