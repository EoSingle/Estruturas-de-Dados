#pragma once

#include "node.hpp"
#include <iostream>
#include <cmath>

class Tree{
    private:
        Node* root;

    public:
        Tree();
        ~Tree();

        Node* Insert(Node*, int);
        Node* Delete(Node*, int);

        int Height(Node*);

        Node* RotateRight(Node*);
        Node* RotateLeft(Node*);
        Node* RightRight(Node*);
        Node* RightLeft(Node*);
        Node* LeftRight(Node*);
        Node* LeftLeft(Node*);

        void PreOrder(Node*);
        void InOrder(Node*);
        void Dump(Node*, int, char*);

        int BF(Node*);

        Node* getRoot();
        void setRoot(Node*);

        void Limpa();
};