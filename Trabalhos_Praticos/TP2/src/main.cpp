#include "graham.hpp"
#include "jarvis.hpp"
#include "ponto.hpp"

#include <iostream>
#include <chrono>
#include <iomanip>
#include <thread>

int main(){
    Jarvis jarvis;
    Graham graham;

    Ponto points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);

    std::cout << "FECHO CONVEXO:\n";

    graham.convexHull(points, n, 2);
    graham.printPilha();

    auto start = std::chrono::high_resolution_clock::now();
    graham.convexHull(points, n, 1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    double tempo = duration.count() * 1e-9; 

    std::cout << "GRAHAM+MERGESORT: " << std::fixed << std::setprecision(3) << tempo << "s\n";


    return 0;
}
