#include <iostream>

using namespace std;

int reg;

int tempResp(int ind, char stats[], int valores[], const int &tam)
{
    bool prev_is_t = false;
    int tempTot = 0;

    for (int i = ind + 1; i < tam; i++)
    {
        switch(stats[i])
        {
            case 'R':
                if (!prev_is_t)
                {
                    tempTot += 1;
                }
                
                prev_is_t = false;
                break;
            case 'E':
                if (!prev_is_t)
                {
                    tempTot += 1;
                }

                if (valores[i] == valores[ind])
                {
                    return tempTot;
                }
                prev_is_t = false;
                break;
            case 'T':
                prev_is_t = true;
                tempTot += valores[i];
                break;
        }
    }
    return -1;
}


int main (void)
{
    cin >> reg;

    char stats[reg];
    int valores[reg];

    for (int i = 0; i < reg; i++)
    {
        cin >> stats[i] >> valores[i];
    }

    int friend_i[20] = {};
    int resp[20] = {};


    for (int i = 0; i < reg; i++)
    {
        if (stats[i] == 'R')
        {
            friend_i[i] = valores[i];
            int tmp_resp = tempResp(i, stats, valores, reg);
            if (tmp_resp == -1)
            {
                resp[i] = -1;
            } else {
                resp[i] += tmp_resp;
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for(int j = i + 1; j < 20; j++)
        {
            if (friend_i[i] == friend_i[j])
            {
                if (resp[j] == -1)
                {
                    resp[i] = -1;
                    friend_i[j] = 0;
                } else 
                {
                    resp[i] += resp[j];
                    friend_i[j] = 0;
                }
            }
        }
        if (friend_i[i] != 0)
        {
            cout << friend_i[i] << ' ' << resp[i] << endl;
        }
    }
    
    return 0;
};