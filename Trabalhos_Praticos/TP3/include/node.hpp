#pragma once

// Classe que implementa um nó para a árvore, pilha e fila.
class Node{
    private:
        char character;
        int frequency;
        Node *left;
        Node *right;
        Node *next;

    public:
        // Construtor
        Node();
        // Construtor com parâmetros caracter e frequência.
        Node(char character, int frequency);
        // Construtor com parâmetros nó esquerdo e nó direito.
        Node(Node *left, Node *right);
        // Destrutor
        ~Node();

        // Retorna o caractere do nó.
        char getCharacter();
        // Retorna a frequência do nó.
        int getFrequency();
        // Retorna o nó esquerdo.
        Node *getLeft();
        // Retorna o nó direito.
        Node *getRight();
        // Retorna o próximo nó.
        Node *getNext();

        // Define o caractere do nó.
        void setCharacter(char character);
        // Define a frequência do nó.
        void setFrequency(int frequency);
        // Define o nó esquerdo.
        void setLeft(Node *left);
        // Define o nó direito.
        void setRight(Node *right);
        // Define o próximo nó.
        void setNext(Node *next);
};
