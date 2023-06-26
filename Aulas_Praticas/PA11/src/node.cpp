#include "node.hpp"

node::node(){
    this->data = 0;
    this->next = nullptr;
}

node::node(node *node){
    this->data = node->data;
    this->next = node->next;
}

node::node(long x){
    this->data = x;
    this->next = nullptr;
}

// Copy constructor
node::node(const node &node){
    this->data = node.data;
    this->next = node.next;
}

node::~node(){
    this->next = nullptr;
}

long node::getData(){
    return this->data;
}

node *node::getNext(){
    return this->next;
}

void node::setData(long x){
    this->data = x;
}

void node::setNext(node *next){
    this->next = next;
}
