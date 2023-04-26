#pragma once

class nodef {
    private:
        float item;
        nodef* proximo;
    public:
        nodef();
        ~nodef();

    friend class PilhaFloat;
};
