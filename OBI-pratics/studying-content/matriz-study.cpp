#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    bool mar[101][101] = {false};
    
    for (int i = 0; i < n; i++)
    {
        int xi, xf, yi, yf;
        cin >> xi >> xf >> yi >> yf;

        for (int x = xi; x < xf; x++)
        {
            for (int y = yi; y < yf; y++)
            {
                mar[x][y] = true;
            }
        }
    }

    int preenchidos = 0;
    for (int i = 1; i < 101; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            if (mar[i][j])
            {
                preenchidos ++;
            }
        }
    }
    cout << preenchidos;
    return 0;
}