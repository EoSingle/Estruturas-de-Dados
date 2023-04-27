#include "resolvedor.hpp"
#include <string>
#include <iostream>

int main(){
    Resolvedor *r = new Resolvedor();
    std::string expressao;

    std::cout << std::endl <<"== Resolvedor e Conversor de expressões aritméticas ==" << std::endl << std::endl;
    std::cout << "Digite uma das opções abaixo:" << std::endl;
    std::cout << "LER <tipo> <expressão> - Lê uma expressão e a armazena" << std::endl;
    std::cout << "POSFIXA - Converte a expressão armazenada para a forma posfixa e a imprime" << std::endl;
    std::cout << "INFIXA - Converte a expressão armazenada para a forma infixa e a imprime" << std::endl;
    std::cout << "RESOLVE - Resolve a expressão armazenada e imprime o resultado" << std::endl;
    std::cout << "SAIR - Encerra o programa" << std::endl << std::endl;


    while(getline(std::cin, expressao)){
        if(expressao.find("LER INFIXA") != std::string::npos){
            expressao = expressao.substr(expressao.find("LER INFIXA") + 11);
            r->lerExpressao(expressao, 1);
        }
        else if(expressao.find("LER POSFIXA") != std::string::npos){
            expressao = expressao.substr(expressao.find("LER POSFIXA") + 11);
            r->lerExpressao(expressao, 2);
        }
        else if(expressao.find("POSFIXA") != std::string::npos) { 
            r->convertePosfixa();
        } 
        else if(expressao.find("INFIXA") != std::string::npos) {
            r->converteInfixa();
        } 
        else if(expressao.find("RESOLVE") != std::string::npos) {
            r->resolverExpressao();
        } 
        else if(expressao.find("SAIR") != std::string::npos) {
            break;
        }
        else {
            std::cout << "ERRO: OPERACAO INVALIDA" << std::endl;
        }
    }

    delete r;
    
    return 0;
}
