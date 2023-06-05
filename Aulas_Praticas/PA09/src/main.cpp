#include "node.hpp"
#include "tree.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    Tree* tree = new Tree();
    int x, op;
    int i=0, n=0;
    char pref[100] = "";

    do {
        std::cout << "\n1)Create:\n2)Insert\n3)Delete:\n4)Print:\n5)Quit:\n\nEnter Your Choice:";
        std::cin >> op;
        switch(op){
            case 1: {
                std::cout << "\nEnter no. of elements:";
                std::cin >> n;
                std::cout << "\nEnter tree data:";
                for (i = 0; i < n; i++) {
                    std::cin >>  x;
                    std::cout << "\nInsert: " << x << std::endl;
                    tree->setRoot(tree->Insert(tree->getRoot(), x));
                    tree->Dump(tree->getRoot(),0,pref);
                }
                break;
            }
            case 2:{
                std::cout << "\nEnter a data:";
                std::cin >> x;
                tree->setRoot(tree->Insert(tree->getRoot(), x));
                break;
            }
            case 3:{
                std::cout << "\nEnter a data:";
                std::cin >> x;
                tree->setRoot(tree->Delete(tree->getRoot(), x));
                break;
            }
            case 4:
                std::cout << "\nPreOrder sequence:\n";
                tree->PreOrder(tree->getRoot());
                std::cout << "\n\nInOrder sequence:\n";
                tree->InOrder(tree->getRoot());
                std::cout << std::endl << "\n\nDump:\n";
                tree->Dump(tree->getRoot(), 0, pref);
                break;
            default:
                break;
        }
    } while (op != 5);
    
    delete tree;
    return 0;
}