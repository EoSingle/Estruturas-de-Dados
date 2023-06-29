#include "stack.hpp"

Stack::Stack(){
    this->top = nullptr;
    this->size = 0;
}

Stack::~Stack(){
    this->clear();
}

Node *Stack::getTop(){
    return this->top;
}

void Stack::push(Node *node){
    if(this->top == nullptr){
        this->top = node;
    }else{
        node->setNext(this->top);
        this->top = node;
    }
    this->size++;
}

Node *Stack::pop(){
    if(this->top != nullptr){
        Node *node = this->top;
        this->top = this->top->getNext();
        node->setNext(nullptr);
        this->size--;
        return node;
    }else{
        return nullptr;
    }
}

int Stack::getSize(){
    return this->size;
}

void Stack::print(){
    Node *node = this->top;
    while(node != nullptr){
        std::cout << node->getCharacter() << " ";
        node = node->getNext();
    }
    std::cout << std::endl;
}

void Stack::clear(){
    Node *node = this->top;
    while(node != nullptr){
        Node *aux = node;
        node = node->getNext();
        delete aux;
    }
    this->top = nullptr;
    this->size = 0;
}

bool Stack::isEmpty(){
    return this->top == nullptr;
}
