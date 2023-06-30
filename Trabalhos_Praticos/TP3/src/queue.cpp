#include "queue.hpp"

Queue::Queue(){
    this->head = nullptr;
    this->size = 0;
}

Queue::~Queue(){
    this->clear();
}

Node *Queue::getHead(){
    return this->head;
}

int Queue::getSize(){
    return this->size;
}

void Queue::setHead(Node *head){
    this->head = head;
}

void Queue::push(Node *node){
    if(this->isEmpty()){
        this->head = node;
    }else if(this->head->getFrequency() > node->getFrequency()){
        node->setNext(this->head);
        this->head = node;
    }else{
        Node *aux = this->head;
        while(aux->getNext() != nullptr && aux->getNext()->getFrequency() < node->getFrequency()){
            aux = aux->getNext();
        }
        node->setNext(aux->getNext());
        aux->setNext(node);
    }
    this->size++;
}

Node *Queue::pop(){
    if(this->isEmpty()){
        return nullptr;
    }else{
        Node *node = this->head;
        this->head = this->head->getNext();
        this->size--;
        return node;
    }
}

void Queue::print(){
    Node *node = this->head;
    while(node != nullptr){
        std::cout << node->getCharacter() << " " << node->getFrequency() << std::endl;
        node = node->getNext();
    }
}

bool Queue::isEmpty(){
    return size == 0;
}

void Queue::clear(){
    while(!this->isEmpty()){
        Node *node = this->pop();
        delete node;
    }
}
