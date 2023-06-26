#include "node.hpp"

Node::Node(){
    this->character = '\0';
    this->frequency = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(char character, int frequency){
    this->character = character;
    this->frequency = frequency;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(Node *left, Node *right){
    this->character = '\0';
    this->frequency = left->frequency + right->frequency;
    this->left = left;
    this->right = right;
}

Node::~Node(){
    this->left = nullptr;
    this->right = nullptr;
}

char Node::getCharacter(){
    return this->character;
}

int Node::getFrequency(){
    return this->frequency;
}

Node *Node::getLeft(){
    return this->left;
}

Node *Node::getRight(){
    return this->right;
}

void Node::setCharacter(char character){
    this->character = character;
}

void Node::setFrequency(int frequency){
    this->frequency = frequency;
}

void Node::setLeft(Node *left){
    this->left = left;
}

void Node::setRight(Node *right){
    this->right = right;
}