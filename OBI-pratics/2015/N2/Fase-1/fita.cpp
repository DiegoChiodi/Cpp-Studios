#include <iostream>
using namespace std;

int main(void){
    int quad;
    cin >> quad;

    bool fita[quad];

    for (int i = 0; i < quad; i++)
    {
        int temp_inp;
        cin >> temp_inp;
        fita[i] = (temp_inp == 0);
    }

    for (int i = 0; i < quad; i++)
    {
        int distRight = 1e9;
        int distLeft = 1e9;
        
        for (int j = i; j < quad; j++)
        {
            if (fita[j])
            {
                distRight = j - i;
                break;
            }
        }

        for (int j = i; j > -1; j--)
        {
            if (fita[j])
            {
                distLeft = i - j;
                break;
            }
        }

        int result = min(distLeft, distRight);
        result = min(result, 9);
        cout << result << " ";
    }
}
