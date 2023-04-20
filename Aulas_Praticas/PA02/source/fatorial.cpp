#include "fatorial.hpp"

int Fatorial::recursivo(int n){
    if (n == 0)
        return 1;
    else
        return n * recursivo(n-1);
}

int Fatorial::iterativo(int n){
    int f;
    f = 1;
    while(n > 0){
        f = f * n;
        n = n - 1;
    }
    return f;
}