#pragma once

class node{
    private:
        long data;
        node *next;

    public:
        node();
        node(node *node);
        node(long x);
        ~node();

        // Copy constructor
        node(const node &node);

        long getData();
        node *getNext();

        void setData(long x);
        void setNext(node *next);

        friend class list;
}; 