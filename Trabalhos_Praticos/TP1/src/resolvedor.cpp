// TODO: Adicionar suporte a float
// TODO: Fazer a função de resolver a expressão


#include "resolvedor.hpp"

// Inicializa a expressão com uma pilha vazia
Resolvedor::Resolvedor(){
    this->expressao = new PilhaEncadeada();
}

// Destrutor da expressão
Resolvedor::~Resolvedor(){
    delete this->expressao;
}

// Lê uma expressão e a armazena em uma pilha
// A expressão é armazenada na forma posfixa
// Expressões validas são compostas por números, espaços, parênteses e operadores (+, -, x, /)
void Resolvedor::lerExpressao(std::string expressao){
    // Limpa a expressão
    this->expressao->Limpa();

    // Cria uma pilha auxiliar
    PilhaEncadeada *aux = new PilhaEncadeada();

    // Testa se a expressão é válida
    unsigned int len = expressao.length();
    for(unsigned int i = 0; i < len; i++){
        if((expressao[i] >= '0' && expressao[i] <= '9') || expressao[i] == ' ' || expressao[i] == '(' || expressao[i] == ')'){
            continue;
        }
        else if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == 'x' || expressao[i] == '/'){
            continue;
        }
        else{
            std::cout << "Expressão inválida" << std::endl;
            return;
        }
            
    }

    // Insere os itens na pilha auxiliar
    for(unsigned int i = 0; i < len; i++){
        if(expressao[i] != ' '){
            std::string aux2 = "";
            aux2 += expressao[i];
            aux->Empilha(aux2);
        }
    }

    // Inverte a expressão e a armazena na expressão
    while(!aux->Vazia()){
        this->expressao->Empilha(aux->Desempilha());
    }

    this->convertePosfixa();

    // Deleta a pilha auxiliar
    delete aux;
}

// Converte uma expressão posfixa para uma expressão infixa
void Resolvedor::converteInfixa(){
    PilhaEncadeada *aux = new PilhaEncadeada();
    PilhaEncadeada *aux2 = new PilhaEncadeada();

    // Percorre toda a expressão
    while(!this->expressao->Vazia()){
        // Se o item for um número, empilha na pilha auxiliar
        if(this->expressao->GetTopo() >= "0" && this->expressao->GetTopo() <= "9"){
            aux->Empilha(this->expressao->GetTopo());
        }
        // Se o item for um operador, desempilha os dois últimos itens da pilha auxiliar e os coloca entre parênteses
        else if(this->expressao->GetTopo() == "+" || this->expressao->GetTopo() == "-" || this->expressao->GetTopo() == "x" || this->expressao->GetTopo() == "/"){
            std::string aux3 = "";
            aux3 += "(";
            aux3 += aux->Desempilha();
            aux3 += this->expressao->GetTopo();
            aux3 += aux->Desempilha();
            aux3 += ")";
            aux->Empilha(aux3);
        }
        this->expressao->Desempilha();
    }

    // Inverte a expressão e a armazena na expressão
    while(!aux->Vazia()){
        int len = aux->GetTopo().length();
        for(int i = 0 ; i < len; i++){
            std::string aux4 = "";
            aux4 += aux->GetTopo()[i];
            aux2->Empilha(aux4);
        }
        aux->Desempilha();
    }

    while(!aux2->Vazia()){
        this->expressao->Empilha(aux2->Desempilha());
    }

    // Deleta as pilhas auxiliares
    delete aux;
    delete aux2;
    
}

// Converte uma expressão infixa em uma expressão posfixa usando o algoritmo de Shunting-Yard || Segmentation fault
void Resolvedor::convertePosfixa(){
    PilhaEncadeada *output = new PilhaEncadeada();
    PilhaEncadeada *operadores = new PilhaEncadeada();
    // Percorrer toda a expressão
    while(!this->expressao->Vazia()){
        // Se o item for um número, empilha na pilha operandos
        if(this->expressao->GetTopo() >= "0" && this->expressao->GetTopo() <= "9"){
            output->Empilha(this->expressao->GetTopo());
        }
        // Se o item for '+' ou '-' e o topo da pilha de operadores tiver prioridade maior ou igual, desempilha o operador e o coloca na pilha operandos
        else if(this->expressao->GetTopo() == "+" || this->expressao->GetTopo() == "-"){
            while(!operadores->Vazia() && operadores->GetTopo() != "("){
                output->Empilha(operadores->Desempilha());
            }
            operadores->Empilha(this->expressao->GetTopo());
            
        }
        // Se o item for 'x' ou '/' e o topo da pilha de operadores tiver prioridade igual, desempilha o operador e o coloca na pilha operandos
        else if(this->expressao->GetTopo() == "x" || this->expressao->GetTopo() == "/"){
            while(!operadores->Vazia() && (operadores->GetTopo() == "x" || operadores->GetTopo() == "/")){
                output->Empilha(operadores->Desempilha());
            }
            operadores->Empilha(this->expressao->GetTopo());
        }
        // Se o item for um parenteses esquerdo, empilha na pilha operadores
        else if(this->expressao->GetTopo() == "("){
            operadores->Empilha(this->expressao->GetTopo());
        }
        // Se o item for um parenteses direito, desempilha os operadores e os coloca na pilha operandos até encontrar um parenteses esquerdo
        else if(this->expressao->GetTopo() == ")"){
            while(operadores->GetTopo() != "("){
                output->Empilha(operadores->Desempilha());
            }
            operadores->Desempilha();
        }
        this->expressao->Desempilha();
    }

    // Desempilha os operadores e os coloca na pilha operandos
    while(!operadores->Vazia()){
        output->Empilha(operadores->Desempilha());
    }

    // Atualiza a expressão
    this->expressao->Limpa();
    while(!output->Vazia()){
        this->expressao->Empilha(output->Desempilha());
    }

    delete output;
    delete operadores;
}

// Resolve a expressão
void Resolvedor::resolverExpressao(){
    
}

// Imprime a expressão
void Resolvedor::imprimirExpressao(){
    PilhaEncadeada *aux = new PilhaEncadeada();
    while(!this->expressao->Vazia()){
        aux->Empilha(this->expressao->Desempilha());
        std::cout << aux->GetTopo() << " ";
    }
    while(!aux->Vazia()){
        this->expressao->Empilha(aux->Desempilha());
    }
    std::cout << std::endl;
    delete aux;
}