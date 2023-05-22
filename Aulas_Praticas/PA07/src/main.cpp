#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono> //Para medir o tempo de CPU

void generate_random_array(int arr[], int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; i++)
       arr[i] = rand() % 100;
    //for (int i=0; i<size; i++)
    //    arr[i] = size - i;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void shellSort(int *vet, int size)
{
    int i, j, aux, h = 1;

    // Calcula o h inicial - Knuth
    do
    {
        h = h * 3 + 1;
    } while (h < size);

    // Calcula o h inicial - Potencias de 2
    //do
    //{
    //    h = h * 2;
    //} while (h < size);

    do
    {
        // Atualiza o valor de h - Knuth
        h /= 3;

        // Atualiza o valor de h - Potencias de 2
        //h /= 2;

        for (i = h; i < size; i++)
        {
            aux = vet[i];
            j = i;
            while (j > h-1 && aux < vet[j - h])
            {
                vet[j] = vet[j - h];
                j -= h;
            }
            vet[j] = aux;
        }
    } while (h > 0);
}

int main(){


    int size = 100;
    int arr1[size];
    int arr2[size];
    
    generate_random_array(arr1, size);

    // Cópia de arr1 para arr2
    for (int i = 0; i < size; i++){
        arr2[i] = arr1[i];
    }

    std::cout << "Before sorting: ";
    for (int i = 0; i < size; i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    shellSort(arr1, size);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "After sorting: ";
    for (int i = 0; i < size; i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "\nCPU Time (shellsort): " << duration << " nanoseconds" << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    heapsort(arr2, size);
    auto end2 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();
    std::cout << "CPU Time (heapsort): " << duration2 << " nanoseconds" << std::endl;

    return 0;
}
