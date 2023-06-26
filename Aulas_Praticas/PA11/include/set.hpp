#pragma once

#include "list.hpp"

class set{
    private:
        list *linked_list;
        set *next;

    public:
        set();
        ~set();

        list *getList();
        set *getNext();

        void setList(list *list);
        void setNext(set *next);
        
};