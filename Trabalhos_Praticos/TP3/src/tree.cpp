#include "tree.hpp"

Tree::Tree(){
    this->root = nullptr;
}

Tree::~Tree(){
    this->clear();
}

Node *Tree::getRoot(){
    return this->root;
}

void Tree::setRoot(Node *root){
    this->root = root;
}

// Contrói a árvore de Huffman a partir de uma fila de prioridade.
void Tree::build(Queue &queue){
    while(queue.getSize() > 1){
        Node *left = queue.pop()->getNode();
        Node *right = queue.pop()->getNode();
        Node *parent = new Node(left, right);
        queue.push(parent);
    }

    // Define a raiz da árvore.
    this->root = queue.pop()->getNode();
}

// Imprime a árvore de Huffman.
void Tree::print(Node *node){
    this->print(node, 0);
}

void Tree::print(Node *node, int level){
    if(node != nullptr){
        this->print(node->getRight(), level + 1);
        for(int i = 0; i < level; i++){
            std::cout << "   ";
        }
        std::cout << node->getCharacter() << std::endl;
        this->print(node->getLeft(), level + 1);
    }
}

// Grava a árvore de Huffman no arquivo de saída.
void Tree::print(Node *node, std::ofstream &output){
    if(node != nullptr){
        this->print(node->getLeft(), output);
        this->print(node->getRight(), output);
        if(node->getCharacter() == '\0'){
            output << "$";
        }else{
            output << node->getCharacter();
        }
    }
}

// Codifica um caractere e grava no arquivo de saída.
void Tree::encode(char character, std::ofstream &output){
    Node *node = this->root;
    std::string code = "";
    while(node->getCharacter() != character){
        if(node->getLeft()->getCharacter() == character){
            node = node->getLeft();
            code += "0";
        }else if(node->getRight()->getCharacter() == character){
            node = node->getRight();
            code += "1";
        }else{
            continue;
        }
    }
    output << code;
}

bool Tree::isEmpty(){
    return this->root == nullptr;
}

void Tree::clear(){
    this->clear(this->root);
    this->root = nullptr;
}

void Tree::clear(Node *node){
    if(node != nullptr){
        this->clear(node->getLeft());
        this->clear(node->getRight());
        delete node;
    }
}
