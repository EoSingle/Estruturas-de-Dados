#include "queue.hpp"

Queue::Queue(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

Queue::~Queue(){
    this->clear();
}

NodeQ *Queue::getHead(){
    return this->head;
}

NodeQ *Queue::getTail(){
    return this->tail;
}

NodeQ *Queue::getNode(char character){
    NodeQ *nodeQ = this->head;
    while(nodeQ != nullptr){
        if(nodeQ->getNode()->getCharacter() == character){
            return nodeQ;
        }
        nodeQ = nodeQ->getNext();
    }
    return nullptr;
}

int Queue::getSize(){
    return this->size;
}

void Queue::setHead(NodeQ *head){
    this->head = head;
}

void Queue::setTail(NodeQ *tail){
    this->tail = tail;
}

// Insere um caractere na fila de prioridade sem ordenar
void Queue::push(char character){
    NodeQ *nodeQ = this->getNode(character);
    if(nodeQ != nullptr){
        nodeQ->getNode()->setFrequency(nodeQ->getNode()->getFrequency() + 1);
    }else{
        nodeQ = new NodeQ(new Node(character, 1));
        if(this->isEmpty()){
            this->head = nodeQ;
            this->tail = nodeQ;
        }else{
            this->tail->setNext(nodeQ);
            nodeQ->setPrevious(this->tail);
            this->tail = nodeQ;
        }
        this->size++;
    }
}

// Insere um nó na fila de prioridade sem ordenar
void Queue::push(Node *node){
    NodeQ *nodeQ = new NodeQ(node);
    if(this->isEmpty()){
        this->head = nodeQ;
        this->tail = nodeQ;
    }else{
        this->tail->setNext(nodeQ);
        nodeQ->setPrevious(this->tail);
        this->tail = nodeQ;
    }
    this->size++;
}

// Remove o nó com menor frequência da fila de prioridade.
NodeQ *Queue::pop(){
    if(this->isEmpty()){
        return nullptr;
    }
    // Busca o nó com menor frequência.
    NodeQ *nodeQ = this->head;
    NodeQ *aux = this->head;
    while(aux != nullptr){
        if(aux->getNode()->getFrequency() < nodeQ->getNode()->getFrequency()){
            nodeQ = aux;
        }
        aux = aux->getNext();
    }
    // Remove o nó da fila de prioridade.
    if(nodeQ == this->head){
        this->head = nodeQ->getNext();
        if(this->head != nullptr){
            this->head->setPrevious(nullptr);
        }
    }else if(nodeQ == this->tail){
        this->tail = nodeQ->getPrevious();
        if(this->tail != nullptr){
            this->tail->setNext(nullptr);
        }
    }else{
        nodeQ->getPrevious()->setNext(nodeQ->getNext());
        nodeQ->getNext()->setPrevious(nodeQ->getPrevious());
    }

    this->size--;
    nodeQ->setNext(nullptr);
    nodeQ->setPrevious(nullptr);
    return nodeQ;
}

bool Queue::isEmpty(){
    return size == 0;
}

void Queue::clear(){
    while(!this->isEmpty()){
        NodeQ *nodeQ = this->pop();
        delete nodeQ;
    }
}
