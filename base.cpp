#include <bits/stdc++.h>

using namespace std;

void trocar(int *v1, int *v2);
void exibir(int *v, int ini, int fim);
void prencher_vetor(int *v, int tam, int mim, int max);
void prencher_vetor_Simples(int *v, int tam);
int busca_binaria(int *v, int tam, int x);
void troca(int *v, int a, int b);
int menor_poss(int *v, int tam, int index);
int maior_poss(int *v, int tam, int index);
void bubble_sort(int *v, int tam);
int busca_sequencial(int *v, int tam, int x);
void exibir_simples(int *v, int tam);
int busca_sequencial_ord(int *v, int tam, int x);
void quicksort(int *v, int n);
int particionamento(int *v, int esq, int dir);
void heapify(int *v, int n, int idx);
void maxheap(int *v, int n);
void heapsort(int *v, int n);
bool ordem_des(int *v, int n);
int ordem_cres(int *v, int n, int c);
void limpa(int *v, int tam);
void insertion(int *v, int n);

#define RED "\x1b[32m";
void limpa(int *v, int tam)
{

    for (int i = 0; i <= tam; i++)
        v[i] = 0;
}
void exibir(int *v, int ini, int fim)
{
    cout << "|";
    for (int i = ini; i < fim; i++)
    {
        cout << v[i] << "|";
    }
    cout << "\n";
}
void exibir_simples(int *v, int tam)
{
    cout << "|";
    for (int i = 0; i < tam; i++)
    {
        cout << v[i] << "|";
    }
    cout << "\n";
}
void prencher_vetor(int *v, int tam, int mim, int max)
{
    srand(time(NULL));
    for (int i = 0; i <= tam; i++)
        v[i] = mim + rand() % max;
}
void prencher_vetor_Simples(int *v, int tam)
{
    srand(time(NULL));
    for (int i = 0; i <= tam; i++)
        v[i] = 1 + rand() % 100;
}

void bubble_sort(int *v, int tam)
{

    for (int i = 0; i <= tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (v[j] > v[j + 1])
                troca(v, j, j + 1);
        }
    }
}
void troca(int *v, int a, int b)
{
    int aux;
    aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}
int menor_poss(int *v, int tam, int index)
{
    int aux = index;
    for (int i = index + 1; i <= tam; i++)
    {
        if (v[aux] > v[i])
            aux = i;
    }
    return aux;
}
int maior_poss(int *v, int tam, int index)
{
    int aux = index;
    for (int i = index + 1; i <= tam; i++)
    {
        if (v[aux] < v[i])
            aux = i;
    }
    return aux;
}
void selection_sort(int *v, int tam)
{
    for (int i = 0; i <= tam; i++)
        troca(v, i, menor_poss(v, tam, i));
}
int busca_sequencial_ord(int *v, int tam, int x)
{
    int temp = -1;
    for (int i = 0; i <= tam; i++)
    {
        if (v[i] == x)
            return i;
        if (v[i] > x)
            break;
    }
    return temp;
}
int busca_sequencial(int *v, int tam, int x)
{
    int temp = -1;
    for (int i = 0; i <= tam; i++)
    {
        if (v[i] == x)
            return i;
    }
    return temp;
}
int busca_binaria(int *v, int tam, int x)
{
    int temp = -1;
    int e = 0, d = tam, m;
    while (e <= d)
    {
        m = abs((e + d) / 2);
        if (x == v[m])
            return m;
        else if (x > v[m])
            e = m + 1;
        else
            d = m - 1;
    }
    return temp;
}

int particionamento(int *v, int esq, int dir)
{
    int p = esq, pos, atual;
    pos = atual = p + 1;

    while (atual <= dir)
    {
        if (v[atual] <= v[p])
        {
            trocar(&v[atual], &v[pos]);
            pos++;
        }
        atual++;
    }
    pos--;

    trocar(&v[p], &v[pos]);
    return pos;
}

void quicksort(int *v, int n)
{
    stack<int> pilha;
    int esq = 0, dir = n - 1, c[n] = {0};
    pilha.push(esq);
    pilha.push(dir);
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
    }
}

void trocar(int *v1, int *v2)
{
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}
void heapify(int *v, int n, int idx)
{
    bool t = true;
    int m = idx;
    while (t)
    {
        t = false;
        int dir = m * 2 + 2;
        int esq = m * 2 + 1;
        if (m < esq && v[m] < v[esq])
            m = esq;
        if (m < dir && v[m] < v[dir])
            m = dir;
        if (m != idx)
        {
            troca(v, m, idx);
            t = true;
            idx = m;
        }
    }
}
void maxheap(int *v, int n)
{
    for (int idx = n / 2 - 1; idx >= 0; idx--)
        heapify(v, n, idx);
}
void heapsort(int *v, int n)
{
    maxheap(v, n);
    while (n > 0)
    {
        troca(v, 0, n - 1);
        n--;
        heapify(v, n, 0);
    }
}
int ordem_cres(int *v, int n, int c)
{
    int aux = 0;
    if (c + 1 < n)
    {
        if (v[c] <= v[c + 1])
        {
            aux = ordem_cres(v, n, c + 1);
        }
        else
        {
            aux = 0;
        }
    }
    else
    {
        return 1;
    }
    if (aux == 0)
        return 1;
}
bool ordem_des(int *v, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] <= v[n + 1])
            return false;
    }
}
void insertion(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int aux = i;
        for (int j = 0; j < n; j++)
        {

            if (v[aux] > v[j])
            {
                aux = j;
            }
        }
        troca(v, i, aux);
    }
}
