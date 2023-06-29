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

    //std::cout << "Tabela de frequência:" << std::endl;
    //this->printTable();

    // Insere os caracteres na fila de prioridade.
    for(int i = 0; i < TAM; i++){
        if(this->table[i] > 0){
            Node *node = new Node((char)i, this->table[i]);
            this->queue->push(node);
        }
    }

    //std::cout << "Fila de prioridade:" << std::endl;
    //this->queue->print();

    // Cria a árvore de Huffman a partir da fila de prioridade.
    this->tree->build(*this->queue);

    //std::cout << "Árvore de Huffman:" << std::endl;
    //this->tree->print(this->tree->getRoot());

    // Grava o cabeçalho no arquivo de saída.
    this->tree->print(this->tree->getRoot(), output);
    output << std::endl;

    // Cria o dicionário de Huffman.
    int columns = this->tree->getHeight(this->tree->getRoot()) + 1;
    char **dict = this->allocDict(columns);
    char code[columns];
    code[0] = '\0';
    this->buildDict(this->tree->getRoot(), dict, columns, code);

    //std::cout << "Dicionário de Huffman:" << std::endl;
    //this->printDict(dict);
    
    // Codifica o arquivo de entrada e grava em uma string.
    std::string buffer;
    file.clear();
    file.seekg(0, std::ios::beg);
    while(file.get(character)){
        buffer += dict[(unsigned char)character];
    }

    // Grava a string no arquivo de saída.
    int size = buffer.size();
    for(int i = 0; i < size; i += 8){
        char byte = 0;
        for(int j = 0; j < 8; j++){
            if(i + j < size){
                byte <<= 1;
                byte |= buffer[i + j] - '0';
            }else{
                byte <<= 1;
            }
        }
        output << byte;
    }
    
    // Libera a memória alocada.
    this->clearDict(dict);
}

void Huffman::decompress(std::ifstream &file, std::ofstream &output){
    // Lê o cabeçalho do arquivo de entrada e cria a árvore de Huffman.
    this->tree->build(file);

    //std::cout << "Árvore de Huffman:" << std::endl;
    //this->tree->print(this->tree->getRoot());

    // Decodifica o arquivo de entrada e grava no arquivo de saída.
    Node *node = this->tree->getRoot();
    char character;
    while(file.get(character)){
        for(int i = 7; i >= 0; i--){
            if((character >> i) & 1){
                node = node->getRight();
            }else{
                node = node->getLeft();
            }
            if(node->getLeft() == nullptr && node->getRight() == nullptr){
                output << node->getCharacter();
                node = this->tree->getRoot();
            }
        }
    }    
}

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
