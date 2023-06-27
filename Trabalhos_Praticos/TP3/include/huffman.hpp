#pragma once

#include "tree.hpp"
#include "queue.hpp"

#include <string.h>

#define TAM 256

class Huffman{
    private:
        Tree *tree;
        Queue *queue;
        unsigned int table[TAM];

    public:
        Huffman();
        ~Huffman();

        void compress(std::ifstream &file, std::ofstream &output);
        void decompress(std::ifstream &file, std::ofstream &output);

        char** allocDict(int columns);
        void buildDict(Node *node, char **dict, int columns, char *code);
        void clearDict(char **dict);

        void printTable();
        void printDict(char **dict);
};
