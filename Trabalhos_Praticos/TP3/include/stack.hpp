#pragma once

#include "node.hpp"
#include <iostream>

class Stack{
    private:
        Node *top;
        int size;
    public:
        Stack();
        ~Stack();

        Node *getTop();
        int getSize();

        void push(Node *node);
        Node *pop();

        void print();
        void clear();
        bool isEmpty();
};
