#include "pilha.hpp"
#include <iostream>

// Inicializa a pilha com tamanho 0
Pilha::Pilha(){
    this->tamanho = 0;
}

// Retorna o tamanho da pilha
int Pilha::GetTamanho(){
    return this->tamanho;
}

// Retorna true se a pilha estiver vazia
bool Pilha::Vazia(){
    return this->tamanho == 0;
}