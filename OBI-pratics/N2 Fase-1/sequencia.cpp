#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int tam_vet;
    cin >> tam_vet;

    vector<int> v (tam_vet);

    for (int i = 0; i < tam_vet; i++)
    {
        cin >> v[i];
    }

    int maior_seq = 0;
    int seq = 0;
    int last_element = v[0] - 1;
    for (int i = 0; i < tam_vet; i++)
    {   
        if ((v[i] <= last_element))
        {
            maior_seq = max(maior_seq, seq);
            seq = 0;
        }
        seq ++;

        last_element = v[i];
    }
    cout << max(maior_seq, seq);
}