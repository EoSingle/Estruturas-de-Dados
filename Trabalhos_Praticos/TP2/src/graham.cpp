#include "graham.hpp"

// Construtor da classe Graham
// Inicializa o ponto p0 com o ponto (0, 0)
// Inicializa a pilha de vertices
Graham::Graham() {
    this->p0 = Ponto(0, 0);
    this->vertices = Pilha();
}

// Destrutor da classe Graham - não faz nada
Graham::~Graham() {}

// Define a orientação de três pontos
// 0 --> p, q e r são colineares
// 1 --> Sentido horário
// 2 --> Sentido anti-horário
int Graham::orientation(Ponto p, Ponto q, Ponto r)
{
    int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
              (q.getX() - p.getX()) * (r.getY() - q.getY());
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2;  // horario ou anti-horario
}

// Retorna o quadrado da distância entre p1 e p2
int Graham::distSq(Ponto p1, Ponto p2)
{
    return (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) +
           (p1.getY() - p2.getY())*(p1.getY() - p2.getY());
}

// Compara dois pontos
//  1 --> p1 é maior que p2
// -1 --> p1 é menor que p2
int Graham::compare(const void *vp1, const void *vp2)
{
    Ponto *p1 = (Ponto *)vp1;
    Ponto *p2 = (Ponto *)vp2;
 
    // Encontra a orientação
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
    return (o == 2)? -1: 1;
}

// Encontra o ponto mais a esquerda e mais abaixo e o coloca na posição 0
void Graham::ordMinY(Ponto pontos[], int n){
    int min = 0;
    int ymin = pontos[0].getY();
    for( int i = 1; i < n; i++ ){
        int y = pontos[i].getY();
        if((y < ymin) || (ymin == y && 
            pontos[i].getX() < pontos[min].getX()) ){
            ymin = pontos[i].getY();
            min = i;
        }
    }

    // Troca o ponto mais a esquerda e mais abaixo com o ponto na posição 0
    Ponto aux = pontos[0];
    pontos[0] = pontos[min];
    pontos[min] = aux;
}

// Algoritmo de ordenação MergeSort
void Graham::MergeSort(Ponto pontos[], int left, int right){
    // Passo base
    if(left < right){
        // Encontra o ponto médio
        int mid = (left + right)/2;

        // Ordena a primeira e a segunda metade
        MergeSort(pontos, left, mid);
        MergeSort(pontos, mid+1, right);

        // Junta as metades as ordenando
        Merge(pontos, left, mid, right);
    }
}

// Junta dois subarrays de pontos
void Graham::Merge(Ponto pontos[], int const left, int const mid, int const right){
    // Define o tamanho dos subarrays
    int subArray1 = mid - left + 1;
    int subArray2 = right - mid;

    // Cria os arrays temporários
    Ponto *leftArray = new Ponto[subArray1],
          *rightArray = new Ponto[subArray2];

    // Copia os dados para os arrays temporários
    for(int i = 0; i < subArray1; i++)
        leftArray[i] = pontos[left + i];
    for(int j = 0; j < subArray2; j++)
        rightArray[j] = pontos[mid + 1 + j];

    int indexOfSubArray1 = 0,        // Índice inicial do primeiro subarray
        indexOfSubArray2 = 0,        // Índice inicial do segundo subarray
        indexOfMergedArray = left;   // Índice inicial do array mesclado

    // Junta os subarrays
    while(indexOfSubArray1 < subArray1 && indexOfSubArray2 < subArray2){
        // Compara os pontos dos subarrays de acordo com o ângulo polar
        if(compare(&leftArray[indexOfSubArray1], &rightArray[indexOfSubArray2]) == -1){
            pontos[indexOfMergedArray] = leftArray[indexOfSubArray1];
            indexOfSubArray1++;
        } else {
            pontos[indexOfMergedArray] = rightArray[indexOfSubArray2];
            indexOfSubArray2++;
        }
        indexOfMergedArray++;
    }

    // Copia os elementos restantes da esquerda, se houver
    while(indexOfSubArray1 < subArray1){
        pontos[indexOfMergedArray] = leftArray[indexOfSubArray1];
        indexOfSubArray1++;
        indexOfMergedArray++;
    }

    // Copia os elementos restantes da direita, se houver
    while(indexOfSubArray2 < subArray2){
        pontos[indexOfMergedArray] = rightArray[indexOfSubArray2];
        indexOfSubArray2++;
        indexOfMergedArray++;
    }

    // Libera a memória dos arrays temporários
    delete[] leftArray;
    delete[] rightArray;
}

// Algoritmo de ordenação InsertionSort
void Graham::InsertionSort(Ponto pontos[], int n){
    int i, j;
    Ponto aux;
    for(i = 1; i < n; i++){
        aux = pontos[i];
        j = i - 1;

        // Move os elementos do vetor que são maiores que a chave para uma posição a frente
        // da sua posição atual
        while(j >= 0 && (compare(&pontos[j], &aux) == 1)){
            pontos[j+1] = pontos[j];
            j--;
        }
        pontos[j+1] = aux;
    }
}

