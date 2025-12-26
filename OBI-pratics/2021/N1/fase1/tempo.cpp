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
    
    // Ordena uma única vez
    bubbleSort(friend_i, resp, qtd);
    
    // Agrupa amigos iguais

    int novoQtd = 0;

    for (int i = 0; i < qtd; )
    {
        int id = friend_i[i];
        int soma = resp[i];
        bool invalido = (resp[i] == -1);

        int j = i + 1;
        while (j < qtd && friend_i[j] == id)
        {
            if (resp[j] == -1)
                invalido = true;
            else
                soma += resp[j];
            j++;
        }

        friend_i[novoQtd] = id;
        resp[novoQtd] = invalido ? -1 : soma;
        novoQtd++;

        i = j;
    }

    qtd = novoQtd;


    // Imprime
    for (int i = 0; i < qtd; i++)
    {
        cout << friend_i[i] << ' ' << resp[i] << endl;
    }
    
    return 0;
}
