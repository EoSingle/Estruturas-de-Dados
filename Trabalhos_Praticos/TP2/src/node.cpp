#include "node.hpp"

// Inicializa o nó com item vazio e próximo igual a nullptr
Node::Node(){
    this->item = Ponto();
    this->proximo = nullptr;
}

// Destrutor do nó
Node::~Node(){
    // Nada a fazer
}
