#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int tam_vet;
    cin >> tam_vet;

    vector<int> v(tam_vet);
    
    for (int i = 0; i < tam_vet; i++)
    {
        cin >> v[i];
    }

    int picos = 0;
    for (int i = 1; i < tam_vet - 1; i++)
    {
        if (v[i - 1] < v[i] && v[i] > v[i + 1])
        {
            picos ++;
        }
    }
    cout << picos;
}