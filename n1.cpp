#include <bits/stdc++.h>
#include "base.cpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    int n = 1000;
    fstream arq;
    arq.open("selection.dat", ios_base::out | ios_base::binary);
    if (arq.is_open())
    {
        for (int i = 1; i < 15; i++)
        {
            int v[n] = {0};
            prencher_vetor(&v[0], n, 1, 100);
            auto ini = high_resolution_clock::now();
            selection_sort(&v[0], n);
            auto fim = high_resolution_clock::now();
            duration<double> intervalo = fim - ini;
            arq << duration_cast<nanoseconds>(intervalo).count() << " " << n << "\n";
            n += 1000;
            cout << ordem_cres(&v[0], n, 0);
        }
    }
    arq.close();
    n = 100;
    arq.open("insertion.dat", ios_base::out | ios_base::binary);
    if (arq.is_open())
    {
        for (int i = 1; i < 15; i++)
        {
            int v[n] = {0};
            prencher_vetor(&v[0], n, 1, 100);
            auto ini = high_resolution_clock::now();
            insertion(&v[0], n);
            auto fim = high_resolution_clock::now();
            duration<double> intervalo = fim - ini;
            arq << duration_cast<nanoseconds>(intervalo).count() << " " << n << "\n";
            n += 1000;
            cout << ordem_cres(&v[0], n, 0);
        }
    }
    arq.close();
    n = 1000;
    arq.open("bubble.dat", ios_base::out | ios_base::binary);
    if (arq.is_open())
    {
        for (int i = 1; i < 15; i++)
        {
            int v[n] = {0};
            prencher_vetor(&v[0], n, 1, 100);
            auto ini = high_resolution_clock::now();
            bubble_sort(&v[0], n);
            auto fim = high_resolution_clock::now();
            duration<double> intervalo = fim - ini;
            arq << duration_cast<nanoseconds>(intervalo).count() << " " << n << "\n";
            n += 1000;
            cout << ordem_cres(&v[0], n, 0);
        }
    }
    arq.close();
    n = 1000;

    arq.open("heap.dat", ios_base::out | ios_base::binary);
    if (arq.is_open())
    {
        for (int i = 1; i < 15; i++)
        {
            int v[n] = {0};
            auto ini = high_resolution_clock::now();
            prencher_vetor(&v[0], n, 1, 100);
            auto fim = high_resolution_clock::now();
            duration<double> intervalo = fim - ini;
            arq << duration_cast<nanoseconds>(intervalo).count() << " " << n << "\n";
            n += 1000;
            cout << ordem_cres(&v[0], n, 0);
        }
    }
    arq.close();
    return 0;
}