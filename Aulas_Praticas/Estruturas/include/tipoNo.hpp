#pragma once

#include <iostream>

class TipoNo
{
public:
    TipoNo();
    void Imprime();

private:
    int item;
    TipoNo *esq;
    TipoNo *dir;
    friend class ArvoreBinaria;
};

TipoNo::TipoNo()
{
    item = 0;
    esq = nullptr;
    dir = nullptr;
}

void TipoNo::Imprime()
{
    std::cout << item << std::endl;
}

