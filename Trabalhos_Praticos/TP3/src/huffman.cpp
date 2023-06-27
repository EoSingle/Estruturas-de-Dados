#include "huffman.hpp"

Huffman::Huffman(){
    this->tree = new Tree();
    this->queue = new Queue();
    for(int i = 0; i < TAM; i++){
        this->table[i] = 0;
    }
}

Huffman::~Huffman(){
    delete this->tree;
    delete this->queue;
}

void Huffman::compress(std::ifstream &file, std::ofstream &output){
    // Percorre o arquivo e conta a frequência de cada caractere.
    char character;
    while(file.get(character)){
        this->table[(unsigned char)character]++;
    }

    std::cout << "Tabela de frequência:" << std::endl;
    this->printTable();

    // Insere os caracteres na fila de prioridade.
    for(int i = 0; i < TAM; i++){
        if(this->table[i] > 0){
            Node *node = new Node((char)i, this->table[i]);
            this->queue->push(node);
        }
    }

    std::cout << "Fila de prioridade:" << std::endl;
    this->queue->print();

    // Cria a árvore de Huffman a partir da fila de prioridade.
    this->tree->build(*this->queue);
    // Grava o cabeçalho no arquivo de saída.
    //this->tree->print(this->tree->getRoot(), output);

    std::cout << "Árvore de Huffman:" << std::endl;
    this->tree->print(this->tree->getRoot());

    // Cria o dicionário de Huffman.
    int columns = this->tree->getHeight(this->tree->getRoot()) + 1;
    char **dict = this->allocDict(columns);
    char code[columns];
    code[0] = '\0';
    this->buildDict(this->tree->getRoot(), dict, columns, code);

    std::cout << "Dicionário de Huffman:" << std::endl;
    this->printDict(dict);

    
    // Codifica o arquivo de entrada e grava no arquivo de saída.
    file.clear();
    file.seekg(0, std::ios::beg);
    while(file.get(character)){
        output << dict[(unsigned char)character];
    }
    
    // Libera a memória alocada.
    this->clearDict(dict);
}

void Huffman::decompress(std::ifstream &file, std::ofstream &output){}

char** Huffman::allocDict(int columns){
    char **dict = new char*[TAM];
    for(int i = 0; i < TAM; i++){
        dict[i] = new char[columns];
    }
    return dict;
}

void Huffman::buildDict(Node *node, char **dict, int columns, char *code){
    char left[columns], right[columns];
    if(node->getLeft() == nullptr && node->getRight() == nullptr){
        strcpy(dict[(unsigned char)node->getCharacter()], code);
    } else {
        strcpy(left, code);
        strcpy(right, code);

        strcat(left, "0");
        strcat(right, "1");

        this->buildDict(node->getLeft(), dict, columns, left);
        this->buildDict(node->getRight(), dict, columns, right);
    }
}

void Huffman::clearDict(char **dict){
    for(int i = 0; i < TAM; i++){
        delete[] dict[i];
    }
    delete[] dict;
}

void Huffman::printTable(){
    for(int i = 0; i < TAM; i++){
        if(this->table[i] > 0)
            std::cout << (char)i << " = " << this->table[i] << std::endl;
    }
}

void Huffman::printDict(char **dict){
    for(int i = 0; i < TAM; i++){
        if(strlen(dict[i]) > 0)
            std::cout << (char)i << " = " << dict[i] << std::endl;
    }
}
