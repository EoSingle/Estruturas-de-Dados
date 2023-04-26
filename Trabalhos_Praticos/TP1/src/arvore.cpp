#include "arvore.hpp"

// Inicializa a árvore com raiz igual a nullptr
ArvoreBinaria::ArvoreBinaria(){
    this->raiz = nullptr;
}

// Destrutor da árvore
ArvoreBinaria::~ArvoreBinaria(){
    this->Limpa();
}

// Insere uma expressão infixa na árvore
void ArvoreBinaria::InsereInfixa(std::string item){
    // Usar duas pilhas, uma para os operadores e outra para os operandos
    PilhaEncadeada *chars = new PilhaEncadeada();
    PilhaEncadeada *nodes = new PilhaEncadeada();
    
    // Percorrer a expressão
    int len = item.length();
    for(int i=0; i < len ; i++){
        // Divide a string
        std::string aux = "";
        while(item[i] != ' '){
            aux += item[i];
            if(aux == "(" || aux ==")")
                break;
            i++;
        }

        // Se a string for vazia, continua
        if(aux == ""){
            continue;
        }
        // Se a string for um parêntese, empilha em chars
        else if(aux == "("){
            TipoNo* no = new TipoNo(aux);
            chars->Empilha(no);
        }
        // Se a string for um número, empilha em nodes
        else if(aux >= "0" && aux <= "9.999"){
            TipoNo* no = new TipoNo(aux);
            nodes->Empilha(no);
        }
        // Se a string for um operador, desempilha até encontrar um operador de menor precedência ou um parêntese
        // a cada etapa, desempilha dois nós de nodes e empilha novamente em nodes um nó com o operador e os dois nós desempilhados
        // por fim, empilha o operador em chars
        else if(aux == "+" || aux == "-" || aux == "*" || aux == "/"){
            if(chars->GetTopo()->item != "("){
                while(!chars->Vazia() && (chars->GetTopo()->item == aux || ((aux == "+" || aux == "-") && (chars->GetTopo()->item == "*" || chars->GetTopo()->item == "/")))){
                    TipoNo* no = new TipoNo(chars->Desempilha()->item);
                    no->dir = nodes->Desempilha();
                    no->esq = nodes->Desempilha();
                    nodes->Empilha(no);
                }
            }
            TipoNo* no = new TipoNo(aux);
            chars->Empilha(no);
        }
        // Se a string for um fecha parêntese, desempilha o topo de chars e desempilha dois nós de nodes
        // empilha novamente em nodes um nó com o operador e os dois nós desempilhados
        // por fim, desempilha o abre parêntese correspondente
        else if(aux == ")"){
            while(chars->GetTopo()->item != "("){
                TipoNo* no = new TipoNo(chars->Desempilha()->item);
                no->dir = nodes->Desempilha();
                no->esq = nodes->Desempilha();
                nodes->Empilha(no);
            }
            chars->Desempilha();
            
        }
    }

    // Atribui a arvore resultante em nodes à raiz da árvore
    this->raiz = nodes->Desempilha();

    delete chars;
    delete nodes;
}

// Insere uma expressão Posfixa na árvore
void ArvoreBinaria::InserePosfixa(std::string item){
    // Usar uma pilha para os nós
    PilhaEncadeada *nodes = new PilhaEncadeada();
    
    // Percorrer a expressão
    int len = item.length();
    for(int i=0; i < len ; i++){
        // Divide a string
        std::string aux = "";
        while(item[i] != ' ' && i < len){
            aux += item[i];
            i++;
        }
        // Se for um número, empilha
        if(aux >="0" && aux <= "9.999"){
            TipoNo* no = new TipoNo(aux);
            nodes->Empilha(no);
        }
        // Se for um operador, desempilha dois e empilha novamente um nó com o operador e os dois nós desempilhados 
        else if(aux == "+" || aux == "-" || aux == "*" || aux == "/"){
            TipoNo* no = new TipoNo(aux);
            no->dir = nodes->Desempilha();
            no->esq = nodes->Desempilha();
            nodes->Empilha(no);
        }
    }

    // Atribui a arvore resultante em à raiz da árvore
    this->raiz = nodes->Desempilha();

    delete nodes;
}

// Percorre a árvore em pré-ordem
void ArvoreBinaria::PreOrdem(TipoNo *p){
    if(p != nullptr){
        std::cout << p->item << " ";
        this->PreOrdem(p->esq);
        this->PreOrdem(p->dir);
    }
}

// Percorre a árvore em ordem (Já adicionando parênteses)
void ArvoreBinaria::InOrdem(TipoNo *p){
    if(p != nullptr){
        std::cout << "( ";
        this->InOrdem(p->esq);
        std::cout << p->item << " ";
        this->InOrdem(p->dir);
        std::cout << ") ";
    }
}

// Percorre a árvore em pós-ordem
void ArvoreBinaria::PosOrdem(TipoNo *p){
    if(p != nullptr){
        this->PosOrdem(p->esq);
        this->PosOrdem(p->dir);
        std::cout << p->item << " ";
    }
}

// Limpa a árvore
void ArvoreBinaria::Limpa(){
    this->ApagaRecursivo(this->raiz);
    this->raiz = nullptr;
}

// Apaga a árvore recursivamente
void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
    if(p != nullptr){
        this->ApagaRecursivo(p->esq);
        this->ApagaRecursivo(p->dir);
        delete p;
    }
}

// Seleciona o tipo de caminhamento
void ArvoreBinaria::Caminha(int tipo){
    switch (tipo)
    {
    case 1:
        this->PreOrdem(this->raiz);
        break;
    case 2:
        this->InOrdem(this->raiz);
        break;
    case 3:
        this->PosOrdem(this->raiz);
        break;
    default:
        break;
    }
}
