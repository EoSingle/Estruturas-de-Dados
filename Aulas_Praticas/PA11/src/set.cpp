#include "set.hpp"

set::set(){
    this->linked_list = nullptr;
    this->next = nullptr;
}

set::~set(){
    this->linked_list = nullptr;
    this->next = nullptr;
}

list *set::getList(){
    return this->linked_list;
}

set *set::getNext(){
    return this->next;
}

void set::setList(list *list){
    this->linked_list = list;
}

void set::setNext(set *next){
    this->next = next;
}
