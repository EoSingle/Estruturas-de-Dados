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

void Tree::build(Queue &queue){
    while(queue.getSize() > 1){
        Node *left = queue.pop();
        Node *right = queue.pop();
        Node *parent = new Node('\0', left->getFrequency() + right->getFrequency());
        parent->setLeft(left);
        parent->setRight(right);
        queue.push(parent);
    }
    this->root = queue.pop();
}

void Tree::build(std::ifstream &input){
    Stack stack;
    while(input.peek() != '\n'){
        char character;
        input.get(character);
        if(character == (char)1){
            Node *right = stack.pop();
            Node *left = stack.pop();
            Node *parent = new Node('\0', 0);
            parent->setLeft(left);
            parent->setRight(right);
            stack.push(parent);
        }else if(character == (char)2){
            Node *node = new Node('\n', 0);
            stack.push(node);
        }else{
            Node *node = new Node(character, 0);
            stack.push(node);
        }
    }
    this->root = stack.pop();
    input.get();
}

int Tree::getHeight(Node *node){
    if(node == nullptr){
        return -1;
    }else{
        int left = this->getHeight(node->getLeft());
        int right = this->getHeight(node->getRight());
        if(left > right){
            return left + 1;
        }else{
            return right + 1;
        }
    }
}

void Tree::print(Node *node){
    this->print(node, 0);
}

void Tree::print(Node *node, int level){
    if(node != nullptr){
        this->print(node->getRight(), level + 1);
        for(int i = 0; i < level; i++){
            std::cout << "    ";
        }
        if(node->getCharacter() == '\0'){
            std::cout << "*" << std::endl;
        }else{
            std::cout << node->getCharacter() << std::endl;
        }
        this->print(node->getLeft(), level + 1);
    }
}

void Tree::print(Node *node, std::ofstream &output){
    if(node != nullptr){
        this->print(node->getLeft(), output);
        this->print(node->getRight(), output);
        if(node->getCharacter() == '\0'){
            output << (char)1;
        }
        else if(node->getCharacter() == '\n'){
            output << (char)2;
        }else{
            output << node->getCharacter();
        }
    }
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
