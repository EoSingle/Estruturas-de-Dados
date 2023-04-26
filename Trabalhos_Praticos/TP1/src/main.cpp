#include "resolvedor.hpp"
#include <string>
#include <iostream>

int main(){
    Resolvedor *r = new Resolvedor();
    r->lerExpressao("4.721663  6.714296  +  0.838888  +  4.205877  4.278166  +  *  4.863587  2.466270  *  / ");
    r->converteInfixa();
    r->convertePosfixa();
    r->resolverExpressao();

    delete r;
    
    return 0;
}
