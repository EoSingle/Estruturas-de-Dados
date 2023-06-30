#include "huffman.hpp"

Huffman::Huffman(){
    this->tree = new Tree();
    this->queue = new Queue();
    for(int i = 0; i < TAM; i++){
        this->tableFreq[i] = 0;
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
        this->tableFreq[(unsigned char)character]++;
    }

    //std::cout << "Tabela de frequência:" << std::endl;
    //this->printTableFreq();

    // Insere os caracteres na fila de prioridade.
    for(int i = 0; i < TAM; i++){
        if(this->tableFreq[i] > 0){
            Node *node = new Node((char)i, this->tableFreq[i]);
            this->queue->push(node);
        }
    }

    //std::cout << "Fila de prioridade:" << std::endl;
    //this->queue->print();

    // Cria a árvore de Huffman a partir da fila de prioridade.
    this->tree->build(*this->queue);

    //std::cout << "Árvore de Huffman:" << std::endl;
    //this->tree->print(this->tree->getRoot());

    // Grava a árvore de Huffman no cabeçalho do arquivo de saída.
    this->tree->print(this->tree->getRoot(), output);
    output << std::endl;

    // Cria a tabela de codificação.
    int columns = this->tree->getHeight(this->tree->getRoot()) + 1;
    char **table = this->allocTable(columns);
    char code[columns];
    code[0] = '\0';
    this->buildTable(this->tree->getRoot(), table, columns, code);

    //std::cout << "Tabela de codificação:" << std::endl;
    //this->printTable(table);
    
    // Codifica o arquivo de entrada e grava em uma string.
    std::string buffer;
    file.clear();
    file.seekg(0, std::ios::beg);
    while(file.get(character)){
        buffer += table[(unsigned char)character];
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
    
    // Libera a memória alocada pela tabela de codificação.
    this->clearTable(table);
}

void Huffman::decompress(std::ifstream &file, std::ofstream &output){
    // Lê o cabeçalho do arquivo de entrada e cria a árvore de Huffman.
    this->tree->build(file);

    //std::cout << "Árvore de Huffman:" << std::endl;
    //this->tree->print(this->tree->getRoot());

    // Decodifica o arquivo de entrada e grava no arquivo de saída.
    Node *node = this->tree->getRoot();
    unsigned char byte;
    while(file.get((char&)byte)){
        for(int i = 7; i >= 0; i--){
            if((byte >> i) & 1){
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

char** Huffman::allocTable(int columns){
    char **table = new char*[TAM];
    for(int i = 0; i < TAM; i++){
        table[i] = new char[columns];
    }
    return table;
}

void Huffman::buildTable(Node *node, char **table, int columns, char *code){
    char left[columns], right[columns];
    if(node->getLeft() == nullptr && node->getRight() == nullptr){
        strcpy(table[(unsigned char)node->getCharacter()], code);
    } else {
        strcpy(left, code);
        strcpy(right, code);

        strcat(left, "0");
        strcat(right, "1");

        this->buildTable(node->getLeft(), table, columns, left);
        this->buildTable(node->getRight(), table, columns, right);
    }
}

void Huffman::clearTable(char **table){
    for(int i = 0; i < TAM; i++){
        delete[] table[i];
    }
    delete[] table;
}

void Huffman::printTableFreq(){
    for(int i = 0; i < TAM; i++){
        if(this->tableFreq[i] > 0)
            std::cout << (char)i << " = " << this->tableFreq[i] << std::endl;
    }
}

void Huffman::printTable(char **table){
    for(int i = 0; i < TAM; i++){
        if(strlen(table[i]) > 0)
            std::cout << (char)i << " = " << table[i] << std::endl;
    }
}
