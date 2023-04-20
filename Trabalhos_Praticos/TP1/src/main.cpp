#include "resolvedor.hpp"
#include <string>
#include <iostream>

int main(){
    Resolvedor *r = new Resolvedor();
    r->lerExpressao("2 + 4 / 2 + 8 / 4");
    r->imprimirExpressao();
    r->convertePosfixa();
    r->imprimirExpressao();

    r->converteInfixa();
    r->imprimirExpressao();

    delete r;
    
    return 0;
}