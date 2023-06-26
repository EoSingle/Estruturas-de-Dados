#include "huffman.hpp"

Huffman::Huffman(){
    this->tree = new Tree();
    this->queue = new Queue();
}

Huffman::~Huffman(){
    delete this->tree;
    delete this->queue;
}

void Huffman::compress(std::ifstream &file, std::ofstream &output){
    // Percorre o arquivo e insere os caracteres na fila de prioridade.
    char character;
    while(file.get(character)){
        this->queue->push(character);
    }

    // Cria a árvore de Huffman a partir da fila de prioridade.
    this->tree->build(*this->queue);
    // Grava o cabeçalho no arquivo de saída.
    this->tree->print(this->tree->getRoot(), output);

    this->tree->print(this->tree->getRoot());

    /*
    // Codifica o arquivo de entrada e grava no arquivo de saída.
    file.clear();
    file.seekg(0, std::ios::beg);
    while(file.get(character)){
        this->tree->encode(character, output);
    }
    */
}

void Huffman::decompress(std::ifstream &file, std::ofstream &output){}
