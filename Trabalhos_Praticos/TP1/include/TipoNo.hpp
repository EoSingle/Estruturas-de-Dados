#pragma once

#include <string>

class TipoNo
{
    private:
        std::string item;
        TipoNo *esq;
        TipoNo *dir;

    public:
        TipoNo();
        TipoNo(std::string item);
        TipoNo(TipoNo *no);

    friend class ArvoreBinaria;
    friend class PilhaEncadeada;
};
