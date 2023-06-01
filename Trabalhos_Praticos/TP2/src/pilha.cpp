#include "pilha.hpp"

// Inicializa o topo como nullptr
Pilha::Pilha() {
    this->topo = nullptr;
    this->tamanho = 0;
}

// Chama o método Limpa que desempilha todos os itens da pilha
Pilha::~Pilha(){
    this->Limpa();
}

// Insere um item no topo da pilha
void Pilha::Empilha(Ponto item){
    Node* novo = new Node();       // Cria um novo nó
    novo->item = item;             // Atribui o item ao nó
    novo->proximo = this->topo;    // O próximo do novo nó aponta para o topo
    this->topo = novo;             // O topo aponta para o novo nó
    this->tamanho++;               // Incrementa o tamanho da pilha
}

// Remove o item do topo da pilha
// Retorna o item removido
Ponto Pilha::Desempilha(){
    // Testa se a pilha está vazia
    if(this->Vazia()){
        return (Ponto());
    }

    Node* aux = this->topo;            // aux aponta para o topo
    this->topo = this->topo->proximo;  // topo aponta para o próximo
    Ponto item = aux->item;            // item recebe o item do nó
    delete aux;                        // deleta o nó
    this->tamanho--;                   // decrementa o tamanho da pilha

    // Retorna o item
    return item;
}

// Desempilha todos os itens da pilha
void Pilha::Limpa(){
    // Enquanto a pilha não estiver vazia, desempilha
    while(!this->Vazia()){
        this->Desempilha();
    }
}

// Retorna o item do topo da pilha
Ponto Pilha::GetTopo(){
    // Testa se a pilha está vazia
    if(this->Vazia()){
        return Ponto();
    }

    // Retorna o item do topo
    return this->topo->item;
}

// Retorna o item abaixo do topo da pilha
Ponto Pilha::NextToTop(){
    // Testa se a pilha está vazia
    if(this->Vazia()){
        return Ponto();
    }

    // Retorna o item abaixo do topo
    return this->topo->proximo->item;
}

// Retorna o tamanho da pilha
int Pilha::GetTamanho(){
    return this->tamanho;
}

// Retorna se a pilha está vazia
bool Pilha::Vazia(){
    return this->tamanho == 0;
}

// Imprime os itens da pilha
void Pilha::Imprime(){
    // Testa se a pilha está vazia
    if(this->Vazia()){
        std::cout << "Pilha vazia" << std::endl;
        return;
    }

    Pilha aux;  // Cria uma pilha auxiliar

    // Imprime os itens da pilha
    while(!this->Vazia()){
        Ponto item = this->Desempilha();
        std::cout << item.getX() << " " << item.getY() << std::endl;
        aux.Empilha(item);
    }
    std::cout << std::endl;

    // Retorna os itens para a pilha original
    while(!aux.Vazia()){
        this->Empilha(aux.Desempilha());
    }
}
