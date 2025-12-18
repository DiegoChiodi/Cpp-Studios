#include <iostream>

using namespace std;

int get_potencia(int base, short exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }

    return result;
}


int main (void)
{
    int tamanho;
    cin >> tamanho;

    string valores[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        cin >> valores[i];
    }

    int result = 0;

    for (int i = 0; i < tamanho; i++)
    {
        int base = 0;
        int potencia = valores[i].at(valores[i].size() - 1) - '0';

        int j_cont = valores[i].size() - 1;

        for (int j = 0; j < j_cont; j++)
        {
            base += (valores[i].at(j) - '0') * get_potencia(10, j_cont - j - 1);
        }
        result += get_potencia(base, potencia);
    }

    cout << result;
}