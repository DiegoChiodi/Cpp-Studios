#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
    int ped_q, sap_t;
    cin >> ped_q >> sap_t;
    ped_q ++;
    vector<bool> is_sap(ped_q, false);
    
    for (int i = 0; i < sap_t; i++)
    {
        int ped_inic, jump_dist;
        cin >> ped_inic >> jump_dist;

        int inicio = ped_inic % jump_dist;
        if (inicio == 0)
            inicio = jump_dist;

        for (int j = inicio; j < ped_q; j += jump_dist)
        {
            is_sap[j] = true;
        }
    }

    for (int i = 1; i < ped_q; i++)
    {
        cout << is_sap[i] << endl;
    }
}