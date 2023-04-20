#ifndef FILACIRCULAR_HPP
#define FILACIRCULAR_HPP

#include "Fila.hpp"
#include <iostream>

class FilaArranjo : public Fila
{
 public:
    FilaArranjo();
    void Enfileira(int item) override;
    int Desenfileira() override;
    void Limpa() override;
    void Imprime();
 private:
    int frente;
    int tras;
    static const int MAXTAM = 10;
    int itens[MAXTAM];
};

#endif
