#include <iostream>

using namespace std;

int main(void)
{
    int botoes_num, pasword_target;
    cin >> botoes_num >> pasword_target;

    int botoes[botoes_num];

    for (int i = 0; i < botoes_num; i++)
    {
        cin >> botoes[i];
    }

    bool open = false;

    for (int mask = 0; mask < (1 << botoes_num); mask++)
    {
        int pasword_som = 0;
        for (int i = 0; i < botoes_num; i++)
        {
            if (mask & (1 << i))
            {
                pasword_som += botoes[i];
            }
        }
        
        if (pasword_som == pasword_target)
        {
            open = true;
            break;
        }

    }
    if (open)
    {
        cout << "SIM";
    } else {
        cout << "NAO";
    }
}