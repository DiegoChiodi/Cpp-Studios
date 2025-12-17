#include <iostream>

using namespace std;
int main (void)
{
    int wins = 0;

    for (int i = 0; i < 6; i++)
    {
        char col;
        cin >> col;

        if (col == 'V')
        {
            wins += 1;
        }
    }

    if (wins == 0)
    {
        cout << -1;
    } else if (wins < 3)
    {
        cout << 3;
    } else if (wins < 5)
    {
        cout << 2;
    } else
    {
        cout << 1;
    }

    return 0;
}