#include <iostream>

using namespace std;

int main (void)
{
    int n;

    cin >> n;
    int count[100000];

    int topo = 0;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == 0 && topo > 0)
        {   
            topo --;
        } else {
            count[topo] = num;
            topo++;
        }
    }

    int somTotal = 0;
    for (int i = 0; i < topo; i++)
    {
        somTotal += count[i];
    }

    cout << somTotal;
}