#include "TipoNo.hpp"

// Cria um nó vazio
TipoNo::TipoNo(){
    this->item = "";
    this->esq = nullptr;
    this->dir = nullptr;

}

// Cria um nó com o item passado por parâmetro
TipoNo::TipoNo(std::string item){
    this->item = item;
    this->esq = nullptr;
    this->dir = nullptr;
}

// Cria um nó com os mesmos atributos do nó passado por parâmetro
TipoNo::TipoNo(TipoNo *no){
    this->item = no->item;
    this->esq = no->esq;
    this->dir = no->dir;
}
