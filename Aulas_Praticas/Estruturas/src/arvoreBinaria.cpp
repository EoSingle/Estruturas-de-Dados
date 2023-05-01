#include "arvoreBinaria.hpp"

ArvoreBinaria::ArvoreBinaria()
{
    raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria()
{
    Limpa();
}

void ArvoreBinaria::Insere(int item)
{
    InsereRecursivo(raiz, item);
}
void ArvoreBinaria::InsereRecursivo(TipoNo *&p, int item)
{
    if (p == nullptr)
    {
        p = new TipoNo();
        p->item = item;
    }
    else
    {
        if (item < p->item)
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void ArvoreBinaria::PreOrdem(TipoNo *p)
{
    if (p != nullptr)
    {
        p->Imprime();
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void ArvoreBinaria::InOrdem(TipoNo *p)
{
    if (p != nullptr)
    {
        InOrdem(p->esq);
        p->Imprime();
        InOrdem(p->dir);
    }
}

void ArvoreBinaria::PosOrdem(TipoNo *p)
{
    if (p != nullptr)
    {
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        p->Imprime();
    }
}

/*void ArvoreBinaria::CaminhaNivel()
{
    FilaArranjo F; // fila de apontadores para nos
    TipoNo *p;
    F.Enfileira(raiz);
    while (!F.Vazia())
    {
        p = F.Desenfileira();
        if (p != NULL)
        {
            p->item.Imprime();
            F.Enfileira(p->esq);
            F.Enfileira(p->dir);
        }
    }
}*/

void ArvoreBinaria::Limpa()
{
    ApagaRecursivo(raiz);
    raiz = nullptr;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p)
{
    if (p != nullptr)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}