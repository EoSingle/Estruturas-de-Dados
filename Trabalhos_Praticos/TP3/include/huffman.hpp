#pragma once

#include "tree.hpp"
#include "queue.hpp"

#include <string.h>

#define TAM 256

// Classe que implementa a codificação e decodificação de Huffman.
class Huffman{
    private:
        Tree *tree;
        Queue *queue;
        unsigned int tableFreq[TAM];

    public:
        // Construtor
        Huffman();
        // Destrutor
        ~Huffman();

        // Realiza a compressão de um arquivo.
        // Parâmetros: arquivo de entrada e arquivo de saída.
        void compress(std::ifstream &file, std::ofstream &output);
        // Realiza a descompressão de um arquivo.
        // Parâmetros: arquivo de entrada e arquivo de saída.
        void decompress(std::ifstream &file, std::ofstream &output);

        // Aloca a tabela de codificação.
        char** allocTable(int columns);
        // Cria a tabela de codificação.
        void buildTable(Node *node, char **table, int columns, char *code);
        // Desaloca a tabela de codificação.
        void clearTable(char **table);

        // Imprime a tabela de frequência.
        void printTableFreq();
        // Imprime a tabela de codificação.
        void printTable(char **table);
};
