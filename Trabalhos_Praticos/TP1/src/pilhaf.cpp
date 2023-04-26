#include "pilhaf.hpp"
#include <iostream>

// Inicializa a pilha com tamanho 0
PilhaF::PilhaF(){
    this->tamanho = 0;
}

// Retorna o tamanho da pilha
int PilhaF::GetTamanho(){
    return this->tamanho;
}

// Retorna true se a pilha estiver vazia
bool PilhaF::Vazia(){
    return this->tamanho == 0;
}
