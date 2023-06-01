#include "ponto.hpp"

Ponto::Ponto(int x, int y)
{
    this->x = x;
    this->y = y;
}

Ponto::Ponto()
{
    this->x = 0;
    this->y = 0;
}

int Ponto::getX() { return this->x; }

int Ponto::getY() { return this->y; }

void Ponto::setXY(int x, int y)
{
    this->x = x;
    this->y = y;
}
