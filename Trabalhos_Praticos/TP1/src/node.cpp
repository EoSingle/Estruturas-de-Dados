#include "node.hpp"

// Inicializa o nó com item vazio e próximo igual a nullptr
node::node(){
    this->item = "";
    this->proximo = nullptr;
}

// Destrutor do nó
node::~node(){
    // Nada a fazer
}