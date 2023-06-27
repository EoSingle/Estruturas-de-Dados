#pragma once

class Node{
    private:
        char character;
        int frequency;
        Node *left;
        Node *right;
        Node *next;

    public:
        // Construtores e destrutores
        Node();
        Node(char character, int frequency);
        Node(Node *left, Node *right);
        ~Node();

        // Getters
        char getCharacter();
        int getFrequency();
        Node *getLeft();
        Node *getRight();
        Node *getNext();

        // Setters
        void setCharacter(char character);
        void setFrequency(int frequency);
        void setLeft(Node *left);
        void setRight(Node *right);
        void setNext(Node *next);
};
