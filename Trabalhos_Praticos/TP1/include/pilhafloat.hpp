#pragma once

#include "pilhaf.hpp"
#include "nodef.hpp"


class PilhaFloat : public PilhaF {
    private:
        nodef* topo;
    public:
        PilhaFloat();
        virtual ~PilhaFloat();
        void Empilha(float item) override;
        float Desempilha() override;
        void Limpa() override;

        float GetTopo();
};
