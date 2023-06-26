#include "list.hpp"

list::list(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

list::list(const list &list){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;

    node *aux = list.head;
    while (aux != nullptr){
        this->insert(aux->getData());
        aux = aux->getNext();
    }
}

list::~list(){
    node *aux = this->head;
    while (aux != nullptr){
        node *next = aux->getNext();
        delete aux;
        aux = next;
    }
}

void list::insert(long x){
    node *newNode = new node(x);

    if (this->head == nullptr){
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->setNext(newNode);
        this->tail = newNode;
    }

    this->size++;
}

void list::remove(long x){
    node *aux = this->head;
    node *prev = nullptr;
    while (aux != nullptr){
        if (aux->getData() == x){
            if (prev == nullptr){
                this->head = aux->getNext();
            } else {
                prev->setNext(aux->getNext());
            }
            delete aux;
            this->size--;
            return;
        }
        prev = aux;
        aux = aux->getNext();
    }
}

bool list::search(long x){
    node *aux = this->head;
    while (aux != nullptr){
        if (aux->getData() == x){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

node *list::getHead(){
    return this->head;
}
