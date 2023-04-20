#include "FilaCircular.hpp"

FilaArranjo::FilaArranjo() : Fila()
{
    frente = 0;
    tras = 0;
}

void FilaArranjo::Enfileira(int item) {
    if (tamanho == MAXTAM){
        std::cout << "Fila Cheia!" << std::endl;
        return;
    }

    itens[tras] = item;
    tras = (tras + 1) % MAXTAM;
    tamanho++;
}

int FilaArranjo::Desenfileira() {
    int aux;

    if (tamanho == 0){
        std::cout << "Fila está vazia!" << std::endl;
        return -1;
    }

    aux = itens[frente];
    frente = (frente + 1) % MAXTAM;
    tamanho--;

    return aux;
}

void FilaArranjo::Limpa() {
    frente = 0;
    tras = 0;
    tamanho = 0;
}

void FilaArranjo::Imprime(){
    int aux = frente;

    if (tamanho == 0){
        std::cout << "Fila está vazia!" << std::endl;
        return;
    }

    for (int i = 0; i < tamanho; i++){
        std::cout << itens[aux] << " ";
        aux = (aux + 1) % MAXTAM;
    }

    std::cout << std::endl;
}