#include "resolvedor.hpp"

// Inicializa a expressão com uma árvore vazia
Resolvedor::Resolvedor(){
    this->arvore = new ArvoreBinaria();
}

// Destrutor da expressão
Resolvedor::~Resolvedor(){
    delete this->arvore;
}

// Verifica se a expressão é válida
// Entrada: expressão
// Saída: true se a expressão é válida, false caso contrário
bool Resolvedor::validarExpressao(std::string expressao, int tipoExpressao){
    // Verifica se a expressão é válida
    switch(tipoExpressao){
        case 1: {
            int len = expressao.length();
            for(int i = 0; i < len; i++){
                // Verifica se o caractere é válido
                if(expressao[i] != ' ' && expressao[i] != '(' && expressao[i] != ')' && expressao[i] != '+' && expressao[i] != '-' && expressao[i] != '*' && expressao[i] != '/' && expressao[i] != '.' && (expressao[i] < '0' || expressao[i] > '9')){
                    return false;
                }
            }

            // Verifica se a expressão tem o mesmo número de parênteses
            int parenteses = 0;
            for(int i = 0; i < len; i++){
                // Conta o número de parênteses
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

            // Verifica se a expressão tem um operador entre dois operandos
            bool operador = false;
            for(int i = 0; i < len; i++){
                if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/'){
                    if(operador){
                        return false;
                    }
                    operador = true;
                }
                else if(expressao[i] >= '0' && expressao[i] <= '9'){
                    operador = false;
                }
            }

            // Verifica se a expressão tem operadores suficientes
            int operadores = 0;
            int operandos = 0;

            for(int i = 0; i < len; i++){
                // Divide a expressão
                std::string aux = "";
                while(expressao[i] != ' '){
                    aux += expressao[i];
                    if(aux == "(" || aux ==")")
                        break;
                    i++;
                }
                // Conta os operadores e operandos
                if(aux == "+" || aux == "-" || aux == "*" || aux == "/"){
                    operadores++;
                }
                else if(aux >= "0" && aux <= "9.99"){
                    operandos++;
                }
            }
            
            if(operadores != operandos - 1){
                return false;
            }

            break;
        }
        case 2: {
            int len = expressao.length();
            for(int i = 0; i < len; i++){
                // Verifica se o caractere é válido
                if(expressao[i] != ' ' && expressao[i] != '+' && expressao[i] != '-' && expressao[i] != '*' && expressao[i] != '/' && expressao[i] != '.' && (expressao[i] < '0' || expressao[i] > '9')){
                    return false;
                }
            }

            // Verifica se a expressão tem operadores suficientes
            int operadores = 0; 
            int operandos = 0;

            for(int i = 0; i < len; i++){
                // Divide a expressão
                std::string aux = "";
                while(expressao[i] != ' ' && i < len){
                    aux += expressao[i];
                    i++;
                }
                // Conta os operadores e operandos
                if(aux == "+" || aux == "-" || aux == "*" || aux == "/"){
                    operadores++;
                }
                else if(aux >= "0" && aux <= "9.99"){
                    operandos++;
                }
            }

            if(operadores != operandos - 1){
                return false;
            }

            break;
        }
        default:
            break;
        
    }
    return true;

}

// Lê uma expressão e a armazena na árvore
// Entrada: expressão
// Saída: void
void Resolvedor::lerExpressao(std::string expressao, int tipoExpressao){
    // Verifica se a expressão é válida
    if(!this->validarExpressao(expressao, tipoExpressao)){
        std::cout << "ERRO: EXP NAO VALIDA" << std::endl;
        return;
    }

    // Limpa a árvore
    this->arvore->Limpa();

    // Insere a expressão na árvore
    switch (tipoExpressao)
    {
    case 1:
        this->arvore->InsereInfixa(expressao);
        std::cout << "EXPRESSAO OK: ";
        this->arvore->Caminha(2);
        std::cout << std::endl;
        break;
    case 2:
        this->arvore->InserePosfixa(expressao);
        std::cout << "EXPRESSAO OK: ";
        this->arvore->Caminha(3);
        std::cout << std::endl;
        break;
    default:
        break;
    }
}

// Converte uma expressão posfixa para uma expressão infixa
// Caminha pela arvore usando um algoritmo de caminhamento em ordem
void Resolvedor::converteInfixa(){
    // Verifica se a árvore está vazia
    if(this->arvore->Vazia()){
        std::cout << "ERRO: EXP NAO EXISTE" << std::endl;
        return;
    }
    std::cout << "INFIXA: ";
    this->arvore->Caminha(2);
    std::cout << std::endl;
}

// Converte uma expressão infixa para uma expressão posfixa
// Caminha pela arvore usando um algoritmo de caminhamento em pós-ordem
void Resolvedor::convertePosfixa(){
    // Verifica se a árvore está vazia
    if(this->arvore->Vazia()){
        std::cout << "ERRO: EXP NAO EXISTE" << std::endl;
        return;
    }
    std::cout << "POSFIXA: ";
    this->arvore->Caminha(3);
    std::cout << std::endl;
}

// Resolve a expressão
void Resolvedor::resolverExpressao(){
    // Verifica se a árvore está vazia
    if(this->arvore->Vazia()){
        std::cout << "ERRO: EXP NAO EXISTE" << std::endl;
        return;
    }
    // Cria uma pilha para armazenar o resultado
    this->resultado = new PilhaFloat();
    this->resolveRecursivo(this->arvore->raiz);
    std::cout << "VAL: ";
    std::cout << this->resultado->GetTopo() << std::endl;
}

// Resolve a expressão recursivamente
void Resolvedor::resolveRecursivo(TipoNo* p){

    if(p != nullptr){
        // Percorre a expressão recursivamente em pós-ordem
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
                if(x1 != 0){
                    this->resultado->Empilha(x2 / x1);
                }
                else{
                    std::cout << "ERRO: DIVISAO POR ZERO" << std::endl;
                    this->resultado->Empilha(0);
                    return;
                }
            }
        }
        // Verifica se o nó é um operando
        else if(p->item >= "0" || p->item <= "9.999"){
            // Insere o operando na pilha
            this->resultado->Empilha(std::stof(p->item));
        }
    }
}
