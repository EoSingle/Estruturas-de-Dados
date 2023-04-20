#include "FilaCircular.hpp"
#include "PilhaArranjo.hpp"
#include <iostream>

int main(){
    PilhaArranjo pilha;

    int aux = 0;

    std::cout << "Usei loops para empilhar e desempilhar aleatoriamente para testar a pilha." << std::endl;
    std::cout << "Usei um domínio de 0 a 9 conforme solicitado." << std::endl;

    for(int i = 0; i < 10; i++){
        std::cout << std::endl << "Empilhando..." << std::endl;
        for (int i = 0; i < rand() % 10; i++){
            pilha.Empilha(aux);
            pilha.Imprime();
            aux = (aux + 1) % 10;
        }

        std::cout << std::endl << "Desempilhando..." << std::endl;
        for (int i = 0; i < rand() % 10; i++){
            pilha.Desempilha();
            pilha.Imprime();
        }
    }

    std::cout << std::endl << "Limpando..." << std::endl;
    pilha.Limpa();
    pilha.Imprime();

    return 0;
}