// Função auxiliar para BucketSort - Calcula o angulo de um vetor
double Graham::Angle(Ponto p){
    return atan2(p.getY() - p0.getY(), p.getX() - p0.getX()) * 180 / M_PI;
}

// Algoritmo de ordenação BucketSort - Utiliza o InsertionSort para ordenar os buckets
void Graham::BucketSort(Ponto pontos[], int n){
    double minAngle = Angle(pontos[0]);
    double maxAngle = Angle(pontos[0]);

    for(int i = 1; i < n; i++){
        double angle = Angle(pontos[i]);
        if(angle < minAngle)
            minAngle = angle;
        if(angle > maxAngle)
            maxAngle = angle;
    }

    // Cria um vetor de buckets
    const int numBuckets = n;
    Ponto** buckets = new Ponto*[numBuckets];
    int* bucketSizes = new int[numBuckets]{0};

    // Coloca os pontos nos buckets
    for(int i = 0; i < n; i++){
        double angle = Angle(pontos[i]);
        int bucket = (int)((angle - minAngle) / (maxAngle - minAngle) * (numBuckets - 1));
        if(bucketSizes[bucket] == 0)
            buckets[bucket] = new Ponto[n];
        buckets[bucket][bucketSizes[bucket]++] = pontos[i];
    }

    // Ordena os buckets e junta os pontos em um vetor
    int index = 0;
    for(int i = 0; i < numBuckets; i++){
        if(bucketSizes[i] == 0)
            continue;
        if(bucketSizes[i] == 1){
            pontos[index++] = buckets[i][0];
            delete[] buckets[i];
            continue;
        }
        InsertionSort(buckets[i], bucketSizes[i]);
        for(int j = 0; j < bucketSizes[i]; j++)
            pontos[index++] = buckets[i][j];
        delete[] buckets[i];
    }

    delete[] buckets;
    delete[] bucketSizes;
    
}


// Ordena os pontos de acordo com o ângulo polar
void Graham::polarSort(Ponto pontos[], int n, int type){
    switch (type)
    {
    case 1:
        MergeSort(pontos, 0, n-1);
        break;
    case 2:
        InsertionSort(pontos, n);
        break;
    case 3:
        BucketSort(pontos, n);
        break;
    default:
        InsertionSort(pontos, n);
        break;
    }
}

// Encontra o fecho convexo de um conjunto de pontos
// type = 1 -> MergeSort
// type = 2 -> InsertionSort
// type = 3 -> BucketSort
void Graham::convexHull(Ponto pontos[], int n, int type){
    // Encontra o ponto mais a esquerda e mais abaixo e o coloca na posição 0
    ordMinY(pontos, n);

    p0 = pontos[0];

    // Cria um vetor auxiliar sem o elemento p0
    Ponto pontosAux[n-1];
    for(int i = 0; i < n-1; i++)
        pontosAux[i] = pontos[i+1];

    // Ordena os pontos restantes pelo ângulo polar formado com p0
    polarSort(pontosAux, n-1, type);

    // Retorna com os pontos ordenados pelo ângulo polar ao vetor original
    for(int i = 0; i < n-1; i++)
        pontos[i+1] = pontosAux[i];

    // Se dois ou mais pontos fazem o mesmo ângulo com p0, remove todos menos o mais distante
    int m = 1;                    // Inicializa o tamanho do array modificado
    for(int i = 1; i < n; i++){
        // Mantém os pontos que não fazem o mesmo ângulo com p0
        while(i < n-1 && orientation(p0, pontos[i], pontos[i+1]) == 0)
            i++;

        pontos[m] = pontos[i];
        m++;                      // Atualiza o tamanho do array modificado
    }

    // Se o número de pontos for menor que 3, não há fecho convexo
    if(m < 3) return;

    // Cria uma pilha vazia e empilha os três primeiros pontos
    vertices.Limpa();
    vertices.Empilha(pontos[0]);
    vertices.Empilha(pontos[1]);
    vertices.Empilha(pontos[2]);

    // Processa os pontos restantes
    for(int i = 3; i < m; i++){
        // Se o ponto atual não fizer um ângulo à esquerda com o topo da pilha edges, remove o topo
        while(orientation(vertices.NextToTop(), vertices.GetTopo(), pontos[i]) != 2)
            vertices.Desempilha();
        vertices.Empilha(pontos[i]);
    }
}

// Imprime a pilha de pontos
void Graham::printPilha(){
    vertices.Imprime();
}

// Testa se o conjunto de pontos é válido
bool Graham::isInvalid(){
    return vertices.Vazia();
}
