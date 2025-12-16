#include <iostream>

using namespace std;


//  Ordena dois vetores em paralelo pelo friend_i

void bubbleSort(int friend_i[], int resp[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (friend_i[j] > friend_i[j + 1])
            {
                swap(friend_i[j], friend_i[j + 1]);
                swap(resp[j], resp[j + 1]);
            }
        }
    }
}


//  Calcula a resposta temporária a partir do índice ind

int tempResp(int ind, char stats[], int valores[], int n)
{
    bool acumulandoTempo = false;
    int total = 0;

    for (int i = ind + 1; i < n; i++)
    {
        if (stats[i] == 'R')
        {
            if (!acumulandoTempo)
                total++;
            acumulandoTempo = false;
        }
        else if (stats[i] == 'E')
        {
            if (!acumulandoTempo)
                total++;

            if (valores[i] == valores[ind])
                return total;

            acumulandoTempo = false;
        }
        else if (stats[i] == 'T')
        {
            acumulandoTempo = true;
            total += valores[i];
        }
    }

    return -1;
}

int main()
{
    int reg;
    cin >> reg;

    char stats[reg];
    int valores[reg];

    for (int i = 0; i < reg; i++)
        cin >> stats[i] >> valores[i];

    int friend_i[reg];
    int resp[reg];
    int qtd = 0;

    // Coleta respostas válidas
    for (int i = 0; i < reg; i++)
    {
        if (stats[i] == 'R')
        {
            friend_i[qtd] = valores[i];
            resp[qtd] = tempResp(i, stats, valores, reg);
            qtd++;
        }
    }

    // Agrupa amigos iguais
    for (int i = 0; i < qtd; i++)
    {
        for (int j = i + 1; j < qtd; j++)
        {
            if (friend_i[i] == friend_i[j])
            {
                if (resp[i] == -1 || resp[j] == -1)
                {
                    resp[i] = -1;
                }
                else
                {
                    resp[i] += resp[j];
                }

                // remove j
                friend_i[j] = friend_i[qtd - 1];
                resp[j]     = resp[qtd - 1];
                qtd--;
                j--;
            }
        }
    }

    // Ordena uma única vez
    bubbleSort(friend_i, resp, qtd);

    // Imprime
    for (int i = 0; i < qtd; i++)
    {
        cout << friend_i[i] << " " << resp[i] << endl;
    }
    return 0;
}
