#include "tree.hpp"

Tree::Tree(){
    this->root = nullptr;
}

Tree::~Tree(){
    Limpa();
}

Node* Tree::Insert(Node* Tree, int x){
    if (Tree == nullptr){
        Tree = new Node(x, nullptr, nullptr, 0);
    } 
    else if (x > Tree->data) {
        Tree->right = Insert(Tree->right, x);
        if (BF(Tree) == -3){
            if (x > Tree->right->data){
                Tree = RightRight(Tree);
            } 
            else {
                Tree = RightLeft(Tree);
            }
        }
    }  
    else if (x < Tree->data) {
        Tree->left = Insert(Tree->left, x);
        if (BF(Tree) == 3){
            if (x < Tree->left->data){
                Tree = LeftLeft(Tree);
            } 
            else {
                Tree = LeftRight(Tree);
            }
        }
    }
    Tree->height = Height(Tree);
    return (Tree);
}

Node* Tree::Delete(Node* Tree, int x) {
    Node* aux;
    if (Tree == nullptr) {
        return nullptr;
    } 
    else if (x > Tree->data) {
        Tree->right = Delete(Tree->right, x);
        if (BF(Tree) == 3){
            if (BF(Tree->left) >= 0){
                Tree = LeftLeft(Tree);
            }
            else{
                Tree = LeftRight(Tree);
            }
        }
    } 
    else if (x < Tree->data) {
        Tree->left = Delete(Tree->left, x);
        if (BF(Tree) == -3){ //Rebalance during windup
            if (BF(Tree->right) <= 0){
                Tree = RightRight(Tree);
            }
            else{
                Tree = RightLeft(Tree);
            }
        }
    } 
    else {
        //data to be deleted is found
        if (Tree->right != nullptr) { //delete its inorder succesor
            aux = Tree->right;
            while (aux->left != nullptr)
                aux = aux->left;
            Tree->data = aux->data;
            Tree->right = Delete(Tree->right, aux->data);
            if (BF(Tree) == 3){ //Rebalance during windup
                if (BF(Tree->left) >= 0){
                    Tree = LeftLeft(Tree);
                }
                else{
                    Tree = LeftRight(Tree);
                }
            }
        } 
        else
            return (Tree->left);
    }
    Tree->height = Height(Tree);
    return (Tree);
}

int Tree::Height(Node* Tree) {
    int leftHeight, rightHeight;
    if (Tree == nullptr)
        return 0;
    if (Tree->left == nullptr)
        leftHeight = 0;
    else
        leftHeight = 1 + Tree->left->height;
    if (Tree->right == nullptr)
        rightHeight = 0;
    else
        rightHeight = 1 + Tree->right->height;
    
    return std::max(leftHeight, rightHeight);
}

Node* Tree::RotateRight(Node* x) {
    Node* y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->height = Height(x);
    y->height = Height(y);
    return y;
}

Node* Tree::RotateLeft(Node* x) {
    Node* y;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = Height(x);
    y->height = Height(y);
    return y;
}

Node* Tree::RightRight(Node* Tree) {
    Tree = RotateLeft(Tree);
    return Tree;
}

Node* Tree::LeftLeft(Node* Tree) {
    Tree = RotateRight(Tree);
    return Tree;
}

Node* Tree::LeftRight(Node* Tree) {
    Tree->left = RotateLeft(Tree->left);
    Tree = RotateRight(Tree);
    return Tree;
}

Node* Tree::RightLeft(Node* Tree) {
    Tree->right = RotateRight(Tree->right);
    Tree = RotateLeft(Tree);
    return Tree;
}

void Tree::PreOrder(Node* Tree) {
    if (Tree != nullptr) {
        std::cout << Tree->data << "(Bf=" << BF(Tree) << ")" << std::endl;
        PreOrder(Tree->left);
        PreOrder(Tree->right);
    }
}

void Tree::InOrder(Node* Tree) {
    if (Tree != nullptr) {
        InOrder(Tree->left);
        std::cout << Tree->data << "(Bf=" << BF(Tree) << ")" << std::endl;
        InOrder(Tree->right);
    }
}

void Tree::Dump(Node* Tree, int level, char* pref) {
    if (Tree != nullptr) {
        std::cout << pref;
        for(int i=0; i<level; i++) std::cout << "    ";
        std::cout << Tree->data << " (Bf=" << BF(Tree) << ", H=" << Tree->height << ")" << std::endl;
        Dump(Tree->left,level+1,pref);
        Dump(Tree->right,level+1,pref);
    }
}

int Tree::BF(Node* Tree) {
    int leftHeight = 0, rightHeight = 0;
    if (Tree->left != nullptr)
        leftHeight = 1 + Tree->left->height;
    if (Tree->right != nullptr)
        rightHeight = 1 + Tree->right->height;
    return leftHeight - rightHeight;
}

void Tree::Limpa(){

}

Node* Tree::getRoot(){
    return this->root;
}

void Tree::setRoot(Node* nRoot){
    this->root = nRoot;
}