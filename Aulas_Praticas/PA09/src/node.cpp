#include "node.hpp"

Node::Node(){
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 0;
}

Node::Node(int data, Node* left, Node* right, int height){
    this->data = data;
    this-> left = left;
    this->right = right;
    this->height = height;
}

Node::~Node(){}
