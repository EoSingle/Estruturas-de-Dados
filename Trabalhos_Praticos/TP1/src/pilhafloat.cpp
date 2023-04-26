#include "pilhafloat.hpp"

// Chama o construtor da classe pai e inicializa o topo como nullptr
PilhaFloat::PilhaFloat() : PilhaF(){
    this->topo = nullptr;
}

// Chama o método Limpa que desempilha todos os itens da pilha
PilhaFloat::~PilhaFloat(){
    this->Limpa();
}

// Insere um item no topo da pilha
void PilhaFloat::Empilha(float item){
    nodef* novo = new nodef();     // Cria um novo nó
    novo->item = item;             // Atribui o item ao nó
    novo->proximo = this->topo;    // O próximo do novo nó aponta para o topo
    this->topo = novo;             // O topo aponta para o novo nó
    this->tamanho++;               // Incrementa o tamanho da pilha
}

// Remove o item do topo da pilha
// Retorna o item removido
float PilhaFloat::Desempilha(){
    // Testa se a pilha está vazia
    if(this->Vazia()){
        return -1;
    }

    nodef* aux = this->topo;           // aux aponta para o topo
    this->topo = this->topo->proximo;  // topo aponta para o próximo
    float item = aux->item;            // item recebe o item do nó
    delete aux;                        // deleta o nó
    this->tamanho--;                   // decrementa o tamanho da pilha

    // Retorna o item
    return item;
}

// Desempilha todos os itens da pilha
void PilhaFloat::Limpa(){
    // Enquanto a pilha não estiver vazia, desempilha
    while(!this->Vazia()){
        this->Desempilha();
    }
}

// Retorna o item do topo da pilha
float PilhaFloat::GetTopo(){
    // Testa se a pilha está vazia
    if(this->Vazia()){
        return -1;
    }

    // Retorna o item do topo
    return this->topo->item;
}
