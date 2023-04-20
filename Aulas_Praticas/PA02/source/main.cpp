#include "fatorial.hpp"
#include "fibonacci.hpp"
#include <getopt.h>
#include <iostream>
#include <cstdlib>

using namespace std;

Fibonacci fib;
Fatorial fat;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cerr << "Erro: número insuficiente de argumentos." << endl;
        return EXIT_FAILURE;
    }

    // Obter a operação a ser executada a partir da flag
    char op = argv[1][1];
    int n = atoi(argv[2]);

    // Executar a operação apropriada
    switch (op) {
        case 'f':
            // Fatorial
            if (argv[1][0] == 'r') {
                cout << fat.recursivo(n) << endl;
            } else {
                cout << fat.iterativo(n) << endl;
            }
            break;
        case 'b':
            // Fibonacci
            if (argv[1][0] == 'r') {
                cout << fib.recursivo(n) << endl;
            } else {
                cout << fib.iterativo(n) << endl;
            }
            break;
        default:
            cerr << "Erro: operação inválida." << endl;
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}