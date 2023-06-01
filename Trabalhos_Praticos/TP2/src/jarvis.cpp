#include "jarvis.hpp"

// Construtor
Jarvis::Jarvis(){
    this->vertices = Pilha();
}

// Destrutor - Não faz nada
Jarvis::~Jarvis(){}

// Define a orientação de três pontos
// 0 --> p, q e r são colineares
// 1 --> Sentido horário
// 2 --> Sentido anti-horário
int Jarvis::orientation(Ponto p, Ponto q, Ponto r)
{
    int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
              (q.getX() - p.getX()) * (r.getY() - q.getY());
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2;  // horario ou anti-horario
}


// Encontra o fecho convexo de um conjunto de n pontos
void Jarvis::convexHull(Ponto pontos[], int n){
	// Caso tenha menos de 3 pontos, não há fecho convexo
    if (n < 3) return;

    // Encontra o ponto mais a esquerda no plano
    int l = 0;
    for (int i = 1; i < n; i++)
        if (pontos[i].getX() < pontos[l].getX())
            l = i;
  
    // Se move em sentido anti-horário até voltar ao ponto inicial
    int p = l, q;
    do
    {
        // Adiciona o ponto atual a pilha de saída
        this->vertices.Empilha(pontos[p]);
  
        // Busca por um ponto 'q' tal que a orientação de (p, q, x) seja anti-horária para todo ponto 'x'
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           // Se i é mais anti-horário que q, atualiza q
           if (orientation(pontos[p], pontos[i], pontos[q]) == 2)
               q = i;
        }
  
        // Agora q é o ponto mais anti-horário em relação a p
        p = q;
  
    } while (p != l);
}

// Imprime o fecho convexo
void Jarvis::printPilha(){
    this->vertices.Imprime();
}
