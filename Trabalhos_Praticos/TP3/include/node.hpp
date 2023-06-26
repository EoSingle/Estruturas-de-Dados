#pragma once

class Node{
    private:
        char character;
        int frequency;
        Node *left;
        Node *right;

    public:
        Node();
        Node(char character, int frequency);
        Node(Node *left, Node *right);
        ~Node();

        char getCharacter();
        int getFrequency();
        Node *getLeft();
        Node *getRight();

        void setCharacter(char character);
        void setFrequency(int frequency);
        void setLeft(Node *left);
        void setRight(Node *right);
};