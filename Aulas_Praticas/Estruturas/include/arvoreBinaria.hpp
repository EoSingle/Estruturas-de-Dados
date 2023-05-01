#pragma once

#include <tipoNo.hpp>

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(int item);
    void Caminha(int tipo);
    void Limpa();

private:
    void InsereRecursivo(TipoNo *&p, int item);
    void ApagaRecursivo(TipoNo *p);
    void PorNivel();
    void PreOrdem(TipoNo *p);
    void InOrdem(TipoNo *p);
    void PosOrdem(TipoNo *p);
    TipoNo *raiz;
};