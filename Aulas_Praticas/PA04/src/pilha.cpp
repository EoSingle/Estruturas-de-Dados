#include "PilhaArranjo.hpp"

PilhaArranjo::PilhaArranjo()
{
    tamanho = 0;
    topo = -1;
    filaprincipal = FilaArranjo();
    filasecundaria = FilaArranjo();
}

void PilhaArranjo::Empilha(int item){
    if(tamanho == 0){
        filaprincipal.Enfileira(item);
        topo++;
        tamanho++;
        return;
    }

    if(tamanho == MAXTAM){
        std::cout << "Pilha cheia!" << std::endl;
        return;
    }

    while(filaprincipal.GetTamanho() != 0){
        filasecundaria.Enfileira(filaprincipal.Desenfileira());
    }

    filaprincipal.Enfileira(item);

    while(filasecundaria.GetTamanho() != 0){
        filaprincipal.Enfileira(filasecundaria.Desenfileira());
    }

    topo++;
    tamanho++;
};

int PilhaArranjo::Desempilha(){
    if(tamanho == 0){
        std::cout << "Pilha vazia!" << std::endl;
        return -1;
    }

    int aux = filaprincipal.Desenfileira();
    topo--;
    tamanho--;

    return aux;
};


void PilhaArranjo::Limpa(){
    filaprincipal.Limpa();
    filasecundaria.Limpa();
    tamanho = 0;
    topo = -1;
};

void PilhaArranjo::Imprime(){
    if (tamanho == 0){
        std::cout << "Pilha está vazia!" << std::endl;
        return;
    }

    filaprincipal.Imprime();
};