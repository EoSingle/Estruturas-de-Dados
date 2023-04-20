#include "resolvedor.hpp"
#include <string>
#include <iostream>

int main(){
    Resolvedor *r = new Resolvedor();
    r->lerExpressao("2 + ( 3 x 4 ) + 5");
    r->imprimirExpressao();

    delete r;
    
    return 0;
}