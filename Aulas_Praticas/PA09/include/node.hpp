#pragma once

class Node {
    private:
        int data;
        Node* left;
        Node* right;
        int height;
    public:
        Node();
        Node(int, Node*, Node*, int);
        ~Node();
        int getData();

    friend class Tree;
};