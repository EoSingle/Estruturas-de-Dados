#include "nodef.hpp"

// Inicializa o nó como 0 e próximo igual a nullptr
nodef::nodef(){
    this->item = 0;
    this->proximo = nullptr;
}

// Destrutor do nó
nodef::~nodef(){
    // Nada a fazer
}
