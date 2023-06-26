#pragma once

#include "node.hpp"

class NodeQ{
    private:
        NodeQ *next;
        NodeQ *previous;
        Node *node;

    public:
        NodeQ(Node *node);
        ~NodeQ();

        NodeQ *getNext();
        NodeQ *getPrevious();
        Node *getNode();

        void setNext(NodeQ *next);
        void setPrevious(NodeQ *previous);
        void setNode(Node *node);

};
