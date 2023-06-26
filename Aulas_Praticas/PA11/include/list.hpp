#pragma once

#include "node.hpp"
#include <iostream>

class list{
    private:
        node *head;
        node *tail;
        long size;

    public:
        list();
        list(const list &list);
        ~list();

        void insert(long x);
        void remove(long x);
        bool search(long x);

        node *getHead();

};
