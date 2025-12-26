#include <iostream>

using namespace std;

int main (void)
{
    int n = 0;
    cin >> n;
    
    int list[100001] = {0};

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        list[x] ++;
    }

    for (int i = 0; i < 100001; i++)
    {
        if (list[i] > n / 2)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}