#pragma once

#include "node.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include <fstream>
#include <iostream>

class Tree{
    private:
        Node *root;

        // Limpa a árvore recursivamente.
        void clear(Node *node);

    public:
        Tree();
        ~Tree();

        Node *getRoot();
        void setRoot(Node *root);

        // Cria a árvore a partir de um arquivo de texto.
        void build(Queue &queue);

        // Monta a árvore a partir do cabeçalho do arquivo de entrada.
        void build(std::ifstream &input);

        // Retorna a altura da árvore.
        int getHeight(Node *node);

        // Imprime a árvore
        void print(Node *node);
        void print(Node *node, int level);

        // Imprime a árvore no cabeçalho do arquivo de saída.
        void print(Node *node, std::ofstream &output);

        bool isEmpty();
        void clear();
};
