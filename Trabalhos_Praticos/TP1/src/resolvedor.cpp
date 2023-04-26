#include "resolvedor.hpp"

// Inicializa a expressão com uma árvore vazia
Resolvedor::Resolvedor(){
    this->arvore = new ArvoreBinaria();
    this->tipoExpressao = 0;
}

// Destrutor da expressão
Resolvedor::~Resolvedor(){
    delete this->arvore;
}

// Verifica se a expressão é válida
// Entrada: expressão
// Saída: true se a expressão é válida, false caso contrário
bool Resolvedor::validarExpressao(std::string expressao){
    // Verifica se a expressão é válida
    int len = expressao.length();
    for(int i = 0; i < len; i++){
        // Verifica se o caractere é válido
        if(expressao[i] != ' ' && expressao[i] != '(' && expressao[i] != ')' && expressao[i] != '+' && expressao[i] != '-' && expressao[i] != '*' && expressao[i] != '/' && expressao[i] != '.' && (expressao[i] < '0' || expressao[i] > '9')){
            return false;
        }
        if((expressao[i] == '(' || expressao[i] == ')') && tipoExpressao == 0){
            tipoExpressao = 1;
        }
    }
    // Verifica se a expressão tem o mesmo número de parênteses
    if(tipoExpressao == 1){
        int parenteses = 0;
        for(int i = 0; i < len; i++){
            // Verifica se o caractere é válido
            if(expressao[i] == '('){
                parenteses++;
            }
            else if(expressao[i] == ')'){
                parenteses--;
            }
            if(parenteses < 0){
                return false;
            }
        }
        if(parenteses != 0){
            return false;
        }
    }
    return true;
}

// Lê uma expressão e a armazena na árvore
// Entrada: expressão
// Saída: void
void Resolvedor::lerExpressao(std::string expressao){
    // Verifica se a expressão é válida
    if(!this->validarExpressao(expressao)){
        std::cout << "Expressão inválida" << std::endl;
        return;
    }
    // Limpa a árvore
    this->arvore->Limpa();

    // Insere a expressão na árvore
    if(tipoExpressao == 1)
        this->arvore->InsereInfixa(expressao);
    else
        this->arvore->InserePosfixa(expressao);

}

// Converte uma expressão posfixa para uma expressão infixa
// Caminha pela arvore usando um algoritmo de caminhamento em ordem
void Resolvedor::converteInfixa(){
    this->arvore->Caminha(2);
    std::cout << std::endl;
}

// Converte uma expressão infixa para uma expressão posfixa
// Caminha pela arvore usando um algoritmo de caminhamento em pós-ordem
void Resolvedor::convertePosfixa(){
    this->arvore->Caminha(3);
    std::cout << std::endl;
}

// Resolve a expressão
void Resolvedor::resolverExpressao(){
    this->resultado = new PilhaFloat();
    this->resolveRecursivo(this->arvore->raiz);
    std::cout << this->resultado->GetTopo() << std::endl;
}

// Resolve a expressão recursivamente
void Resolvedor::resolveRecursivo(TipoNo* p){

    if(p != nullptr){
        // Resolve a expressão recursivamente
        this->resolveRecursivo(p->esq);
        this->resolveRecursivo(p->dir);
        // Verifica se o nó é um operador
        if(p->item == "+" || p->item == "-" || p->item == "*" || p->item == "/"){
            // Desempilha os dois últimos operandos e empilha o resultado da operação
            float x1 = this->resultado->Desempilha();
            float x2 = this->resultado->Desempilha();
            if(p->item == "+"){
               this->resultado->Empilha(x2 + x1);
            }
            else if(p->item == "-"){
                this->resultado->Empilha(x2 - x1);
            }
            else if(p->item == "*"){
                this->resultado->Empilha(x2 * x1);
            }
            else if(p->item == "/"){
                if(x1 != 0)
                    this->resultado->Empilha(x2 / x1);
                else
                    std::cout << "Divisão por 0" << std::endl;
            }
        }
        // Verifica se o nó é um operando
        else if(p->item >= "0" || p->item <= "9.999"){
            // Insere o operando na pilha
            this->resultado->Empilha(std::stof(p->item));
        }
    }
}
