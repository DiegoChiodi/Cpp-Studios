#include <iostream>

using namespace std;

int main(void)
{
    int n = 0;

    cin >> n;

    int numsD[31] = {0};
    int numsE[31] = {0};

    for (int i = 0; i < n; i++)
    {
        int num;
        char lado;

        cin >> num >> lado;

        if (lado == 'D')
        {
            numsD[num - 30]++;
        } else {
            numsE[num - 30]++;
        }
    }

    int pares = 0;

    for (int i = 0; i < 31; i++)
    {
        pares += (numsE[i] > numsD[i]) ? numsD[i] : numsE[i];
    }


    cout << pares;

    return 0;
}