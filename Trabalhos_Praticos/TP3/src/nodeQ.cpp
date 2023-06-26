#include "nodeQ.hpp"

NodeQ::NodeQ(Node *node){
    this->node = node;
    this->next = nullptr;
    this->previous = nullptr;
}

NodeQ::~NodeQ(){
    delete this->node;
}

NodeQ *NodeQ::getNext(){
    return this->next;
}

NodeQ *NodeQ::getPrevious(){
    return this->previous;
}

Node *NodeQ::getNode(){
    return this->node;
}

void NodeQ::setNext(NodeQ *next){
    this->next = next;
}

void NodeQ::setPrevious(NodeQ *previous){
    this->previous = previous;
}

void NodeQ::setNode(Node *node){
    this->node = node;
}
