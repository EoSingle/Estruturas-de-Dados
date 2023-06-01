#pragma once

class Ponto {
    private:
        int x;
        int y;

    public:
        Ponto(int x, int y);
        Ponto();
        int getX();
        int getY();
        void setXY(int x, int y);

};
