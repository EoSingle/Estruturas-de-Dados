// TODO: Criar uma exceção para um erro de leitura das linhas do arquivo de entrada

#include "graham.hpp"
#include "jarvis.hpp"
#include "ponto.hpp"

#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

const int MAX = 100000;

int main(int argc, char *argv[]){
    if(argc < 2){
        std::cout << "Usage: ./bin/programa <input_file>\n";
        return 1;
    }

    Jarvis jarvis;
    Graham graham;

    Ponto points[MAX];
    int n = 0;
    std::ifstream input_file(argv[1]);

    if(input_file.is_open()){
        int x, y;
        while(input_file >> x >> y){
            if(n >= MAX){
                std::cout << "Número máximo de pontos excedido. Alguns pontos foram descartados.\n";
                break;
            }
            points[n].setXY(x, y);
            n++;
        }
        input_file.close();
    } else {
        std::cout << "Erro ao abrir o arquivo de entrada\n";
        return 1;
    }

    graham.convexHull(points, n, 2);
    if(graham.isInvalid()){
        std::cout << "Pontos inválidos\n";
        return 1;
    }
    std::cout << "FECHO CONVEXO:\n";
    graham.printPilha();

    auto start = std::chrono::high_resolution_clock::now();
    graham.convexHull(points, n, 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    double tempo = duration.count() * 1e-9; 

    std::cout << "GRAHAM+MERGESORT: " << std::fixed << std::setprecision(6) << tempo << "s\n";

    start = std::chrono::high_resolution_clock::now();
    graham.convexHull(points, n, 2);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    tempo = duration.count() * 1e-9;

    std::cout << "GRAHAM+INSERTIONSORT: " << std::fixed << std::setprecision(6) << tempo << "s\n";

    start = std::chrono::high_resolution_clock::now();
    graham.convexHull(points, n, 3);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    tempo = duration.count() * 1e-9;

    std::cout << "GRAHAM+BUCKETSORT: " << std::fixed << std::setprecision(6) << tempo << "s\n";

    start = std::chrono::high_resolution_clock::now();
    jarvis.convexHull(points, n);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    tempo = duration.count() * 1e-9;

    std::cout << "JARVIS: " << std::fixed << std::setprecision(6) << tempo << "s\n";

    return 0;
}
