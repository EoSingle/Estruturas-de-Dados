#include "node.hpp"
#include "tree.hpp"
#include "huffman.hpp"

#include <iostream>
#include <fstream>

// O programa deve fazer duas coisas:
// 1. Ler um arquivo de texto e gerar um arquivo binário do texto compactado pelo algoritmo de Huffman.
// 2. Ler um arquivo binário criado pelo programa anteriormente e gerar o arquivo de texto original.
//
// O programa deve receber dois argumentos:
// 1. O primeiro argumento deve ser o nome do arquivo de texto a ser compactado ou descompactado.
// 2. O segundo argumento deve ser o nome do arquivo binário a ser gerado ou lido.
//
// Exemplo de execução:
// ./tp3 -c texto.txt binario.bin
// ./tp3 -d binario.bin texto.txt


int main(int argc, char* argv[]){
    if(argc != 4){
        if(argc == 2 && (std::string)argv[1] == "-h"){
            std::cout << "Trabalho Prático 3 - Compactação de Arquivos de Texto" << std::endl;
            std::cout << "Lucas Albano Olive Cruz - 2022036209" << std::endl;
            std::cout << "Instruções do programa:" << std::endl;
            std::cout << "-c <arquivo de texto> <arquivo binário> compacta o arquivo de texto e gera o arquivo binário" << std::endl;
            std::cout << "-d <arquivo binário> <arquivo de texto> descompacta o arquivo binário e gera o arquivo de texto" << std::endl;
            std::cout << "-h exibe as instruções do programa" << std::endl;
            return 0;
        }
        std::cout << "ERRO: Número de argumentos inválido." << std::endl;
        std::cout << "Use a opção -h para exibir as instruções do programa." << std::endl;
        return 1;
    }

    std::string option = argv[1];
    std::string input = argv[2];
    std::string output = argv[3];

    if(option == "-c"){
        std::ifstream file(input);
        if(!file.is_open()){
            std::cout << "ERRO: Não foi possível abrir o arquivo de entrada." << std::endl;
            return 1;
        }

        std::ofstream binary(output, std::ios::binary);
        if(!binary.is_open()){
            std::cout << "ERRO: Não foi possível abrir o arquivo de saída." << std::endl;
            return 1;
        }

        Huffman huffman;
        huffman.compress(file, binary);
        file.close();
        binary.close();
    }
    else if(option == "-d"){
        std::ifstream binary(input, std::ios::binary);
        if(!binary.is_open()){
            std::cout << "ERRO: Não foi possível abrir o arquivo de entrada." << std::endl;
            return 1;
        }

        std::ofstream file(output);
        if(!file.is_open()){
            std::cout << "ERRO: Não foi possível abrir o arquivo de saída." << std::endl;
            return 1;
        }

        Huffman huffman;
        huffman.decompress(binary, file);
        binary.close();
        file.close();
    }
    else{
        std::cout << "ERRO: Opção inválida." << std::endl;
        std::cout << "Use a opção -h para exibir as instruções do programa." << std::endl;
        return 1;
    }
    
    return 0;
}
