#include <bits/stdc++.h>
#include "colors.h"

using namespace std;

void exibir(int *v, int n, int *c);
void quicksort(int *v, int n);
int particionamento(int *v, int esq, int dir);
void troca(int *v1, int *v2);
typedef struct vetor
{
    int c;
    int p = 0;
} vec;
int main()
{
    int v[15] = {3, 2, -1, 2, -5, -4, 4, 1, 0, 2, 3, -6, 9, -9, 1},
        n = 15, c[15] = {0},
        p = 0, pos, atual;

    quicksort(v, n);
    return 0;
}

void exibir(int *v, int n, int *c)
{
    for (int i = 0; i < n; i++)
        if (c[i] == 1)
            cout << RED << v[i] << " ";
        else
            cout << RESET << v[i] << " ";
    cout << endl;
}

int particionamento(int *v, int esq, int dir)
{
    int p = esq, pos, atual;
    pos = atual = p + 1;

    while (atual <= dir)
    {
        if (v[atual] <= v[p])
        {
            troca(&v[atual], &v[pos]);
            pos++;
        }
        atual++;
    }
    pos--;

    troca(&v[p], &v[pos]);
    return pos;
}

void quicksort(int *v, int n)
{
    stack<int> pilha;
    int esq = 0, dir = n - 1, c[n] = {0};
    pilha.push(esq);
    pilha.push(dir);
    exibir(v, n, c);
    while (!pilha.empty())
    {
        dir = pilha.top();
        pilha.pop();
        esq = pilha.top();
        pilha.pop();
        int p = particionamento(v, esq, dir);
        c[p] = 1;
        if (p - 1 > esq)
        {
            pilha.push(esq);
            pilha.push(p - 1);
        }
        if (p + 1 < dir)
        {
            pilha.push(p + 1);
            pilha.push(dir);
        }
        exibir(v, n, c);
    }
}

void troca(int *v1, int *v2)
{
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}