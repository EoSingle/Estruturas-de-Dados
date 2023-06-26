#pragma once

#include "tree.hpp"
#include "queue.hpp"

class Huffman{
    private:
        Tree *tree;
        Queue *queue;

    public:
        Huffman();
        ~Huffman();

        void compress(std::ifstream &file, std::ofstream &output);
        void decompress(std::ifstream &file, std::ofstream &output);
};
