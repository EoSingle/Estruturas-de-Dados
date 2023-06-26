#include "ConjuntoDisjunto.hpp" 

ConjuntoDisjunto::ConjuntoDisjunto(){
    this->head = nullptr;
    this->tail = nullptr;
}

ConjuntoDisjunto::~ConjuntoDisjunto(){
    set *aux = this->head;
    while (aux != nullptr){
        set *next = aux->getNext();
        delete aux;
        aux = next;
    }
}

void ConjuntoDisjunto::makeSet(long x){
    set *newSet = new set();
    newSet->setList(new list());
    newSet->getList()->insert(x);

    if (this->head == nullptr){
        this->head = newSet;
        this->tail = newSet;
    } else {
        this->tail->setNext(newSet);
        this->tail = newSet;
    }
}

void ConjuntoDisjunto::unionSet(long x, long y){
    // Conjuntos auxilires para armazenar os conjuntos 
    // que contém os elementos x e y
    set *setX = this->head;
    set *setY = this->head;

    // Busca o conjunto que contém o elemento x
    while (setX != nullptr){
        if (setX->getList()->search(x)){
            break;
        }
        setX = setX->getNext();
    }

    // Busca o conjunto que contém o elemento y
    while (setY != nullptr){
        if (setY->getList()->search(y)){
            break;
        }
        setY = setY->getNext();
    }

    // Se não encontrou os conjuntos, retorna
    if (setX == nullptr || setY == nullptr){
        return;
    }

    // Se os conjuntos são iguais, retorna
    if (setX == setY){
        return;
    }

    // Insere todos os elementos do conjunto que contém o elemento y no
    // conjunto que contém o elemento x
    node *aux = setY->getList()->getHead();
    while (aux != nullptr){
        setX->getList()->insert(aux->getData());
        aux = aux->getNext();
    }

    // Remove o conjunto que continha o elemento y
    set *auxSet = this->head;
    set *prev = nullptr;
    while (auxSet != nullptr){
        if (auxSet == setY){
            if (prev == nullptr){
                this->head = auxSet->getNext();
            } else {
                prev->setNext(auxSet->getNext());
            }
            delete auxSet;
            return;
        }
        prev = auxSet;
        auxSet = auxSet->getNext();
    }
}

set* ConjuntoDisjunto::findSet(long x){
    set *aux = this->head;
    while (aux != nullptr){
        if (aux->getList()->search(x)){
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;
}