#include "huffman.hpp"
#include <iostream>
#include <fstream>

//#include <chrono>  // Para medir o tempo de execução
//#include <iomanip> // Para formatar a saída do tempo de execução

int main(int argc, char* argv[]){
    if(argc != 4){
        if(argc == 2 && (std::string)argv[1] == "-h"){
            std::cout << "Trabalho Prático 3 - Compactação de Arquivos de Texto" << std::endl;
            std::cout << "Lucas Albano Olive Cruz - 2022036209" << std::endl;
            std::cout << "Instruções do programa:" << std::endl;
            std::cout << "-c <arquivo de texto> <arquivo binário> // compacta o arquivo de texto para um arquivo binário" << std::endl;
            std::cout << "-d <arquivo binário> <arquivo de texto> // descompacta o arquivo binário e remonta o arquivo de texto" << std::endl;
            std::cout << "-h // exibe as instruções do programa" << std::endl;
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

        //auto start = std::chrono::high_resolution_clock::now();
        Huffman huffman;
        huffman.compress(file, binary);
        //auto end = std::chrono::high_resolution_clock::now();

        //std::cout<< "Arquivo compactado com sucesso." << std::endl << std::endl;
        //std::cout << "Arquivo de entrada: " << input << std::endl;
        //file.clear();
        //std::cout << "Tamanho do arquivo de entrada: " << file.tellg() << " bytes" << std::endl << std::endl;

        //std::cout << "Arquivo de saída: " << output << std::endl;
        //std::cout << "Tamanho do arquivo de saída: " << binary.tellp() << " bytes" << std::endl << std::endl;

        //std::cout << "Taxa de compressão: " << std::fixed << std::setprecision(2) << ( 1 - (double)binary.tellp() / file.tellg()) * 100 << "%" << std::endl;

        file.close();
        binary.close();

        //auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        //double tempo = duration.count() * 1e-9;
        //std::cout << std::endl;
        //std::cout << "Tempo de execução: " << std::fixed << std::setprecision(6) << tempo << "s" << std::endl;

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

        //auto start = std::chrono::high_resolution_clock::now();
        Huffman huffman;
        huffman.decompress(binary, file);
        //auto end = std::chrono::high_resolution_clock::now();

        //std::cout<< "Arquivo descompactado com sucesso." << std::endl << std::endl;

        //std::cout << "Arquivo descompactado em: " << output << std::endl << std::endl;

        binary.close();
        file.close();

        //auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        //double tempo = duration.count() * 1e-9;
        //std::cout << "Tempo de execução: " << std::fixed << std::setprecision(6) << tempo << "s" << std::endl;
    
    }
    else{
        std::cout << "ERRO: Opção inválida." << std::endl;
        std::cout << "Use a opção -h para exibir as instruções do programa." << std::endl;
        return 1;
    }
    
    return 0;
}
