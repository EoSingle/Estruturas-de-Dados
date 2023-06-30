#pragma once

#include "node.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include <fstream>
#include <iostream>

// Classe que implementa a árvore de Huffman.
class Tree{
    private:
        Node *root;

        // Método auxiliar para limpar a árvore.
        void clear(Node *node);

    public:
        // Construtor
        Tree();
        // Destrutor
        ~Tree();

        // Retorna a raiz da árvore.
        Node *getRoot();
        // Define a raiz da árvore.
        void setRoot(Node *root);

        // Cria a árvore a partir de um arquivo de texto.
        void build(Queue &queue);

        // Monta a árvore a partir do cabeçalho do arquivo de entrada.
        void build(std::ifstream &input);

        // Retorna a altura da árvore.
        int getHeight(Node *node);

        // Imprime a árvore
        void print(Node *node);
        // Método auxiliar para imprimir a árvore.
        void print(Node *node, int level);

        // Imprime a árvore no cabeçalho do arquivo de saída.
        void print(Node *node, std::ofstream &output);

        // Retorna se a árvore está vazia.
        bool isEmpty();
        // Limpa a árvore.
        void clear();
};
