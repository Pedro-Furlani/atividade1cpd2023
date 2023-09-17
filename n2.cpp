#include <bits/stdc++.h>
#include "cores.cpp"
using namespace std;
const int TAM = 20;
int main()
{
    srand(time(NULL));
    int hist[TAM + 1] = {0};
    int maximo = -1;
    for (int i = 1; i <= 400; i++)
    {
        int v = 1 + rand() % TAM;
        hist[v]++;
    }
    cout << endl;
    cout << endl;
    int h[400][400] = {0};
    for (int i = 1; i <= TAM; i++)
    {
        for (int j = 1; j <= hist[i]; j++)
        {
            h[j][i] = 1;
        }
    }
    for (int i = TAM; i >= 1; i--)
    {
        for (int j = 1; j <= TAM; j++)
        {
            if (h[i][j] == 1)
            {
                if (j % 10 == 1 && i == 1)
                    cout << RED << '\xDB' << RESET;
                else
                    cout << '\xDB';
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}